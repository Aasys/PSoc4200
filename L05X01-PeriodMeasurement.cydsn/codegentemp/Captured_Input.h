/*******************************************************************************
* File Name: Captured_Input.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Captured_Input_H) /* Pins Captured_Input_H */
#define CY_PINS_Captured_Input_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Captured_Input_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Captured_Input_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Captured_Input_Read(void);
void    Captured_Input_Write(uint8 value);
uint8   Captured_Input_ReadDataReg(void);
#if defined(Captured_Input__PC) || (CY_PSOC4_4200L) 
    void    Captured_Input_SetDriveMode(uint8 mode);
#endif
void    Captured_Input_SetInterruptMode(uint16 position, uint16 mode);
uint8   Captured_Input_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Captured_Input_Sleep(void); 
void Captured_Input_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Captured_Input__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Captured_Input_DRIVE_MODE_BITS        (3)
    #define Captured_Input_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Captured_Input_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Captured_Input_SetDriveMode() function.
         *  @{
         */
        #define Captured_Input_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Captured_Input_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Captured_Input_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Captured_Input_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Captured_Input_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Captured_Input_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Captured_Input_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Captured_Input_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Captured_Input_MASK               Captured_Input__MASK
#define Captured_Input_SHIFT              Captured_Input__SHIFT
#define Captured_Input_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Captured_Input_SetInterruptMode() function.
     *  @{
     */
        #define Captured_Input_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Captured_Input_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Captured_Input_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Captured_Input_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Captured_Input__SIO)
    #define Captured_Input_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Captured_Input__PC) && (CY_PSOC4_4200L)
    #define Captured_Input_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Captured_Input_USBIO_DISABLE              ((uint32)(~Captured_Input_USBIO_ENABLE))
    #define Captured_Input_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Captured_Input_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Captured_Input_USBIO_ENTER_SLEEP          ((uint32)((1u << Captured_Input_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Captured_Input_USBIO_SUSPEND_DEL_SHIFT)))
    #define Captured_Input_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Captured_Input_USBIO_SUSPEND_SHIFT)))
    #define Captured_Input_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Captured_Input_USBIO_SUSPEND_DEL_SHIFT)))
    #define Captured_Input_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Captured_Input__PC)
    /* Port Configuration */
    #define Captured_Input_PC                 (* (reg32 *) Captured_Input__PC)
#endif
/* Pin State */
#define Captured_Input_PS                     (* (reg32 *) Captured_Input__PS)
/* Data Register */
#define Captured_Input_DR                     (* (reg32 *) Captured_Input__DR)
/* Input Buffer Disable Override */
#define Captured_Input_INP_DIS                (* (reg32 *) Captured_Input__PC2)

/* Interrupt configuration Registers */
#define Captured_Input_INTCFG                 (* (reg32 *) Captured_Input__INTCFG)
#define Captured_Input_INTSTAT                (* (reg32 *) Captured_Input__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Captured_Input_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Captured_Input__SIO)
    #define Captured_Input_SIO_REG            (* (reg32 *) Captured_Input__SIO)
#endif /* (Captured_Input__SIO_CFG) */

/* USBIO registers */
#if !defined(Captured_Input__PC) && (CY_PSOC4_4200L)
    #define Captured_Input_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Captured_Input_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Captured_Input_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Captured_Input_DRIVE_MODE_SHIFT       (0x00u)
#define Captured_Input_DRIVE_MODE_MASK        (0x07u << Captured_Input_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Captured_Input_H */


/* [] END OF FILE */
