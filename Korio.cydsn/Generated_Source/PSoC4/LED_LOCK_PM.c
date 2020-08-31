/*******************************************************************************
* File Name: LED_LOCK.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "LED_LOCK.h"

static LED_LOCK_BACKUP_STRUCT  LED_LOCK_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: LED_LOCK_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet LED_LOCK_SUT.c usage_LED_LOCK_Sleep_Wakeup
*******************************************************************************/
void LED_LOCK_Sleep(void)
{
    #if defined(LED_LOCK__PC)
        LED_LOCK_backup.pcState = LED_LOCK_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            LED_LOCK_backup.usbState = LED_LOCK_CR1_REG;
            LED_LOCK_USB_POWER_REG |= LED_LOCK_USBIO_ENTER_SLEEP;
            LED_LOCK_CR1_REG &= LED_LOCK_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(LED_LOCK__SIO)
        LED_LOCK_backup.sioState = LED_LOCK_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        LED_LOCK_SIO_REG &= (uint32)(~LED_LOCK_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: LED_LOCK_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to LED_LOCK_Sleep() for an example usage.
*******************************************************************************/
void LED_LOCK_Wakeup(void)
{
    #if defined(LED_LOCK__PC)
        LED_LOCK_PC = LED_LOCK_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            LED_LOCK_USB_POWER_REG &= LED_LOCK_USBIO_EXIT_SLEEP_PH1;
            LED_LOCK_CR1_REG = LED_LOCK_backup.usbState;
            LED_LOCK_USB_POWER_REG &= LED_LOCK_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(LED_LOCK__SIO)
        LED_LOCK_SIO_REG = LED_LOCK_backup.sioState;
    #endif
}


/* [] END OF FILE */
