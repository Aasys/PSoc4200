/*******************************************************************************
* File Name: Sq_Wave_Out.c  
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
#include "Sq_Wave_Out.h"

static Sq_Wave_Out_BACKUP_STRUCT  Sq_Wave_Out_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Sq_Wave_Out_Sleep
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
*  \snippet Sq_Wave_Out_SUT.c usage_Sq_Wave_Out_Sleep_Wakeup
*******************************************************************************/
void Sq_Wave_Out_Sleep(void)
{
    #if defined(Sq_Wave_Out__PC)
        Sq_Wave_Out_backup.pcState = Sq_Wave_Out_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Sq_Wave_Out_backup.usbState = Sq_Wave_Out_CR1_REG;
            Sq_Wave_Out_USB_POWER_REG |= Sq_Wave_Out_USBIO_ENTER_SLEEP;
            Sq_Wave_Out_CR1_REG &= Sq_Wave_Out_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Sq_Wave_Out__SIO)
        Sq_Wave_Out_backup.sioState = Sq_Wave_Out_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Sq_Wave_Out_SIO_REG &= (uint32)(~Sq_Wave_Out_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Sq_Wave_Out_Wakeup
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
*  Refer to Sq_Wave_Out_Sleep() for an example usage.
*******************************************************************************/
void Sq_Wave_Out_Wakeup(void)
{
    #if defined(Sq_Wave_Out__PC)
        Sq_Wave_Out_PC = Sq_Wave_Out_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Sq_Wave_Out_USB_POWER_REG &= Sq_Wave_Out_USBIO_EXIT_SLEEP_PH1;
            Sq_Wave_Out_CR1_REG = Sq_Wave_Out_backup.usbState;
            Sq_Wave_Out_USB_POWER_REG &= Sq_Wave_Out_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Sq_Wave_Out__SIO)
        Sq_Wave_Out_SIO_REG = Sq_Wave_Out_backup.sioState;
    #endif
}


/* [] END OF FILE */
