/*******************************************************************************
* File Name: Capture_Pin.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Capture_Pin.h"

static Capture_Pin_BACKUP_STRUCT  Capture_Pin_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Capture_Pin_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Capture_Pin_SUT.c usage_Capture_Pin_Sleep_Wakeup
*******************************************************************************/
void Capture_Pin_Sleep(void)
{
    #if defined(Capture_Pin__PC)
        Capture_Pin_backup.pcState = Capture_Pin_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Capture_Pin_backup.usbState = Capture_Pin_CR1_REG;
            Capture_Pin_USB_POWER_REG |= Capture_Pin_USBIO_ENTER_SLEEP;
            Capture_Pin_CR1_REG &= Capture_Pin_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Capture_Pin__SIO)
        Capture_Pin_backup.sioState = Capture_Pin_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Capture_Pin_SIO_REG &= (uint32)(~Capture_Pin_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Capture_Pin_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Capture_Pin_Sleep() for an example usage.
*******************************************************************************/
void Capture_Pin_Wakeup(void)
{
    #if defined(Capture_Pin__PC)
        Capture_Pin_PC = Capture_Pin_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Capture_Pin_USB_POWER_REG &= Capture_Pin_USBIO_EXIT_SLEEP_PH1;
            Capture_Pin_CR1_REG = Capture_Pin_backup.usbState;
            Capture_Pin_USB_POWER_REG &= Capture_Pin_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Capture_Pin__SIO)
        Capture_Pin_SIO_REG = Capture_Pin_backup.sioState;
    #endif
}


/* [] END OF FILE */
