/*******************************************************************************
* File Name: Captured_Input.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Captured_Input_ALIASES_H) /* Pins Captured_Input_ALIASES_H */
#define CY_PINS_Captured_Input_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Captured_Input_0			(Captured_Input__0__PC)
#define Captured_Input_0_PS		(Captured_Input__0__PS)
#define Captured_Input_0_PC		(Captured_Input__0__PC)
#define Captured_Input_0_DR		(Captured_Input__0__DR)
#define Captured_Input_0_SHIFT	(Captured_Input__0__SHIFT)
#define Captured_Input_0_INTR	((uint16)((uint16)0x0003u << (Captured_Input__0__SHIFT*2u)))

#define Captured_Input_INTR_ALL	 ((uint16)(Captured_Input_0_INTR))


#endif /* End Pins Captured_Input_ALIASES_H */


/* [] END OF FILE */
