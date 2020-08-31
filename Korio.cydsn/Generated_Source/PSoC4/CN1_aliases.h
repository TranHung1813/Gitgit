/*******************************************************************************
* File Name: CN1.h  
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

#if !defined(CY_PINS_CN1_ALIASES_H) /* Pins CN1_ALIASES_H */
#define CY_PINS_CN1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define CN1_0			(CN1__0__PC)
#define CN1_0_PS		(CN1__0__PS)
#define CN1_0_PC		(CN1__0__PC)
#define CN1_0_DR		(CN1__0__DR)
#define CN1_0_SHIFT	(CN1__0__SHIFT)
#define CN1_0_INTR	((uint16)((uint16)0x0003u << (CN1__0__SHIFT*2u)))

#define CN1_INTR_ALL	 ((uint16)(CN1_0_INTR))


#endif /* End Pins CN1_ALIASES_H */


/* [] END OF FILE */
