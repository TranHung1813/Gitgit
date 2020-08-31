/*******************************************************************************
* File Name: beep.h  
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

#if !defined(CY_PINS_beep_H) /* Pins beep_H */
#define CY_PINS_beep_H

#include "cytypes.h"
#include "cyfitter.h"
#include "beep_aliases.h"


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
} beep_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   beep_Read(void);
void    beep_Write(uint8 value);
uint8   beep_ReadDataReg(void);
#if defined(beep__PC) || (CY_PSOC4_4200L) 
    void    beep_SetDriveMode(uint8 mode);
#endif
void    beep_SetInterruptMode(uint16 position, uint16 mode);
uint8   beep_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void beep_Sleep(void); 
void beep_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(beep__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define beep_DRIVE_MODE_BITS        (3)
    #define beep_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - beep_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the beep_SetDriveMode() function.
         *  @{
         */
        #define beep_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define beep_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define beep_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define beep_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define beep_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define beep_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define beep_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define beep_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define beep_MASK               beep__MASK
#define beep_SHIFT              beep__SHIFT
#define beep_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in beep_SetInterruptMode() function.
     *  @{
     */
        #define beep_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define beep_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define beep_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define beep_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(beep__SIO)
    #define beep_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(beep__PC) && (CY_PSOC4_4200L)
    #define beep_USBIO_ENABLE               ((uint32)0x80000000u)
    #define beep_USBIO_DISABLE              ((uint32)(~beep_USBIO_ENABLE))
    #define beep_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define beep_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define beep_USBIO_ENTER_SLEEP          ((uint32)((1u << beep_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << beep_USBIO_SUSPEND_DEL_SHIFT)))
    #define beep_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << beep_USBIO_SUSPEND_SHIFT)))
    #define beep_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << beep_USBIO_SUSPEND_DEL_SHIFT)))
    #define beep_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(beep__PC)
    /* Port Configuration */
    #define beep_PC                 (* (reg32 *) beep__PC)
#endif
/* Pin State */
#define beep_PS                     (* (reg32 *) beep__PS)
/* Data Register */
#define beep_DR                     (* (reg32 *) beep__DR)
/* Input Buffer Disable Override */
#define beep_INP_DIS                (* (reg32 *) beep__PC2)

/* Interrupt configuration Registers */
#define beep_INTCFG                 (* (reg32 *) beep__INTCFG)
#define beep_INTSTAT                (* (reg32 *) beep__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define beep_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(beep__SIO)
    #define beep_SIO_REG            (* (reg32 *) beep__SIO)
#endif /* (beep__SIO_CFG) */

/* USBIO registers */
#if !defined(beep__PC) && (CY_PSOC4_4200L)
    #define beep_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define beep_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define beep_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define beep_DRIVE_MODE_SHIFT       (0x00u)
#define beep_DRIVE_MODE_MASK        (0x07u << beep_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins beep_H */


/* [] END OF FILE */
