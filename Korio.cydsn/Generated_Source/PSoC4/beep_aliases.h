/*******************************************************************************
* File Name: beep.h  
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

#if !defined(CY_PINS_beep_ALIASES_H) /* Pins beep_ALIASES_H */
#define CY_PINS_beep_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define beep_0			(beep__0__PC)
#define beep_0_PS		(beep__0__PS)
#define beep_0_PC		(beep__0__PC)
#define beep_0_DR		(beep__0__DR)
#define beep_0_SHIFT	(beep__0__SHIFT)
#define beep_0_INTR	((uint16)((uint16)0x0003u << (beep__0__SHIFT*2u)))

#define beep_INTR_ALL	 ((uint16)(beep_0_INTR))


#endif /* End Pins beep_ALIASES_H */


/* [] END OF FILE */
