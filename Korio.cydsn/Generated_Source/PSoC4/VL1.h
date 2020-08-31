/*******************************************************************************
* File Name: VL1.h  
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

#if !defined(CY_PINS_VL1_H) /* Pins VL1_H */
#define CY_PINS_VL1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "VL1_aliases.h"


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
} VL1_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   VL1_Read(void);
void    VL1_Write(uint8 value);
uint8   VL1_ReadDataReg(void);
#if defined(VL1__PC) || (CY_PSOC4_4200L) 
    void    VL1_SetDriveMode(uint8 mode);
#endif
void    VL1_SetInterruptMode(uint16 position, uint16 mode);
uint8   VL1_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void VL1_Sleep(void); 
void VL1_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(VL1__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define VL1_DRIVE_MODE_BITS        (3)
    #define VL1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - VL1_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the VL1_SetDriveMode() function.
         *  @{
         */
        #define VL1_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define VL1_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define VL1_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define VL1_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define VL1_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define VL1_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define VL1_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define VL1_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define VL1_MASK               VL1__MASK
#define VL1_SHIFT              VL1__SHIFT
#define VL1_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in VL1_SetInterruptMode() function.
     *  @{
     */
        #define VL1_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define VL1_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define VL1_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define VL1_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(VL1__SIO)
    #define VL1_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(VL1__PC) && (CY_PSOC4_4200L)
    #define VL1_USBIO_ENABLE               ((uint32)0x80000000u)
    #define VL1_USBIO_DISABLE              ((uint32)(~VL1_USBIO_ENABLE))
    #define VL1_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define VL1_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define VL1_USBIO_ENTER_SLEEP          ((uint32)((1u << VL1_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << VL1_USBIO_SUSPEND_DEL_SHIFT)))
    #define VL1_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << VL1_USBIO_SUSPEND_SHIFT)))
    #define VL1_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << VL1_USBIO_SUSPEND_DEL_SHIFT)))
    #define VL1_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(VL1__PC)
    /* Port Configuration */
    #define VL1_PC                 (* (reg32 *) VL1__PC)
#endif
/* Pin State */
#define VL1_PS                     (* (reg32 *) VL1__PS)
/* Data Register */
#define VL1_DR                     (* (reg32 *) VL1__DR)
/* Input Buffer Disable Override */
#define VL1_INP_DIS                (* (reg32 *) VL1__PC2)

/* Interrupt configuration Registers */
#define VL1_INTCFG                 (* (reg32 *) VL1__INTCFG)
#define VL1_INTSTAT                (* (reg32 *) VL1__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define VL1_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(VL1__SIO)
    #define VL1_SIO_REG            (* (reg32 *) VL1__SIO)
#endif /* (VL1__SIO_CFG) */

/* USBIO registers */
#if !defined(VL1__PC) && (CY_PSOC4_4200L)
    #define VL1_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define VL1_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define VL1_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define VL1_DRIVE_MODE_SHIFT       (0x00u)
#define VL1_DRIVE_MODE_MASK        (0x07u << VL1_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins VL1_H */


/* [] END OF FILE */
