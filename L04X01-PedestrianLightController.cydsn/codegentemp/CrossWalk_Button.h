/*******************************************************************************
* File Name: CrossWalk_Button.h  
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

#if !defined(CY_PINS_CrossWalk_Button_H) /* Pins CrossWalk_Button_H */
#define CY_PINS_CrossWalk_Button_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CrossWalk_Button_aliases.h"


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
} CrossWalk_Button_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   CrossWalk_Button_Read(void);
void    CrossWalk_Button_Write(uint8 value);
uint8   CrossWalk_Button_ReadDataReg(void);
#if defined(CrossWalk_Button__PC) || (CY_PSOC4_4200L) 
    void    CrossWalk_Button_SetDriveMode(uint8 mode);
#endif
void    CrossWalk_Button_SetInterruptMode(uint16 position, uint16 mode);
uint8   CrossWalk_Button_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void CrossWalk_Button_Sleep(void); 
void CrossWalk_Button_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(CrossWalk_Button__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define CrossWalk_Button_DRIVE_MODE_BITS        (3)
    #define CrossWalk_Button_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - CrossWalk_Button_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the CrossWalk_Button_SetDriveMode() function.
         *  @{
         */
        #define CrossWalk_Button_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define CrossWalk_Button_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define CrossWalk_Button_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define CrossWalk_Button_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define CrossWalk_Button_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define CrossWalk_Button_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define CrossWalk_Button_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define CrossWalk_Button_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define CrossWalk_Button_MASK               CrossWalk_Button__MASK
#define CrossWalk_Button_SHIFT              CrossWalk_Button__SHIFT
#define CrossWalk_Button_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CrossWalk_Button_SetInterruptMode() function.
     *  @{
     */
        #define CrossWalk_Button_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define CrossWalk_Button_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define CrossWalk_Button_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define CrossWalk_Button_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(CrossWalk_Button__SIO)
    #define CrossWalk_Button_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(CrossWalk_Button__PC) && (CY_PSOC4_4200L)
    #define CrossWalk_Button_USBIO_ENABLE               ((uint32)0x80000000u)
    #define CrossWalk_Button_USBIO_DISABLE              ((uint32)(~CrossWalk_Button_USBIO_ENABLE))
    #define CrossWalk_Button_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define CrossWalk_Button_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define CrossWalk_Button_USBIO_ENTER_SLEEP          ((uint32)((1u << CrossWalk_Button_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << CrossWalk_Button_USBIO_SUSPEND_DEL_SHIFT)))
    #define CrossWalk_Button_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << CrossWalk_Button_USBIO_SUSPEND_SHIFT)))
    #define CrossWalk_Button_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << CrossWalk_Button_USBIO_SUSPEND_DEL_SHIFT)))
    #define CrossWalk_Button_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(CrossWalk_Button__PC)
    /* Port Configuration */
    #define CrossWalk_Button_PC                 (* (reg32 *) CrossWalk_Button__PC)
#endif
/* Pin State */
#define CrossWalk_Button_PS                     (* (reg32 *) CrossWalk_Button__PS)
/* Data Register */
#define CrossWalk_Button_DR                     (* (reg32 *) CrossWalk_Button__DR)
/* Input Buffer Disable Override */
#define CrossWalk_Button_INP_DIS                (* (reg32 *) CrossWalk_Button__PC2)

/* Interrupt configuration Registers */
#define CrossWalk_Button_INTCFG                 (* (reg32 *) CrossWalk_Button__INTCFG)
#define CrossWalk_Button_INTSTAT                (* (reg32 *) CrossWalk_Button__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define CrossWalk_Button_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(CrossWalk_Button__SIO)
    #define CrossWalk_Button_SIO_REG            (* (reg32 *) CrossWalk_Button__SIO)
#endif /* (CrossWalk_Button__SIO_CFG) */

/* USBIO registers */
#if !defined(CrossWalk_Button__PC) && (CY_PSOC4_4200L)
    #define CrossWalk_Button_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define CrossWalk_Button_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define CrossWalk_Button_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define CrossWalk_Button_DRIVE_MODE_SHIFT       (0x00u)
#define CrossWalk_Button_DRIVE_MODE_MASK        (0x07u << CrossWalk_Button_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins CrossWalk_Button_H */


/* [] END OF FILE */
