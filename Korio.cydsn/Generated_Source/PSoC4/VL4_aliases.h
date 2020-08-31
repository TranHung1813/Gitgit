/*******************************************************************************
* File Name: VL4.h  
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

#if !defined(CY_PINS_VL4_ALIASES_H) /* Pins VL4_ALIASES_H */
#define CY_PINS_VL4_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define VL4_0			(VL4__0__PC)
#define VL4_0_PS		(VL4__0__PS)
#define VL4_0_PC		(VL4__0__PC)
#define VL4_0_DR		(VL4__0__DR)
#define VL4_0_SHIFT	(VL4__0__SHIFT)
#define VL4_0_INTR	((uint16)((uint16)0x0003u << (VL4__0__SHIFT*2u)))

#define VL4_INTR_ALL	 ((uint16)(VL4_0_INTR))


#endif /* End Pins VL4_ALIASES_H */


/* [] END OF FILE */
