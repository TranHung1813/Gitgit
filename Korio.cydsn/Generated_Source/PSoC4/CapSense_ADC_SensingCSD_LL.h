/***************************************************************************//**
* \file CapSense_ADC_SensingCSD_LL.h
* \version 5.0
*
* \brief
*   This file provides the headers of APIs specific to CSD sensing implementation.
*
* \see CapSense_ADC v5.0 Datasheet
*
*//*****************************************************************************
* Copyright (2016-2017), Cypress Semiconductor Corporation.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*******************************************************************************/

#if !defined(CY_SENSE_CapSense_ADC_SENSINGCSD_LL_H)
#define CY_SENSE_CapSense_ADC_SENSINGCSD_LL_H

#include <CyLib.h>
#include <cyfitter.h>
#include <cytypes.h>
#include <cypins.h>
#include "CapSense_ADC_Structure.h"
#include "CapSense_ADC_Configuration.h"
#include "CapSense_ADC_Sensing.h"

/****************************************************************************
* Register and mode mask definition
****************************************************************************/

#if (CapSense_ADC_ENABLE == CapSense_ADC_CSDV2)
    #define CapSense_ADC_CSD_CSDCMP_INIT                                (CapSense_ADC_CSDCMP_CSDCMP_DISABLED)

    /* SW_HS_P_SEL switches state for Coarse initialization of CMOD (sense path) */
    #if (CapSense_ADC_ENABLE == CapSense_ADC_CSD_EN)
        #if (CapSense_ADC_CSD__CMOD_PAD == CapSense_ADC_CMOD_CONNECTION)
            #define CapSense_ADC_CSD_HS_P_SEL_COARSE_CMOD               (CapSense_ADC_SW_HS_P_SEL_SW_HMPM_STATIC_CLOSE)
        #elif (CapSense_ADC_CSD__CSHIELD_PAD == CapSense_ADC_CMOD_CONNECTION)
            #define CapSense_ADC_CSD_HS_P_SEL_COARSE_CMOD               (CapSense_ADC_SW_HS_P_SEL_SW_HMPS_STATIC_CLOSE)
        #else
            #define CapSense_ADC_CSD_HS_P_SEL_COARSE_CMOD               (CapSense_ADC_SW_HS_P_SEL_SW_HMPT_STATIC_CLOSE)
        #endif /* (CapSense_ADC_CSD__CMOD_PAD == CapSense_ADC_CMOD_CONNECTION) */
    #else
        #define CapSense_ADC_CSD_HS_P_SEL_COARSE_CMOD                   (0x00000000uL)
    #endif /* ((CapSense_ADC_ENABLE == CapSense_ADC_CSD_CSX_EN) && (CapSense_ADC_ENABLE == CapSense_ADC_CSD_EN)) */

    #if ((CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_TANK_EN) && \
        (CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_EN))
        /* SW_HS_P_SEL switches state for Coarse initialization of CTANK (sense path) */
        #if (CapSense_ADC_CSD__CSH_TANK_PAD == CapSense_ADC_CTANK_CONNECTION)
            #define CapSense_ADC_CSD_HS_P_SEL_COARSE_TANK               (CapSense_ADC_SW_HS_P_SEL_SW_HMPT_STATIC_CLOSE)
        #elif (CapSense_ADC_CSD__CSHIELD_PAD == CapSense_ADC_CTANK_CONNECTION)
            #define CapSense_ADC_CSD_HS_P_SEL_COARSE_TANK               (CapSense_ADC_SW_HS_P_SEL_SW_HMPS_STATIC_CLOSE)
        #elif (CapSense_ADC_CSD__CMOD_PAD == CapSense_ADC_CTANK_CONNECTION)
            #define CapSense_ADC_CSD_HS_P_SEL_COARSE_TANK               (CapSense_ADC_SW_HS_P_SEL_SW_HMPM_STATIC_CLOSE)
        #else
            #define CapSense_ADC_CSD_HS_P_SEL_COARSE_TANK               (CapSense_ADC_SW_HS_P_SEL_SW_HMMA_STATIC_CLOSE)
        #endif /* (CapSense_ADC_CSD__CSH_TANK_PAD == CapSense_ADC_CTANK_CONNECTION) */
    #else
        #define CapSense_ADC_CSD_HS_P_SEL_COARSE_TANK                   (0x00000000uL)
    #endif /* ((CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_TANK_EN) && \
               (CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_EN)) */

    #define CapSense_ADC_CSD_SW_HS_P_SEL_COARSE                         (CapSense_ADC_HS_P_SEL_COARSE_CMOD | CapSense_ADC_CSD_HS_P_SEL_COARSE_TANK)

    /* C_mod config */
    #if ((CapSense_ADC_CSD__CMOD_PAD == CapSense_ADC_CMOD_CONNECTION) || (CapSense_ADC_CSD__CMOD_PAD == CapSense_ADC_CTANK_CONNECTION))
        #define CapSense_ADC_CSD_SW_FW_MOD_SEL_INIT             (CapSense_ADC_SW_FW_MOD_SEL_SW_F1PM_STATIC_CLOSE |\
                                                                     CapSense_ADC_SW_FW_MOD_SEL_SW_F1MA_STATIC_CLOSE |\
                                                                     CapSense_ADC_SW_FW_MOD_SEL_SW_F1CA_STATIC_CLOSE)
        #define CapSense_ADC_SW_DSI_SEL_CMODPAD                 (CapSense_ADC_SW_DSI_CMOD)
    #else
        #define CapSense_ADC_CSD_SW_FW_MOD_SEL_INIT             (0x00000000uL)
        #define CapSense_ADC_SW_DSI_SEL_CMODPAD                 (0x00000000uL)
    #endif /* (CapSense_ADC_CSD__CMOD_PAD == CapSense_ADC_CMOD_CONNECTION) */

    /* C_tank config */
    #if ((CapSense_ADC_CSD__CSH_TANK_PAD == CapSense_ADC_CMOD_CONNECTION) || (CapSense_ADC_CSD__CSH_TANK_PAD == CapSense_ADC_CTANK_CONNECTION))
        #define CapSense_ADC_CSD_SW_FW_TANK_SEL_INIT            (CapSense_ADC_SW_FW_TANK_SEL_SW_F2PT_STATIC_CLOSE |\
                                                                     CapSense_ADC_SW_FW_TANK_SEL_SW_F2MA_STATIC_CLOSE |\
                                                                     CapSense_ADC_SW_FW_TANK_SEL_SW_F2CA_STATIC_CLOSE)
        #define CapSense_ADC_SW_DSI_SEL_TANKPAD                 (CapSense_ADC_SW_DSI_CTANK)
    #else
        #define CapSense_ADC_CSD_SW_FW_TANK_SEL_INIT            (0x00000000uL)
        #define CapSense_ADC_SW_DSI_SEL_TANKPAD                 (0x00000000uL)
    #endif /* (CapSense_ADC_CSD__CSH_TANK_PAD == CapSense_ADC_CTANK_CONNECTION) */

    #define CapSense_ADC_CSD_SW_SHIELD_SEL_INIT                 (CapSense_ADC_SW_SHIELD_SEL_SW_HCAV_HSCMP)

    /* Defining default HW configuration according to settings in customizer. */
    #define CapSense_ADC_DEFAULT_CSD_CONFIG                 (CapSense_ADC_CONFIG_FILTER_DELAY_12MHZ |\
                                                                 CapSense_ADC_CONFIG_SAMPLE_SYNC_MASK)
    #if (CapSense_ADC_ENABLE == CapSense_ADC_CSD_AUTO_ZERO_EN)
        /* Enable CSDCMP */
        #define CapSense_ADC_CSD_CSDCMP_SCAN                (CapSense_ADC_CSDCMP_CSDCMP_EN_MASK |\
                                                                 CapSense_ADC_CSDCMP_AZ_EN_MASK)
    #else
        /* Enable CSDCMP */
        #define CapSense_ADC_CSD_CSDCMP_SCAN                (CapSense_ADC_CSDCMP_CSDCMP_EN_MASK)
    #endif /* (CapSense_ADC_ENABLE == CapSense_ADC_CSD_AUTO_ZERO_EN) */

    #if ((CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_TANK_EN) && \
        (CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_EN))
        /* SW_HS_P_SEL switches state for Coarse initialization of CTANK (sense path) */
        #if (CapSense_ADC_CSD__CSH_TANK_PAD == CapSense_ADC_CTANK_CONNECTION)
            #define CapSense_ADC_CSD_HS_P_SEL_SCAN_TANK                 (CapSense_ADC_SW_HS_P_SEL_SW_HMPT_STATIC_CLOSE)
        #elif (CapSense_ADC_CSD__CSHIELD_PAD == CapSense_ADC_CTANK_CONNECTION)
            #define CapSense_ADC_CSD_HS_P_SEL_SCAN_TANK                 (CapSense_ADC_SW_HS_P_SEL_SW_HMPS_STATIC_CLOSE)
        #elif (CapSense_ADC_CSD__CMOD_PAD == CapSense_ADC_CTANK_CONNECTION)
            #define CapSense_ADC_CSD_HS_P_SEL_SCAN_TANK                 (CapSense_ADC_SW_HS_P_SEL_SW_HMPM_STATIC_CLOSE)
        #else
            #define CapSense_ADC_CSD_HS_P_SEL_SCAN_TANK                 (CapSense_ADC_SW_HS_P_SEL_SW_HMMB_STATIC_CLOSE)
        #endif /* (CapSense_ADC_CSD__CSH_TANK_PAD == CapSense_ADC_CTANK_CONNECTION) */
        #define CapSense_ADC_CSD_SW_HS_P_SEL_SCAN                       (CapSense_ADC_HS_P_SEL_SCAN_TANK)
    #elif(CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_EN)
        #define CapSense_ADC_CSD_SW_HS_P_SEL_SCAN                       (CapSense_ADC_SW_HS_P_SEL_SW_HMMB_STATIC_CLOSE)
    #else
        #define CapSense_ADC_CSD_SW_HS_P_SEL_SCAN                       (CapSense_ADC_STATIC_OPEN)
    #endif /* ((CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_TANK_EN) && \
               (CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_EN)) */

    /* SW_FW_MOD_SEL switches state for Coarse initialization of CMOD (sense path) */
    #define CapSense_ADC_CSD_SW_FW_MOD_SEL_SCAN                 (0x00000000uL)

    #if((CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_EN) && \
        (CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_TANK_EN) && \
        (CapSense_ADC_CSD__CSH_TANK_PAD == CapSense_ADC_CTANK_CONNECTION))
        #define CapSense_ADC_CSD_SW_FW_TANK_SEL_SCAN            (CapSense_ADC_SW_FW_TANK_SEL_SW_F2PT_STATIC_CLOSE | \
                                                                 CapSense_ADC_SW_FW_TANK_SEL_SW_F2CB_STATIC_CLOSE)
    #else
        #define CapSense_ADC_CSD_SW_FW_TANK_SEL_SCAN            (0x00000000uL)
    #endif /* ((CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_EN) && \
               (CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_TANK_EN) && \
               (CapSense_ADC_CSD__CSH_TANK_PAD == CapSense_ADC_CTANK_CONNECTION)) */

    /* Shield switch default config */
    #if ((CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_EN) && \
         (CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_TANK_EN))
        #if (CapSense_ADC_IDAC_SINKING == CapSense_ADC_CSD_IDAC_CONFIG)
            #define CapSense_ADC_CSD_SW_SHIELD_SEL_SCAN          (CapSense_ADC_SW_SHIELD_SEL_SW_HCBG_HSCMP)
        #else
            #define CapSense_ADC_CSD_SW_SHIELD_SEL_SCAN          (CapSense_ADC_SW_SHIELD_SEL_SW_HCBV_HSCMP)
        #endif /* (CapSense_ADC_IDAC_SINKING == CapSense_ADC_CSD_IDAC_CONFIG) */
    #elif(CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_EN)
        #if (CapSense_ADC_IDAC_SINKING == CapSense_ADC_CSD_IDAC_CONFIG)
            #define CapSense_ADC_CSD_SW_SHIELD_SEL_SCAN          (CapSense_ADC_SW_SHIELD_SEL_SW_HCBV_PHI1 | \
                                                                     CapSense_ADC_SW_SHIELD_SEL_SW_HCBG_PHI2_HSCMP)
        #else
            #define CapSense_ADC_CSD_SW_SHIELD_SEL_SCAN          (CapSense_ADC_SW_SHIELD_SEL_SW_HCBG_PHI1 | \
                                                                     CapSense_ADC_SW_SHIELD_SEL_SW_HCBV_PHI2_HSCMP)
        #endif /* (CapSense_ADC_IDAC_SINKING == CapSense_ADC_CSD_IDAC_CONFIG) */
    #else
        #define CapSense_ADC_CSD_SW_SHIELD_SEL_SCAN              (0x00000000uL)
    #endif /* ((CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_EN) && \
               (CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_TANK_EN)) */

    #define CapSense_ADC_CSD_SW_RES_INIT                        (CapSense_ADC_CSD_INIT_SWITCH_RES << CYFLD_CSD_RES_HCAV__OFFSET)
    #define CapSense_ADC_CSD_SW_RES_SCAN                        ((CapSense_ADC_CSD_SHIELD_SWITCH_RES << CYFLD_CSD_RES_HCBV__OFFSET) |\
                                                                     (CapSense_ADC_CSD_SHIELD_SWITCH_RES << CYFLD_CSD_RES_HCBG__OFFSET))

    #define CapSense_ADC_CSD_SHIELD_GPIO_DM                 (CapSense_ADC_GPIO_STRGDRV)
    #define CapSense_ADC_CSD_SENSOR_HSIOM_SEL               (CapSense_ADC_HSIOM_SEL_CSD_SENSE)
    #define CapSense_ADC_CSD_SHIELD_HSIOM_SEL               (CapSense_ADC_HSIOM_SEL_CSD_SHIELD)
    #define CapSense_ADC_CSD_CMOD_HSIOM_SEL                 (CapSense_ADC_HSIOM_SEL_AMUXA)

    #define CapSense_ADC_DEFAULT_IDAC_MOD_BALL_MODE         ((uint32)CapSense_ADC_IDAC_MOD_BALL_MODE_FULL <<\
                                                                 CYFLD_CSD_BAL_MODE__OFFSET)
    #define CapSense_ADC_DEFAULT_IDAC_COMP_BALL_MODE        ((uint32)CapSense_ADC_IDAC_COMP_BALL_MODE_FULL <<\
                                                                 CYFLD_CSD_BAL_MODE__OFFSET)

    #define CapSense_ADC_DEFAULT_SENSE_DUTY_SEL             (CapSense_ADC_SENSE_DUTY_OVERLAP_PHI1_MASK |\
                                                                 CapSense_ADC_SENSE_DUTY_OVERLAP_PHI2_MASK)

    #define CapSense_ADC_CSD_IDAC_MOD_BITS_USED                     (7u)
    #define CapSense_ADC_CAL_MIDDLE_BIT                             (1uL << (CapSense_ADC_CSD_IDAC_MOD_BITS_USED - 1u))

    #define CapSense_ADC_DELAY_EXTRACYCLES_NUM                      (9u)

    #if (CapSense_ADC_IDAC_GAIN_HIGH == CapSense_ADC_CSD_IDAC_GAIN)
        #define CapSense_ADC_CSD_IDAC_GAIN_VALUE_NA                 (2400u)
    #elif (CapSense_ADC_IDAC_GAIN_MEDIUM == CapSense_ADC_CSD_IDAC_GAIN)
        #define CapSense_ADC_CSD_IDAC_GAIN_VALUE_NA                 (300u)
    #else
        #define CapSense_ADC_CSD_IDAC_GAIN_VALUE_NA                 (37u)
    #endif /* (CapSense_ADC_IDAC_GAIN_HIGH == CapSense_ADC_CSD_IDAC_GAIN) */

    /* Defining the drive mode of pins depending on the Inactive sensor connection setting in the Component customizer. */
    #if(CapSense_ADC_SNS_CONNECTION_GROUND == CapSense_ADC_CSD_INACTIVE_SNS_CONNECTION)
        #define CapSense_ADC_CSD_INACTIVE_SNS_GPIO_DM               (CY_SYS_PINS_DM_STRONG)
    #elif(CapSense_ADC_SNS_CONNECTION_HIGHZ == CapSense_ADC_CSD_INACTIVE_SNS_CONNECTION)
        #define CapSense_ADC_CSD_INACTIVE_SNS_GPIO_DM               (CY_SYS_PINS_DM_ALG_HIZ)
    #elif(CapSense_ADC_SNS_CONNECTION_SHIELD == CapSense_ADC_CSD_INACTIVE_SNS_CONNECTION)
        #define CapSense_ADC_CSD_INACTIVE_SNS_GPIO_DM               (CY_SYS_PINS_DM_ALG_HIZ)
    #else
        #error "Unsupported inactive connection for the inactive sensors."
    #endif /* (CapSense_ADC_SNS_CONNECTION_GROUND == CapSense_ADC_CSD_INACTIVE_SNS_CONNECTION) */


    /* Clock Source Mode */
    #if (CapSense_ADC_CLK_SOURCE_DIRECT == CapSense_ADC_CSD_SNS_CLK_SOURCE)
        #define CapSense_ADC_DEFAULT_MODULATION_MODE                (CapSense_ADC_CLK_SOURCE_DIRECT)
    #elif (CapSense_ADC_CLK_SOURCE_PRSAUTO == CapSense_ADC_CSD_SNS_CLK_SOURCE)
        #define CapSense_ADC_DEFAULT_MODULATION_MODE                (CapSense_ADC_CLK_SOURCE_SSC2)
    #elif ((CapSense_ADC_CLK_SOURCE_PRS8) == CapSense_ADC_CSD_SNS_CLK_SOURCE)
        #define CapSense_ADC_DEFAULT_MODULATION_MODE                (CapSense_ADC_CSD_SNS_CLK_SOURCE)
    #elif ((CapSense_ADC_CLK_SOURCE_PRS12) == CapSense_ADC_CSD_SNS_CLK_SOURCE)
        #define CapSense_ADC_DEFAULT_MODULATION_MODE                (CapSense_ADC_CSD_SNS_CLK_SOURCE)
    #else
        #define CapSense_ADC_DEFAULT_MODULATION_MODE                (CapSense_ADC_CSD_SNS_CLK_SOURCE)
    #endif /* (CapSense_ADC_CLK_SOURCE_DIRECT != CapSense_ADC_CSD_SNS_CLK_SOURCE) */

    /* IDACs Ranges */
    #if (CapSense_ADC_IDAC_GAIN_LOW == CapSense_ADC_CSD_IDAC_GAIN)
        #define CapSense_ADC_DEFAULT_IDAC_MOD_RANGE                 ((uint32)CapSense_ADC_IDAC_MOD_RANGE_IDAC_LO << CYFLD_CSD_RANGE__OFFSET)
        #define CapSense_ADC_DEFAULT_IDAC_COMP_RANGE                ((uint32)CapSense_ADC_IDAC_COMP_RANGE_IDAC_LO << CYFLD_CSD_RANGE__OFFSET)
    #elif (CapSense_ADC_IDAC_GAIN_MEDIUM == CapSense_ADC_CSD_IDAC_GAIN)
        #define CapSense_ADC_DEFAULT_IDAC_MOD_RANGE                 ((uint32)CapSense_ADC_IDAC_MOD_RANGE_IDAC_MED << CYFLD_CSD_RANGE__OFFSET)
        #define CapSense_ADC_DEFAULT_IDAC_COMP_RANGE                ((uint32)CapSense_ADC_IDAC_COMP_RANGE_IDAC_MED << CYFLD_CSD_RANGE__OFFSET)
    #else
        #define CapSense_ADC_DEFAULT_IDAC_MOD_RANGE                 ((uint32)CapSense_ADC_IDAC_MOD_RANGE_IDAC_HI << CYFLD_CSD_RANGE__OFFSET)
        #define CapSense_ADC_DEFAULT_IDAC_COMP_RANGE                ((uint32)CapSense_ADC_IDAC_COMP_RANGE_IDAC_HI << CYFLD_CSD_RANGE__OFFSET)
    #endif

    /* IDACs Polarities */
    #if (CapSense_ADC_IDAC_SINKING == CapSense_ADC_CSD_IDAC_CONFIG)
        #define CapSense_ADC_DEFAULT_IDAC_MOD_POLARITY              ((uint32)CapSense_ADC_IDAC_MOD_POLARITY_VDDA_SNK << CYFLD_CSD_POLARITY__OFFSET)
        #define CapSense_ADC_DEFAULT_IDAC_COMP_POLARITY             ((uint32)CapSense_ADC_IDAC_COMP_POLARITY_VDDA_SNK << CYFLD_CSD_POLARITY__OFFSET)
    #else
        #define CapSense_ADC_DEFAULT_IDAC_MOD_POLARITY              ((uint32)CapSense_ADC_IDAC_MOD_POLARITY_VSSA_SRC << CYFLD_CSD_POLARITY__OFFSET)
        #define CapSense_ADC_DEFAULT_IDAC_COMP_POLARITY             ((uint32)CapSense_ADC_IDAC_COMP_POLARITY_VSSA_SRC << CYFLD_CSD_POLARITY__OFFSET)
    #endif /* (CapSense_ADC_IDAC_SINKING == CapSense_ADC_CSD_IDAC_CONFIG) */

    #define CapSense_ADC_SW_REFGEN_VREF_SRC                         (CapSense_ADC_SW_REFGEN_SEL_SW_SGR_MASK)

    /* IDAC legs configuration */
    #if ((CapSense_ADC_ENABLE == CapSense_ADC_CSD_IDAC_COMP_EN) && \
         (CapSense_ADC_ENABLE == CapSense_ADC_CSD_DEDICATED_IDAC_COMP_EN))
            #define CapSense_ADC_DEFAULT_SW_REFGEN_SEL              (CapSense_ADC_SW_REFGEN_VREF_SRC | CapSense_ADC_SW_REFGEN_SEL_SW_IAIB_MASK)
            #define CapSense_ADC_DEFAULT_IDAC_COMP_LEG1_MODE        (CapSense_ADC_IDAC_COMP_LEG1_EN_MASK |\
                                                                        ((uint32)CapSense_ADC_IDAC_COMP_LEG1_MODE_CSD_STATIC << CYFLD_CSD_LEG1_MODE__OFFSET))
    #else
            #define CapSense_ADC_DEFAULT_SW_REFGEN_SEL              (CapSense_ADC_SW_REFGEN_VREF_SRC)
            #define CapSense_ADC_DEFAULT_IDAC_COMP_LEG1_MODE        ((uint32)CapSense_ADC_IDAC_COMP_LEG1_MODE_CSD_STATIC << CYFLD_CSD_LEG1_MODE__OFFSET)
    #endif /* ((CapSense_ADC_ENABLE == CapSense_ADC_CSD_IDAC_COMP_EN) && \
               (CapSense_ADC_ENABLE == CapSense_ADC_CSD_DEDICATED_IDAC_COMP_EN)) */


    #if ((CapSense_ADC_ENABLE == CapSense_ADC_CSD_IDAC_COMP_EN) && \
         (CapSense_ADC_DISABLE == CapSense_ADC_CSD_DEDICATED_IDAC_COMP_EN))
            #define CapSense_ADC_DEFAULT_IDAC_COMP_LEG2_MODE        (CapSense_ADC_IDAC_COMP_LEG2_EN_MASK |\
                                                                        ((uint32)CapSense_ADC_IDAC_COMP_LEG2_MODE_CSD_STATIC << CYFLD_CSD_LEG2_MODE__OFFSET))
    #else
            #define CapSense_ADC_DEFAULT_IDAC_COMP_LEG2_MODE        ((uint32)CapSense_ADC_IDAC_COMP_LEG2_MODE_GP_STATIC << CYFLD_CSD_LEG2_MODE__OFFSET)
    #endif /* ((CapSense_ADC_ENABLE == CapSense_ADC_CSD_IDAC_COMP_EN) && \
            (CapSense_ADC_DISABLE == CapSense_ADC_CSD_DEDICATED_IDAC_COMP_EN)) */

    /* IDACs register configuration is based on the Component configuration */
    #define CapSense_ADC_IDAC_MOD_DEFAULT_CFG                       (CapSense_ADC_DEFAULT_IDAC_MOD_RANGE | \
                                                                         CapSense_ADC_DEFAULT_IDAC_MOD_POLARITY | \
                                                                         CapSense_ADC_DEFAULT_IDAC_MOD_BALL_MODE | \
                                                                        ((uint32)(CapSense_ADC_IDAC_MOD_LEG1_MODE_CSD << CYFLD_CSD_LEG1_MODE__OFFSET)) | \
                                                                         CapSense_ADC_IDAC_MOD_LEG1_EN_MASK | \
                                                                         CapSense_ADC_DEFAULT_IDAC_COMP_LEG2_MODE)

    #define CapSense_ADC_IDAC_COMP_DEFAULT_CFG                      (CapSense_ADC_DEFAULT_IDAC_COMP_RANGE | \
                                                                         CapSense_ADC_DEFAULT_IDAC_COMP_POLARITY | \
                                                                         CapSense_ADC_DEFAULT_IDAC_COMP_BALL_MODE | \
                                                                         CapSense_ADC_DEFAULT_IDAC_COMP_LEG1_MODE | \
                                                                        ((uint32)(CapSense_ADC_IDAC_COMP_LEG2_MODE_GP_STATIC << CYFLD_CSD_LEG2_MODE__OFFSET)))

    #define CapSense_ADC_IDAC_MOD_CALIBRATION_CFG                   ((uint32)(CapSense_ADC_DEFAULT_IDAC_MOD_RANGE | \
                                                                         CapSense_ADC_DEFAULT_IDAC_MOD_POLARITY | \
                                                                         CapSense_ADC_DEFAULT_IDAC_MOD_BALL_MODE | \
                                                                        ((uint32)(CapSense_ADC_IDAC_MOD_LEG1_MODE_CSD << CYFLD_CSD_LEG1_MODE__OFFSET)) | \
                                                                         CapSense_ADC_IDAC_MOD_LEG1_EN_MASK | \
                                                                        ((uint32)((uint32)CapSense_ADC_IDAC_MOD_LEG2_MODE_GP_STATIC << CYFLD_CSD_LEG2_MODE__OFFSET))))

    #define CapSense_ADC_IDAC_COMP_CALIBRATION_CFG                  ((uint32)(CapSense_ADC_DEFAULT_IDAC_COMP_RANGE | \
                                                                         CapSense_ADC_DEFAULT_IDAC_COMP_POLARITY | \
                                                                         CapSense_ADC_DEFAULT_IDAC_COMP_BALL_MODE | \
                                                                        ((uint32)((uint32)CapSense_ADC_IDAC_COMP_LEG1_MODE_GP_STATIC << CYFLD_CSD_LEG1_MODE__OFFSET)) | \
                                                                        ((uint32)((uint32)CapSense_ADC_IDAC_COMP_LEG2_MODE_GP_STATIC << CYFLD_CSD_LEG2_MODE__OFFSET))))
#else
    #define CapSense_ADC_CSD_IDAC_MOD_BITS_USED                     (8u)

    #define CapSense_ADC_IDAC_MOD_CFG_MASK                  (CapSense_ADC_IDAC_POLARITY1_MIR_MASK |\
                                                                CapSense_ADC_IDAC_MOD_RANGE_MASK |\
                                                                CapSense_ADC_IDAC_MOD_MODE_MASK |\
                                                                CapSense_ADC_IDAC_MOD_MASK)

    #define CapSense_ADC_IDAC_COMP_CFG_MASK                 (CapSense_ADC_IDAC_POLARITY2_MIR_MASK |\
                                                                CapSense_ADC_IDAC_COMP_RANGE_MASK |\
                                                                CapSense_ADC_IDAC_COMP_MODE_MASK |\
                                                                CapSense_ADC_IDAC_COMP_MASK)

        #define CapSense_ADC_PRS_8_CONFIG                       CapSense_ADC_CONFIG_PRS_SELECT_MASK
    #define CapSense_ADC_PRS_12_CONFIG                      (CapSense_ADC_CONFIG_PRS_12_8_MASK |\
                                                                CapSense_ADC_CONFIG_PRS_SELECT_MASK)

    /* Third-generation HW block Initial PRS mode */
    #if (CapSense_ADC_CLK_SOURCE_PRS8 == CapSense_ADC_CSD_SNS_CLK_SOURCE)
        #define CapSense_ADC_DEFAULT_MODULATION_MODE        CapSense_ADC_CONFIG_PRS_SELECT_MASK

    #elif (CapSense_ADC_CLK_SOURCE_PRS12 == CapSense_ADC_CSD_SNS_CLK_SOURCE)
        #define CapSense_ADC_DEFAULT_MODULATION_MODE        (CapSense_ADC_CONFIG_PRS_12_8_MASK |\
                                                                CapSense_ADC_CONFIG_PRS_SELECT_MASK)
    #else
        #define CapSense_ADC_DEFAULT_MODULATION_MODE        (0u)
    #endif /* (CapSense_ADC_CSD_SNS_CLK_SOURCE == CapSense_ADC_PRS_8BITS) */

    /* Third-generation HW block Set IDAC polarity */
    #if (CapSense_ADC_CSD_IDAC_CONFIG == CapSense_ADC_IDAC_SINKING)
        #define CapSense_ADC_DEFAULT_IDAC_POLARITY          CapSense_ADC_CONFIG_POLARITY_MASK
        #define CapSense_ADC_CSH_DR_CONFIG                  CapSense_ADC_CTANK_DR_VDDIO
    #else
        #define CapSense_ADC_DEFAULT_IDAC_POLARITY          (0u)
        #define CapSense_ADC_CSH_DR_CONFIG                  CapSense_ADC_CTANK_DR_VSSIO
    #endif /* (CapSense_ADC_CSD_IDAC_CONFIG == CapSense_ADC_IDAC_SINKING) */

    /* Defining default CSD configuration according to settings in customizer. */
    #define CapSense_ADC_DEFAULT_CSD_CONFIG                 (CapSense_ADC_CONFIG_SENSE_COMP_BW_MASK |\
                                                                CapSense_ADC_DEFAULT_IDAC_POLARITY |\
                                                                CapSense_ADC_CONFIG_SENSE_INSEL_MASK |\
                                                                CapSense_ADC_CONFIG_REFBUF_DRV_MASK)

    #define CapSense_ADC_CSD_ENABLE_MASK                    (CapSense_ADC_CONFIG_ENABLE_MASK |\
                                                                CapSense_ADC_CONFIG_SENSE_EN_MASK |\
                                                                CapSense_ADC_CONFIG_SENSE_COMP_EN_MASK)

    /* Third-generation HW block Defining mask intended for clearing bits related to pre-charging options. */
    #define CapSense_ADC_PRECHARGE_CONFIG_MASK              (CapSense_ADC_CONFIG_REFBUF_EN_MASK |\
                                                                CapSense_ADC_CONFIG_COMP_MODE_MASK |\
                                                                CapSense_ADC_CONFIG_COMP_PIN_MASK  |\
                                                                CapSense_ADC_CONFIG_REFBUF_OUTSEL_MASK)

    #define CapSense_ADC_CMOD_PRECHARGE_CONFIG              (CapSense_ADC_DEFAULT_CSD_CONFIG |\
                                                                CapSense_ADC_CONFIG_REFBUF_EN_MASK |\
                                                                CapSense_ADC_CONFIG_COMP_PIN_MASK)

    #define CapSense_ADC_CMOD_PRECHARGE_CONFIG_CSD_EN       (CapSense_ADC_DEFAULT_CSD_CONFIG |\
                                                                CapSense_ADC_CSD_ENABLE_MASK |\
                                                                CapSense_ADC_CONFIG_REFBUF_EN_MASK |\
                                                                CapSense_ADC_CONFIG_COMP_PIN_MASK)


    /* Third-generation HW block Ctank pre-charge mode configuration */
    #if(CapSense_ADC_CSD_CSH_PRECHARGE_SRC == CapSense_ADC_CSH_PRECHARGE_VREF)
        #if (CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_EN)
            #define  CapSense_ADC_CTANK_PRECHARGE_CONFIG    (CapSense_ADC_DEFAULT_CSD_CONFIG |\
                                                                 CapSense_ADC_CONFIG_REFBUF_EN_MASK |\
                                                                 CapSense_ADC_CONFIG_PRS_CLEAR_MASK |\
                                                                 CapSense_ADC_CONFIG_REFBUF_OUTSEL_MASK)
        #else
            #define  CapSense_ADC_CTANK_PRECHARGE_CONFIG    (CapSense_ADC_DEFAULT_CSD_CONFIG |\
                                                                 CapSense_ADC_CONFIG_REFBUF_OUTSEL_MASK |\
                                                                 CapSense_ADC_CONFIG_PRS_CLEAR_MASK)
        #endif /* (CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_EN) */
    #else
        #define  CapSense_ADC_CTANK_PRECHARGE_CONFIG        (CapSense_ADC_DEFAULT_CSD_CONFIG |\
                                                                CapSense_ADC_CONFIG_REFBUF_OUTSEL_MASK |\
                                                                CapSense_ADC_CONFIG_REFBUF_EN_MASK |\
                                                                CapSense_ADC_CONFIG_COMP_MODE_MASK |\
                                                                CapSense_ADC_CONFIG_PRS_CLEAR_MASK |\
                                                                CapSense_ADC_CONFIG_COMP_PIN_MASK)
    #endif /* (CapSense_ADC_CSD_CSH_PRECHARGE_SRC == CapSense_ADC__CSH_PRECHARGE_IO_BUF) */

    #define  CapSense_ADC_CTANK_PRECHARGE_CONFIG_CSD_EN     (CapSense_ADC_CTANK_PRECHARGE_CONFIG |\
                                                                 CapSense_ADC_CONFIG_ENABLE_MASK |\
                                                                 CapSense_ADC_CONFIG_SENSE_COMP_EN_MASK)

#endif /* (CapSense_ADC_ENABLE == CapSense_ADC_CSDV2) */

/* Calibration constants */
#define CapSense_ADC_IDAC_MOD_MAX_CALIB_ERROR                       (10u)
#define CapSense_ADC_CAL_MIDDLE_BIT                                 (1uL << (CapSense_ADC_CSD_IDAC_MOD_BITS_USED - 1u))

#define CapSense_ADC_CSD_AVG_CYCLES_PER_LOOP                   (5u)
#define CapSense_ADC_CSD_MEASURE_MAX_TIME_US                   (6000u)
#define CapSense_ADC_CSD_PRECHARGE_MAX_TIME_US                 (250u)

#define CapSense_ADC_CSD_CALIBR_WATCHDOG_CYCLES_NUM            (((CYDEV_BCLK__SYSCLK__MHZ) * (CapSense_ADC_CSD_MEASURE_MAX_TIME_US)) /\
                                                                    (CapSense_ADC_CSD_AVG_CYCLES_PER_LOOP))
#define CapSense_ADC_CSD_PRECHARGE_WATCHDOG_CYCLES_NUM         (((CYDEV_BCLK__SYSCLK__MHZ) * (CapSense_ADC_CSD_MEASURE_MAX_TIME_US)) /\
                                                                    (CapSense_ADC_CSD_AVG_CYCLES_PER_LOOP))

/***************************************
* Global software variables
***************************************/

extern uint32 CapSense_ADC_configCsd;

#if (CapSense_ADC_ENABLE == CapSense_ADC_CSD_NOISE_METRIC_EN)
    extern uint8 CapSense_ADC_badConversionsNum;
#endif /* (CapSense_ADC_ENABLE == CapSense_ADC_CSD_NOISE_METRIC_EN) */

#if (CapSense_ADC_CSD_SS_DIS != CapSense_ADC_CSD_AUTOTUNE)
    /* Stores IDAC and raw count that corresponds to a sensor with maximum Cp within a widget */
    extern uint8 CapSense_ADC_calibratedIdac;
    extern uint16 CapSense_ADC_calibratedRawcount;
    #if (CapSense_ADC_CSD_MATRIX_WIDGET_EN || CapSense_ADC_CSD_TOUCHPAD_WIDGET_EN)
        extern uint8 CapSense_ADC_calibratedIdacRow;
        extern uint16 CapSense_ADC_calibratedRawcountRow;
    #endif /*(CapSense_ADC_CSD_MATRIX_WIDGET_EN || CapSense_ADC_CSD_TOUCHPAD_WIDGET_EN) */
#endif /* (CapSense_ADC_CSD_SS_DIS != CapSense_ADC_CSD_AUTOTUNE) */

/***************************************
* Function Prototypes
**************************************/

/**
* \cond SECTION_C_LOW_LEVEL
* \addtogroup group_c_low_level
* \{
*/

void CapSense_ADC_CSDSetupWidget(uint32 widgetId);
void CapSense_ADC_CSDSetupWidgetExt(uint32 widgetId, uint32 sensorId);
void CapSense_ADC_CSDScan(void);
void CapSense_ADC_CSDScanExt(void);
#if ((CapSense_ADC_CSD_SS_DIS != CapSense_ADC_CSD_AUTOTUNE) || \
     (CapSense_ADC_ENABLE == CapSense_ADC_CSD_IDAC_AUTOCAL_EN))
    cystatus CapSense_ADC_CSDCalibrateWidget(uint32 widgetId, uint32 target);
#endif /* ((CapSense_ADC_CSD_SS_DIS != CapSense_ADC_CSD_AUTOTUNE) || \
           (CapSense_ADC_ENABLE == CapSense_ADC_CSD_IDAC_AUTOCAL_EN))  */
void CapSense_ADC_CSDConnectSns(CapSense_ADC_FLASH_IO_STRUCT const *snsAddrPtr);
void CapSense_ADC_CSDDisconnectSns(CapSense_ADC_FLASH_IO_STRUCT const *snsAddrPtr);

/** \}
* \endcond */

/*****************************************************
* Function Prototypes - internal Low Level functions
*****************************************************/

/**
* \cond SECTION_C_INTERNAL
* \addtogroup group_c_internal
* \{
*/

void CapSense_ADC_SsCSDInitialize(void);
void CapSense_ADC_SsCSDStartSample(void);
void CapSense_ADC_SsCSDSetUpIdacs(CapSense_ADC_RAM_WD_BASE_STRUCT const *ptrWdgt);
void CapSense_ADC_SsCSDConfigClock(void);
void CapSense_ADC_SsCSDElectrodeCheck(void);
#if ((CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_EN) && \
     (0u != CapSense_ADC_CSD_TOTAL_SHIELD_COUNT))
    void CapSense_ADC_SsCSDDisableShieldElectrodes(void);
#endif /* ((CapSense_ADC_ENABLE == CapSense_ADC_CSD_SHIELD_EN) && \
           (0u != CapSense_ADC_CSD_TOTAL_SHIELD_COUNT)) */
#if (CapSense_ADC_ENABLE == CapSense_ADC_CSDV2)
    uint32 CapSense_ADC_SsCSDGetNumberOfConversions(uint32 snsClkDivider, uint32 resolution, uint32 snsClkSrc);
#endif /* (CapSense_ADC_ENABLE == CapSense_ADC_CSDV2) */
void CapSense_ADC_SsCSDCalculateScanDuration(CapSense_ADC_RAM_WD_BASE_STRUCT const *ptrWdgt);
void CapSense_ADC_SsCSDConnectSensorExt(uint32 widgetId, uint32 sensorId);
void CapSense_ADC_SsCSDDisconnectSnsExt(uint32 widgetId, uint32 sensorId);

#if ((CapSense_ADC_CSD_SS_DIS != CapSense_ADC_CSD_AUTOTUNE) || \
     (CapSense_ADC_ENABLE == CapSense_ADC_SELF_TEST_EN) || \
     (CapSense_ADC_ENABLE == CapSense_ADC_CSD_IDAC_AUTOCAL_EN))
#endif /* ((CapSense_ADC_CSD_SS_DIS != CapSense_ADC_CSD_AUTOTUNE) || \
           (CapSense_ADC_ENABLE == CapSense_ADC_SELF_TEST_EN) || \
           (CapSense_ADC_ENABLE == CapSense_ADC_CSD_IDAC_AUTOCAL_EN)) */

/** \}
* \endcond */

/***************************************
* Global software variables
***************************************/
extern uint32 CapSense_ADC_configCsd;

/* Interrupt handler */
extern CY_ISR_PROTO(CapSense_ADC_CSDPostSingleScan);
extern CY_ISR_PROTO(CapSense_ADC_CSDPostMultiScan);
#if (CapSense_ADC_ENABLE == CapSense_ADC_CSD_GANGED_SNS_EN)
extern CY_ISR_PROTO(CapSense_ADC_CSDPostMultiScanGanged);
#endif /* (CapSense_ADC_ENABLE == CapSense_ADC_CSD_GANGED_SNS_EN) */
#if (CapSense_ADC_ENABLE == CapSense_ADC_CSD_NOISE_METRIC_EN)
    extern uint8 CapSense_ADC_badConversionsNum;
#endif /* (CapSense_ADC_ENABLE == CapSense_ADC_CSD_NOISE_METRIC_EN) */

#endif /* End CY_SENSE_CapSense_ADC_SENSINGCSD_LL_H */


/* [] END OF FILE */