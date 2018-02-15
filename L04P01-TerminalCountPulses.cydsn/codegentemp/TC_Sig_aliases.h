/*******************************************************************************
* File Name: TC_Sig.h  
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

#if !defined(CY_PINS_TC_Sig_ALIASES_H) /* Pins TC_Sig_ALIASES_H */
#define CY_PINS_TC_Sig_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define TC_Sig_0			(TC_Sig__0__PC)
#define TC_Sig_0_PS		(TC_Sig__0__PS)
#define TC_Sig_0_PC		(TC_Sig__0__PC)
#define TC_Sig_0_DR		(TC_Sig__0__DR)
#define TC_Sig_0_SHIFT	(TC_Sig__0__SHIFT)
#define TC_Sig_0_INTR	((uint16)((uint16)0x0003u << (TC_Sig__0__SHIFT*2u)))

#define TC_Sig_INTR_ALL	 ((uint16)(TC_Sig_0_INTR))


#endif /* End Pins TC_Sig_ALIASES_H */


/* [] END OF FILE */
