/*******************************************************************************
* File Name: Capture_Pin.h  
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

#if !defined(CY_PINS_Capture_Pin_ALIASES_H) /* Pins Capture_Pin_ALIASES_H */
#define CY_PINS_Capture_Pin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Capture_Pin_0			(Capture_Pin__0__PC)
#define Capture_Pin_0_PS		(Capture_Pin__0__PS)
#define Capture_Pin_0_PC		(Capture_Pin__0__PC)
#define Capture_Pin_0_DR		(Capture_Pin__0__DR)
#define Capture_Pin_0_SHIFT	(Capture_Pin__0__SHIFT)
#define Capture_Pin_0_INTR	((uint16)((uint16)0x0003u << (Capture_Pin__0__SHIFT*2u)))

#define Capture_Pin_INTR_ALL	 ((uint16)(Capture_Pin_0_INTR))


#endif /* End Pins Capture_Pin_ALIASES_H */


/* [] END OF FILE */
