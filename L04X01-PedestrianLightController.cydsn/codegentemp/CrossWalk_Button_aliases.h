/*******************************************************************************
* File Name: CrossWalk_Button.h  
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

#if !defined(CY_PINS_CrossWalk_Button_ALIASES_H) /* Pins CrossWalk_Button_ALIASES_H */
#define CY_PINS_CrossWalk_Button_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define CrossWalk_Button_0			(CrossWalk_Button__0__PC)
#define CrossWalk_Button_0_PS		(CrossWalk_Button__0__PS)
#define CrossWalk_Button_0_PC		(CrossWalk_Button__0__PC)
#define CrossWalk_Button_0_DR		(CrossWalk_Button__0__DR)
#define CrossWalk_Button_0_SHIFT	(CrossWalk_Button__0__SHIFT)
#define CrossWalk_Button_0_INTR	((uint16)((uint16)0x0003u << (CrossWalk_Button__0__SHIFT*2u)))

#define CrossWalk_Button_INTR_ALL	 ((uint16)(CrossWalk_Button_0_INTR))


#endif /* End Pins CrossWalk_Button_ALIASES_H */


/* [] END OF FILE */
