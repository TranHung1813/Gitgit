/***************************************************************************//**
* \file CapSense_RegisterMap.h
* \version 5.0
*
* \brief
*   This file provides the definitions for the Component data structure register.
*
* \see CapSense v5.0 Datasheet
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

#if !defined(CY_SENSE_CapSense_REGISTER_MAP_H)
#define CY_SENSE_CapSense_REGISTER_MAP_H

#include <cytypes.h>
#include "CapSense_Configuration.h"
#include "CapSense_Structure.h"

/*****************************************************************************/
/* RAM Data structure register definitions                                   */
/*****************************************************************************/
#define CapSense_CONFIG_ID_VALUE                            (CapSense_dsRam.configId)
#define CapSense_CONFIG_ID_OFFSET                           (0u)
#define CapSense_CONFIG_ID_SIZE                             (2u)
#define CapSense_CONFIG_ID_PARAM_ID                         (0x87000000u)

#define CapSense_DEVICE_ID_VALUE                            (CapSense_dsRam.deviceId)
#define CapSense_DEVICE_ID_OFFSET                           (2u)
#define CapSense_DEVICE_ID_SIZE                             (2u)
#define CapSense_DEVICE_ID_PARAM_ID                         (0x8B000002u)

#define CapSense_HW_CLOCK_VALUE                             (CapSense_dsRam.hwClock)
#define CapSense_HW_CLOCK_OFFSET                            (4u)
#define CapSense_HW_CLOCK_SIZE                              (2u)
#define CapSense_HW_CLOCK_PARAM_ID                          (0x86000004u)

#define CapSense_TUNER_CMD_VALUE                            (CapSense_dsRam.tunerCmd)
#define CapSense_TUNER_CMD_OFFSET                           (6u)
#define CapSense_TUNER_CMD_SIZE                             (2u)
#define CapSense_TUNER_CMD_PARAM_ID                         (0xA1000006u)

#define CapSense_SCAN_COUNTER_VALUE                         (CapSense_dsRam.scanCounter)
#define CapSense_SCAN_COUNTER_OFFSET                        (8u)
#define CapSense_SCAN_COUNTER_SIZE                          (2u)
#define CapSense_SCAN_COUNTER_PARAM_ID                      (0x85000008u)

#define CapSense_STATUS_VALUE                               (CapSense_dsRam.status)
#define CapSense_STATUS_OFFSET                              (12u)
#define CapSense_STATUS_SIZE                                (4u)
#define CapSense_STATUS_PARAM_ID                            (0xCB00000Cu)

#define CapSense_WDGT_ENABLE0_VALUE                         (CapSense_dsRam.wdgtEnable[0u])
#define CapSense_WDGT_ENABLE0_OFFSET                        (16u)
#define CapSense_WDGT_ENABLE0_SIZE                          (4u)
#define CapSense_WDGT_ENABLE0_PARAM_ID                      (0xE6000010u)

#define CapSense_WDGT_STATUS0_VALUE                         (CapSense_dsRam.wdgtStatus[0u])
#define CapSense_WDGT_STATUS0_OFFSET                        (20u)
#define CapSense_WDGT_STATUS0_SIZE                          (4u)
#define CapSense_WDGT_STATUS0_PARAM_ID                      (0xCC000014u)

#define CapSense_SNS_STATUS0_VALUE                          (CapSense_dsRam.snsStatus[0u])
#define CapSense_SNS_STATUS0_OFFSET                         (24u)
#define CapSense_SNS_STATUS0_SIZE                           (1u)
#define CapSense_SNS_STATUS0_PARAM_ID                       (0x48000018u)

#define CapSense_SNS_STATUS1_VALUE                          (CapSense_dsRam.snsStatus[1u])
#define CapSense_SNS_STATUS1_OFFSET                         (25u)
#define CapSense_SNS_STATUS1_SIZE                           (1u)
#define CapSense_SNS_STATUS1_PARAM_ID                       (0x4E000019u)

#define CapSense_SNS_STATUS2_VALUE                          (CapSense_dsRam.snsStatus[2u])
#define CapSense_SNS_STATUS2_OFFSET                         (26u)
#define CapSense_SNS_STATUS2_SIZE                           (1u)
#define CapSense_SNS_STATUS2_PARAM_ID                       (0x4400001Au)

#define CapSense_SNS_STATUS3_VALUE                          (CapSense_dsRam.snsStatus[3u])
#define CapSense_SNS_STATUS3_OFFSET                         (27u)
#define CapSense_SNS_STATUS3_SIZE                           (1u)
#define CapSense_SNS_STATUS3_PARAM_ID                       (0x4200001Bu)

#define CapSense_ADC_RESULT0_VALUE                          (CapSense_dsRam.adcResult[0u])
#define CapSense_ADC_RESULT0_OFFSET                         (28u)
#define CapSense_ADC_RESULT0_SIZE                           (2u)
#define CapSense_ADC_RESULT0_PARAM_ID                       (0x8100001Cu)

#define CapSense_ADC_CODE0_VALUE                            (CapSense_dsRam.adcCode[0u])
#define CapSense_ADC_CODE0_OFFSET                           (30u)
#define CapSense_ADC_CODE0_SIZE                             (2u)
#define CapSense_ADC_CODE0_PARAM_ID                         (0x8D00001Eu)

#define CapSense_ADC_STATUS_VALUE                           (CapSense_dsRam.adcStatus)
#define CapSense_ADC_STATUS_OFFSET                          (32u)
#define CapSense_ADC_STATUS_SIZE                            (1u)
#define CapSense_ADC_STATUS_PARAM_ID                        (0x45000020u)

#define CapSense_ADC_IDAC_VALUE                             (CapSense_dsRam.adcIdac)
#define CapSense_ADC_IDAC_OFFSET                            (33u)
#define CapSense_ADC_IDAC_SIZE                              (1u)
#define CapSense_ADC_IDAC_PARAM_ID                          (0x43000021u)

#define CapSense_ADC_ACTIVE_CH_VALUE                        (CapSense_dsRam.adcActiveCh)
#define CapSense_ADC_ACTIVE_CH_OFFSET                       (34u)
#define CapSense_ADC_ACTIVE_CH_SIZE                         (1u)
#define CapSense_ADC_ACTIVE_CH_PARAM_ID                     (0x49000022u)

#define CapSense_CSD0_CONFIG_VALUE                          (CapSense_dsRam.csd0Config)
#define CapSense_CSD0_CONFIG_OFFSET                         (36u)
#define CapSense_CSD0_CONFIG_SIZE                           (2u)
#define CapSense_CSD0_CONFIG_PARAM_ID                       (0xAA800024u)

#define CapSense_MOD_CSD_CLK_VALUE                          (CapSense_dsRam.modCsdClk)
#define CapSense_MOD_CSD_CLK_OFFSET                         (38u)
#define CapSense_MOD_CSD_CLK_SIZE                           (1u)
#define CapSense_MOD_CSD_CLK_PARAM_ID                       (0x6E800026u)

#define CapSense_ADC_RESOLUTION_VALUE                       (CapSense_dsRam.adcResolution)
#define CapSense_ADC_RESOLUTION_OFFSET                      (39u)
#define CapSense_ADC_RESOLUTION_SIZE                        (1u)
#define CapSense_ADC_RESOLUTION_PARAM_ID                    (0x43800027u)

#define CapSense_ADC_AZTIME_VALUE                           (CapSense_dsRam.adcAzTime)
#define CapSense_ADC_AZTIME_OFFSET                          (40u)
#define CapSense_ADC_AZTIME_SIZE                            (1u)
#define CapSense_ADC_AZTIME_PARAM_ID                        (0x4A800028u)

#define CapSense_BTNRO_RESOLUTION_VALUE                     (CapSense_dsRam.wdgtList.btnro.resolution)
#define CapSense_BTNRO_RESOLUTION_OFFSET                    (42u)
#define CapSense_BTNRO_RESOLUTION_SIZE                      (2u)
#define CapSense_BTNRO_RESOLUTION_PARAM_ID                  (0xA580002Au)

#define CapSense_BTNRO_FINGER_TH_VALUE                      (CapSense_dsRam.wdgtList.btnro.fingerTh)
#define CapSense_BTNRO_FINGER_TH_OFFSET                     (44u)
#define CapSense_BTNRO_FINGER_TH_SIZE                       (2u)
#define CapSense_BTNRO_FINGER_TH_PARAM_ID                   (0xA880002Cu)

#define CapSense_BTNRO_NOISE_TH_VALUE                       (CapSense_dsRam.wdgtList.btnro.noiseTh)
#define CapSense_BTNRO_NOISE_TH_OFFSET                      (46u)
#define CapSense_BTNRO_NOISE_TH_SIZE                        (1u)
#define CapSense_BTNRO_NOISE_TH_PARAM_ID                    (0x6C80002Eu)

#define CapSense_BTNRO_NNOISE_TH_VALUE                      (CapSense_dsRam.wdgtList.btnro.nNoiseTh)
#define CapSense_BTNRO_NNOISE_TH_OFFSET                     (47u)
#define CapSense_BTNRO_NNOISE_TH_SIZE                       (1u)
#define CapSense_BTNRO_NNOISE_TH_PARAM_ID                   (0x6A80002Fu)

#define CapSense_BTNRO_HYSTERESIS_VALUE                     (CapSense_dsRam.wdgtList.btnro.hysteresis)
#define CapSense_BTNRO_HYSTERESIS_OFFSET                    (48u)
#define CapSense_BTNRO_HYSTERESIS_SIZE                      (1u)
#define CapSense_BTNRO_HYSTERESIS_PARAM_ID                  (0x66800030u)

#define CapSense_BTNRO_ON_DEBOUNCE_VALUE                    (CapSense_dsRam.wdgtList.btnro.onDebounce)
#define CapSense_BTNRO_ON_DEBOUNCE_OFFSET                   (49u)
#define CapSense_BTNRO_ON_DEBOUNCE_SIZE                     (1u)
#define CapSense_BTNRO_ON_DEBOUNCE_PARAM_ID                 (0x60800031u)

#define CapSense_BTNRO_LOW_BSLN_RST_VALUE                   (CapSense_dsRam.wdgtList.btnro.lowBslnRst)
#define CapSense_BTNRO_LOW_BSLN_RST_OFFSET                  (50u)
#define CapSense_BTNRO_LOW_BSLN_RST_SIZE                    (1u)
#define CapSense_BTNRO_LOW_BSLN_RST_PARAM_ID                (0x6A800032u)

#define CapSense_BTNRO_IDAC_MOD0_VALUE                      (CapSense_dsRam.wdgtList.btnro.idacMod[0u])
#define CapSense_BTNRO_IDAC_MOD0_OFFSET                     (51u)
#define CapSense_BTNRO_IDAC_MOD0_SIZE                       (1u)
#define CapSense_BTNRO_IDAC_MOD0_PARAM_ID                   (0x4A000033u)

#define CapSense_BTNRO_SNS_CLK_VALUE                        (CapSense_dsRam.wdgtList.btnro.snsClk)
#define CapSense_BTNRO_SNS_CLK_OFFSET                       (52u)
#define CapSense_BTNRO_SNS_CLK_SIZE                         (2u)
#define CapSense_BTNRO_SNS_CLK_PARAM_ID                     (0xAF800034u)

#define CapSense_BTNRO_SNS_CLK_SOURCE_VALUE                 (CapSense_dsRam.wdgtList.btnro.snsClkSource)
#define CapSense_BTNRO_SNS_CLK_SOURCE_OFFSET                (54u)
#define CapSense_BTNRO_SNS_CLK_SOURCE_SIZE                  (1u)
#define CapSense_BTNRO_SNS_CLK_SOURCE_PARAM_ID              (0x40800036u)

#define CapSense_BTNCOLD_RESOLUTION_VALUE                   (CapSense_dsRam.wdgtList.btncold.resolution)
#define CapSense_BTNCOLD_RESOLUTION_OFFSET                  (56u)
#define CapSense_BTNCOLD_RESOLUTION_SIZE                    (2u)
#define CapSense_BTNCOLD_RESOLUTION_PARAM_ID                (0xAF810038u)

#define CapSense_BTNCOLD_FINGER_TH_VALUE                    (CapSense_dsRam.wdgtList.btncold.fingerTh)
#define CapSense_BTNCOLD_FINGER_TH_OFFSET                   (58u)
#define CapSense_BTNCOLD_FINGER_TH_SIZE                     (2u)
#define CapSense_BTNCOLD_FINGER_TH_PARAM_ID                 (0xA381003Au)

#define CapSense_BTNCOLD_NOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.btncold.noiseTh)
#define CapSense_BTNCOLD_NOISE_TH_OFFSET                    (60u)
#define CapSense_BTNCOLD_NOISE_TH_SIZE                      (1u)
#define CapSense_BTNCOLD_NOISE_TH_PARAM_ID                  (0x6681003Cu)

#define CapSense_BTNCOLD_NNOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.btncold.nNoiseTh)
#define CapSense_BTNCOLD_NNOISE_TH_OFFSET                   (61u)
#define CapSense_BTNCOLD_NNOISE_TH_SIZE                     (1u)
#define CapSense_BTNCOLD_NNOISE_TH_PARAM_ID                 (0x6081003Du)

#define CapSense_BTNCOLD_HYSTERESIS_VALUE                   (CapSense_dsRam.wdgtList.btncold.hysteresis)
#define CapSense_BTNCOLD_HYSTERESIS_OFFSET                  (62u)
#define CapSense_BTNCOLD_HYSTERESIS_SIZE                    (1u)
#define CapSense_BTNCOLD_HYSTERESIS_PARAM_ID                (0x6A81003Eu)

#define CapSense_BTNCOLD_ON_DEBOUNCE_VALUE                  (CapSense_dsRam.wdgtList.btncold.onDebounce)
#define CapSense_BTNCOLD_ON_DEBOUNCE_OFFSET                 (63u)
#define CapSense_BTNCOLD_ON_DEBOUNCE_SIZE                   (1u)
#define CapSense_BTNCOLD_ON_DEBOUNCE_PARAM_ID               (0x6C81003Fu)

#define CapSense_BTNCOLD_LOW_BSLN_RST_VALUE                 (CapSense_dsRam.wdgtList.btncold.lowBslnRst)
#define CapSense_BTNCOLD_LOW_BSLN_RST_OFFSET                (64u)
#define CapSense_BTNCOLD_LOW_BSLN_RST_SIZE                  (1u)
#define CapSense_BTNCOLD_LOW_BSLN_RST_PARAM_ID              (0x67810040u)

#define CapSense_BTNCOLD_IDAC_MOD0_VALUE                    (CapSense_dsRam.wdgtList.btncold.idacMod[0u])
#define CapSense_BTNCOLD_IDAC_MOD0_OFFSET                   (65u)
#define CapSense_BTNCOLD_IDAC_MOD0_SIZE                     (1u)
#define CapSense_BTNCOLD_IDAC_MOD0_PARAM_ID                 (0x47010041u)

#define CapSense_BTNCOLD_SNS_CLK_VALUE                      (CapSense_dsRam.wdgtList.btncold.snsClk)
#define CapSense_BTNCOLD_SNS_CLK_OFFSET                     (66u)
#define CapSense_BTNCOLD_SNS_CLK_SIZE                       (2u)
#define CapSense_BTNCOLD_SNS_CLK_PARAM_ID                   (0xA3810042u)

#define CapSense_BTNCOLD_SNS_CLK_SOURCE_VALUE               (CapSense_dsRam.wdgtList.btncold.snsClkSource)
#define CapSense_BTNCOLD_SNS_CLK_SOURCE_OFFSET              (68u)
#define CapSense_BTNCOLD_SNS_CLK_SOURCE_SIZE                (1u)
#define CapSense_BTNCOLD_SNS_CLK_SOURCE_PARAM_ID            (0x4D810044u)

#define CapSense_BTNHOT_RESOLUTION_VALUE                    (CapSense_dsRam.wdgtList.btnhot.resolution)
#define CapSense_BTNHOT_RESOLUTION_OFFSET                   (70u)
#define CapSense_BTNHOT_RESOLUTION_SIZE                     (2u)
#define CapSense_BTNHOT_RESOLUTION_PARAM_ID                 (0xA7820046u)

#define CapSense_BTNHOT_FINGER_TH_VALUE                     (CapSense_dsRam.wdgtList.btnhot.fingerTh)
#define CapSense_BTNHOT_FINGER_TH_OFFSET                    (72u)
#define CapSense_BTNHOT_FINGER_TH_SIZE                      (2u)
#define CapSense_BTNHOT_FINGER_TH_PARAM_ID                  (0xA8820048u)

#define CapSense_BTNHOT_NOISE_TH_VALUE                      (CapSense_dsRam.wdgtList.btnhot.noiseTh)
#define CapSense_BTNHOT_NOISE_TH_OFFSET                     (74u)
#define CapSense_BTNHOT_NOISE_TH_SIZE                       (1u)
#define CapSense_BTNHOT_NOISE_TH_PARAM_ID                   (0x6C82004Au)

#define CapSense_BTNHOT_NNOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.btnhot.nNoiseTh)
#define CapSense_BTNHOT_NNOISE_TH_OFFSET                    (75u)
#define CapSense_BTNHOT_NNOISE_TH_SIZE                      (1u)
#define CapSense_BTNHOT_NNOISE_TH_PARAM_ID                  (0x6A82004Bu)

#define CapSense_BTNHOT_HYSTERESIS_VALUE                    (CapSense_dsRam.wdgtList.btnhot.hysteresis)
#define CapSense_BTNHOT_HYSTERESIS_OFFSET                   (76u)
#define CapSense_BTNHOT_HYSTERESIS_SIZE                     (1u)
#define CapSense_BTNHOT_HYSTERESIS_PARAM_ID                 (0x6182004Cu)

#define CapSense_BTNHOT_ON_DEBOUNCE_VALUE                   (CapSense_dsRam.wdgtList.btnhot.onDebounce)
#define CapSense_BTNHOT_ON_DEBOUNCE_OFFSET                  (77u)
#define CapSense_BTNHOT_ON_DEBOUNCE_SIZE                    (1u)
#define CapSense_BTNHOT_ON_DEBOUNCE_PARAM_ID                (0x6782004Du)

#define CapSense_BTNHOT_LOW_BSLN_RST_VALUE                  (CapSense_dsRam.wdgtList.btnhot.lowBslnRst)
#define CapSense_BTNHOT_LOW_BSLN_RST_OFFSET                 (78u)
#define CapSense_BTNHOT_LOW_BSLN_RST_SIZE                   (1u)
#define CapSense_BTNHOT_LOW_BSLN_RST_PARAM_ID               (0x6D82004Eu)

#define CapSense_BTNHOT_IDAC_MOD0_VALUE                     (CapSense_dsRam.wdgtList.btnhot.idacMod[0u])
#define CapSense_BTNHOT_IDAC_MOD0_OFFSET                    (79u)
#define CapSense_BTNHOT_IDAC_MOD0_SIZE                      (1u)
#define CapSense_BTNHOT_IDAC_MOD0_PARAM_ID                  (0x4D02004Fu)

#define CapSense_BTNHOT_SNS_CLK_VALUE                       (CapSense_dsRam.wdgtList.btnhot.snsClk)
#define CapSense_BTNHOT_SNS_CLK_OFFSET                      (80u)
#define CapSense_BTNHOT_SNS_CLK_SIZE                        (2u)
#define CapSense_BTNHOT_SNS_CLK_PARAM_ID                    (0xAF820050u)

#define CapSense_BTNHOT_SNS_CLK_SOURCE_VALUE                (CapSense_dsRam.wdgtList.btnhot.snsClkSource)
#define CapSense_BTNHOT_SNS_CLK_SOURCE_OFFSET               (82u)
#define CapSense_BTNHOT_SNS_CLK_SOURCE_SIZE                 (1u)
#define CapSense_BTNHOT_SNS_CLK_SOURCE_PARAM_ID             (0x40820052u)

#define CapSense_BTNLOCK_RESOLUTION_VALUE                   (CapSense_dsRam.wdgtList.btnlock.resolution)
#define CapSense_BTNLOCK_RESOLUTION_OFFSET                  (84u)
#define CapSense_BTNLOCK_RESOLUTION_SIZE                    (2u)
#define CapSense_BTNLOCK_RESOLUTION_PARAM_ID                (0xAD830054u)

#define CapSense_BTNLOCK_FINGER_TH_VALUE                    (CapSense_dsRam.wdgtList.btnlock.fingerTh)
#define CapSense_BTNLOCK_FINGER_TH_OFFSET                   (86u)
#define CapSense_BTNLOCK_FINGER_TH_SIZE                     (2u)
#define CapSense_BTNLOCK_FINGER_TH_PARAM_ID                 (0xA1830056u)

#define CapSense_BTNLOCK_NOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.btnlock.noiseTh)
#define CapSense_BTNLOCK_NOISE_TH_OFFSET                    (88u)
#define CapSense_BTNLOCK_NOISE_TH_SIZE                      (1u)
#define CapSense_BTNLOCK_NOISE_TH_PARAM_ID                  (0x66830058u)

#define CapSense_BTNLOCK_NNOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.btnlock.nNoiseTh)
#define CapSense_BTNLOCK_NNOISE_TH_OFFSET                   (89u)
#define CapSense_BTNLOCK_NNOISE_TH_SIZE                     (1u)
#define CapSense_BTNLOCK_NNOISE_TH_PARAM_ID                 (0x60830059u)

#define CapSense_BTNLOCK_HYSTERESIS_VALUE                   (CapSense_dsRam.wdgtList.btnlock.hysteresis)
#define CapSense_BTNLOCK_HYSTERESIS_OFFSET                  (90u)
#define CapSense_BTNLOCK_HYSTERESIS_SIZE                    (1u)
#define CapSense_BTNLOCK_HYSTERESIS_PARAM_ID                (0x6A83005Au)

#define CapSense_BTNLOCK_ON_DEBOUNCE_VALUE                  (CapSense_dsRam.wdgtList.btnlock.onDebounce)
#define CapSense_BTNLOCK_ON_DEBOUNCE_OFFSET                 (91u)
#define CapSense_BTNLOCK_ON_DEBOUNCE_SIZE                   (1u)
#define CapSense_BTNLOCK_ON_DEBOUNCE_PARAM_ID               (0x6C83005Bu)

#define CapSense_BTNLOCK_LOW_BSLN_RST_VALUE                 (CapSense_dsRam.wdgtList.btnlock.lowBslnRst)
#define CapSense_BTNLOCK_LOW_BSLN_RST_OFFSET                (92u)
#define CapSense_BTNLOCK_LOW_BSLN_RST_SIZE                  (1u)
#define CapSense_BTNLOCK_LOW_BSLN_RST_PARAM_ID              (0x6783005Cu)

#define CapSense_BTNLOCK_IDAC_MOD0_VALUE                    (CapSense_dsRam.wdgtList.btnlock.idacMod[0u])
#define CapSense_BTNLOCK_IDAC_MOD0_OFFSET                   (93u)
#define CapSense_BTNLOCK_IDAC_MOD0_SIZE                     (1u)
#define CapSense_BTNLOCK_IDAC_MOD0_PARAM_ID                 (0x4703005Du)

#define CapSense_BTNLOCK_SNS_CLK_VALUE                      (CapSense_dsRam.wdgtList.btnlock.snsClk)
#define CapSense_BTNLOCK_SNS_CLK_OFFSET                     (94u)
#define CapSense_BTNLOCK_SNS_CLK_SIZE                       (2u)
#define CapSense_BTNLOCK_SNS_CLK_PARAM_ID                   (0xA383005Eu)

#define CapSense_BTNLOCK_SNS_CLK_SOURCE_VALUE               (CapSense_dsRam.wdgtList.btnlock.snsClkSource)
#define CapSense_BTNLOCK_SNS_CLK_SOURCE_OFFSET              (96u)
#define CapSense_BTNLOCK_SNS_CLK_SOURCE_SIZE                (1u)
#define CapSense_BTNLOCK_SNS_CLK_SOURCE_PARAM_ID            (0x40830060u)

#define CapSense_BTNRO_SNS0_RAW0_VALUE                      (CapSense_dsRam.snsList.btnro[0u].raw[0u])
#define CapSense_BTNRO_SNS0_RAW0_OFFSET                     (98u)
#define CapSense_BTNRO_SNS0_RAW0_SIZE                       (2u)
#define CapSense_BTNRO_SNS0_RAW0_PARAM_ID                   (0x8C000062u)

#define CapSense_BTNRO_SNS0_BSLN0_VALUE                     (CapSense_dsRam.snsList.btnro[0u].bsln[0u])
#define CapSense_BTNRO_SNS0_BSLN0_OFFSET                    (100u)
#define CapSense_BTNRO_SNS0_BSLN0_SIZE                      (2u)
#define CapSense_BTNRO_SNS0_BSLN0_PARAM_ID                  (0x81000064u)

#define CapSense_BTNRO_SNS0_BSLN_EXT0_VALUE                 (CapSense_dsRam.snsList.btnro[0u].bslnExt[0u])
#define CapSense_BTNRO_SNS0_BSLN_EXT0_OFFSET                (102u)
#define CapSense_BTNRO_SNS0_BSLN_EXT0_SIZE                  (1u)
#define CapSense_BTNRO_SNS0_BSLN_EXT0_PARAM_ID              (0x45000066u)

#define CapSense_BTNRO_SNS0_DIFF_VALUE                      (CapSense_dsRam.snsList.btnro[0u].diff)
#define CapSense_BTNRO_SNS0_DIFF_OFFSET                     (104u)
#define CapSense_BTNRO_SNS0_DIFF_SIZE                       (2u)
#define CapSense_BTNRO_SNS0_DIFF_PARAM_ID                   (0x82000068u)

#define CapSense_BTNRO_SNS0_NEG_BSLN_RST_CNT0_VALUE         (CapSense_dsRam.snsList.btnro[0u].negBslnRstCnt[0u])
#define CapSense_BTNRO_SNS0_NEG_BSLN_RST_CNT0_OFFSET        (106u)
#define CapSense_BTNRO_SNS0_NEG_BSLN_RST_CNT0_SIZE          (1u)
#define CapSense_BTNRO_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID      (0x4600006Au)

#define CapSense_BTNRO_SNS0_IDAC_COMP0_VALUE                (CapSense_dsRam.snsList.btnro[0u].idacComp[0u])
#define CapSense_BTNRO_SNS0_IDAC_COMP0_OFFSET               (107u)
#define CapSense_BTNRO_SNS0_IDAC_COMP0_SIZE                 (1u)
#define CapSense_BTNRO_SNS0_IDAC_COMP0_PARAM_ID             (0x4000006Bu)

#define CapSense_BTNCOLD_SNS0_RAW0_VALUE                    (CapSense_dsRam.snsList.btncold[0u].raw[0u])
#define CapSense_BTNCOLD_SNS0_RAW0_OFFSET                   (108u)
#define CapSense_BTNCOLD_SNS0_RAW0_SIZE                     (2u)
#define CapSense_BTNCOLD_SNS0_RAW0_PARAM_ID                 (0x8300006Cu)

#define CapSense_BTNCOLD_SNS0_BSLN0_VALUE                   (CapSense_dsRam.snsList.btncold[0u].bsln[0u])
#define CapSense_BTNCOLD_SNS0_BSLN0_OFFSET                  (110u)
#define CapSense_BTNCOLD_SNS0_BSLN0_SIZE                    (2u)
#define CapSense_BTNCOLD_SNS0_BSLN0_PARAM_ID                (0x8F00006Eu)

#define CapSense_BTNCOLD_SNS0_BSLN_EXT0_VALUE               (CapSense_dsRam.snsList.btncold[0u].bslnExt[0u])
#define CapSense_BTNCOLD_SNS0_BSLN_EXT0_OFFSET              (112u)
#define CapSense_BTNCOLD_SNS0_BSLN_EXT0_SIZE                (1u)
#define CapSense_BTNCOLD_SNS0_BSLN_EXT0_PARAM_ID            (0x4D000070u)

#define CapSense_BTNCOLD_SNS0_DIFF_VALUE                    (CapSense_dsRam.snsList.btncold[0u].diff)
#define CapSense_BTNCOLD_SNS0_DIFF_OFFSET                   (114u)
#define CapSense_BTNCOLD_SNS0_DIFF_SIZE                     (2u)
#define CapSense_BTNCOLD_SNS0_DIFF_PARAM_ID                 (0x89000072u)

#define CapSense_BTNCOLD_SNS0_NEG_BSLN_RST_CNT0_VALUE       (CapSense_dsRam.snsList.btncold[0u].negBslnRstCnt[0u])
#define CapSense_BTNCOLD_SNS0_NEG_BSLN_RST_CNT0_OFFSET      (116u)
#define CapSense_BTNCOLD_SNS0_NEG_BSLN_RST_CNT0_SIZE        (1u)
#define CapSense_BTNCOLD_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID    (0x4C000074u)

#define CapSense_BTNCOLD_SNS0_IDAC_COMP0_VALUE              (CapSense_dsRam.snsList.btncold[0u].idacComp[0u])
#define CapSense_BTNCOLD_SNS0_IDAC_COMP0_OFFSET             (117u)
#define CapSense_BTNCOLD_SNS0_IDAC_COMP0_SIZE               (1u)
#define CapSense_BTNCOLD_SNS0_IDAC_COMP0_PARAM_ID           (0x4A000075u)

#define CapSense_BTNHOT_SNS0_RAW0_VALUE                     (CapSense_dsRam.snsList.btnhot[0u].raw[0u])
#define CapSense_BTNHOT_SNS0_RAW0_OFFSET                    (118u)
#define CapSense_BTNHOT_SNS0_RAW0_SIZE                      (2u)
#define CapSense_BTNHOT_SNS0_RAW0_PARAM_ID                  (0x88000076u)

#define CapSense_BTNHOT_SNS0_BSLN0_VALUE                    (CapSense_dsRam.snsList.btnhot[0u].bsln[0u])
#define CapSense_BTNHOT_SNS0_BSLN0_OFFSET                   (120u)
#define CapSense_BTNHOT_SNS0_BSLN0_SIZE                     (2u)
#define CapSense_BTNHOT_SNS0_BSLN0_PARAM_ID                 (0x87000078u)

#define CapSense_BTNHOT_SNS0_BSLN_EXT0_VALUE                (CapSense_dsRam.snsList.btnhot[0u].bslnExt[0u])
#define CapSense_BTNHOT_SNS0_BSLN_EXT0_OFFSET               (122u)
#define CapSense_BTNHOT_SNS0_BSLN_EXT0_SIZE                 (1u)
#define CapSense_BTNHOT_SNS0_BSLN_EXT0_PARAM_ID             (0x4300007Au)

#define CapSense_BTNHOT_SNS0_DIFF_VALUE                     (CapSense_dsRam.snsList.btnhot[0u].diff)
#define CapSense_BTNHOT_SNS0_DIFF_OFFSET                    (124u)
#define CapSense_BTNHOT_SNS0_DIFF_SIZE                      (2u)
#define CapSense_BTNHOT_SNS0_DIFF_PARAM_ID                  (0x8600007Cu)

#define CapSense_BTNHOT_SNS0_NEG_BSLN_RST_CNT0_VALUE        (CapSense_dsRam.snsList.btnhot[0u].negBslnRstCnt[0u])
#define CapSense_BTNHOT_SNS0_NEG_BSLN_RST_CNT0_OFFSET       (126u)
#define CapSense_BTNHOT_SNS0_NEG_BSLN_RST_CNT0_SIZE         (1u)
#define CapSense_BTNHOT_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID     (0x4200007Eu)

#define CapSense_BTNHOT_SNS0_IDAC_COMP0_VALUE               (CapSense_dsRam.snsList.btnhot[0u].idacComp[0u])
#define CapSense_BTNHOT_SNS0_IDAC_COMP0_OFFSET              (127u)
#define CapSense_BTNHOT_SNS0_IDAC_COMP0_SIZE                (1u)
#define CapSense_BTNHOT_SNS0_IDAC_COMP0_PARAM_ID            (0x4400007Fu)

#define CapSense_BTNLOCK_SNS0_RAW0_VALUE                    (CapSense_dsRam.snsList.btnlock[0u].raw[0u])
#define CapSense_BTNLOCK_SNS0_RAW0_OFFSET                   (128u)
#define CapSense_BTNLOCK_SNS0_RAW0_SIZE                     (2u)
#define CapSense_BTNLOCK_SNS0_RAW0_PARAM_ID                 (0x84000080u)

#define CapSense_BTNLOCK_SNS0_BSLN0_VALUE                   (CapSense_dsRam.snsList.btnlock[0u].bsln[0u])
#define CapSense_BTNLOCK_SNS0_BSLN0_OFFSET                  (130u)
#define CapSense_BTNLOCK_SNS0_BSLN0_SIZE                    (2u)
#define CapSense_BTNLOCK_SNS0_BSLN0_PARAM_ID                (0x88000082u)

#define CapSense_BTNLOCK_SNS0_BSLN_EXT0_VALUE               (CapSense_dsRam.snsList.btnlock[0u].bslnExt[0u])
#define CapSense_BTNLOCK_SNS0_BSLN_EXT0_OFFSET              (132u)
#define CapSense_BTNLOCK_SNS0_BSLN_EXT0_SIZE                (1u)
#define CapSense_BTNLOCK_SNS0_BSLN_EXT0_PARAM_ID            (0x4D000084u)

#define CapSense_BTNLOCK_SNS0_DIFF_VALUE                    (CapSense_dsRam.snsList.btnlock[0u].diff)
#define CapSense_BTNLOCK_SNS0_DIFF_OFFSET                   (134u)
#define CapSense_BTNLOCK_SNS0_DIFF_SIZE                     (2u)
#define CapSense_BTNLOCK_SNS0_DIFF_PARAM_ID                 (0x89000086u)

#define CapSense_BTNLOCK_SNS0_NEG_BSLN_RST_CNT0_VALUE       (CapSense_dsRam.snsList.btnlock[0u].negBslnRstCnt[0u])
#define CapSense_BTNLOCK_SNS0_NEG_BSLN_RST_CNT0_OFFSET      (136u)
#define CapSense_BTNLOCK_SNS0_NEG_BSLN_RST_CNT0_SIZE        (1u)
#define CapSense_BTNLOCK_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID    (0x4E000088u)

#define CapSense_BTNLOCK_SNS0_IDAC_COMP0_VALUE              (CapSense_dsRam.snsList.btnlock[0u].idacComp[0u])
#define CapSense_BTNLOCK_SNS0_IDAC_COMP0_OFFSET             (137u)
#define CapSense_BTNLOCK_SNS0_IDAC_COMP0_SIZE               (1u)
#define CapSense_BTNLOCK_SNS0_IDAC_COMP0_PARAM_ID           (0x48000089u)

#define CapSense_SNR_TEST_WIDGET_ID_VALUE                   (CapSense_dsRam.snrTestWidgetId)
#define CapSense_SNR_TEST_WIDGET_ID_OFFSET                  (138u)
#define CapSense_SNR_TEST_WIDGET_ID_SIZE                    (1u)
#define CapSense_SNR_TEST_WIDGET_ID_PARAM_ID                (0x6900008Au)

#define CapSense_SNR_TEST_SENSOR_ID_VALUE                   (CapSense_dsRam.snrTestSensorId)
#define CapSense_SNR_TEST_SENSOR_ID_OFFSET                  (139u)
#define CapSense_SNR_TEST_SENSOR_ID_SIZE                    (1u)
#define CapSense_SNR_TEST_SENSOR_ID_PARAM_ID                (0x6F00008Bu)

#define CapSense_SNR_TEST_SCAN_COUNTER_VALUE                (CapSense_dsRam.snrTestScanCounter)
#define CapSense_SNR_TEST_SCAN_COUNTER_OFFSET               (140u)
#define CapSense_SNR_TEST_SCAN_COUNTER_SIZE                 (2u)
#define CapSense_SNR_TEST_SCAN_COUNTER_PARAM_ID             (0x8700008Cu)

#define CapSense_SNR_TEST_RAW_COUNT0_VALUE                  (CapSense_dsRam.snrTestRawCount[0u])
#define CapSense_SNR_TEST_RAW_COUNT0_OFFSET                 (142u)
#define CapSense_SNR_TEST_RAW_COUNT0_SIZE                   (2u)
#define CapSense_SNR_TEST_RAW_COUNT0_PARAM_ID               (0x8B00008Eu)


/*****************************************************************************/
/* Flash Data structure register definitions                                 */
/*****************************************************************************/
#define CapSense_BTNRO_PTR2SNS_FLASH_VALUE                  (CapSense_dsFlash.wdgtArray[0].ptr2SnsFlash)
#define CapSense_BTNRO_PTR2SNS_FLASH_OFFSET                 (0u)
#define CapSense_BTNRO_PTR2SNS_FLASH_SIZE                   (4u)
#define CapSense_BTNRO_PTR2SNS_FLASH_PARAM_ID               (0xD1000000u)

#define CapSense_BTNRO_PTR2WD_RAM_VALUE                     (CapSense_dsFlash.wdgtArray[0].ptr2WdgtRam)
#define CapSense_BTNRO_PTR2WD_RAM_OFFSET                    (4u)
#define CapSense_BTNRO_PTR2WD_RAM_SIZE                      (4u)
#define CapSense_BTNRO_PTR2WD_RAM_PARAM_ID                  (0xD0000004u)

#define CapSense_BTNRO_PTR2SNS_RAM_VALUE                    (CapSense_dsFlash.wdgtArray[0].ptr2SnsRam)
#define CapSense_BTNRO_PTR2SNS_RAM_OFFSET                   (8u)
#define CapSense_BTNRO_PTR2SNS_RAM_SIZE                     (4u)
#define CapSense_BTNRO_PTR2SNS_RAM_PARAM_ID                 (0xD3000008u)

#define CapSense_BTNRO_PTR2FLTR_HISTORY_VALUE               (CapSense_dsFlash.wdgtArray[0].ptr2FltrHistory)
#define CapSense_BTNRO_PTR2FLTR_HISTORY_OFFSET              (12u)
#define CapSense_BTNRO_PTR2FLTR_HISTORY_SIZE                (4u)
#define CapSense_BTNRO_PTR2FLTR_HISTORY_PARAM_ID            (0xD200000Cu)

#define CapSense_BTNRO_PTR2DEBOUNCE_VALUE                   (CapSense_dsFlash.wdgtArray[0].ptr2DebounceArr)
#define CapSense_BTNRO_PTR2DEBOUNCE_OFFSET                  (16u)
#define CapSense_BTNRO_PTR2DEBOUNCE_SIZE                    (4u)
#define CapSense_BTNRO_PTR2DEBOUNCE_PARAM_ID                (0xD4000010u)

#define CapSense_BTNRO_STATIC_CONFIG_VALUE                  (CapSense_dsFlash.wdgtArray[0].staticConfig)
#define CapSense_BTNRO_STATIC_CONFIG_OFFSET                 (20u)
#define CapSense_BTNRO_STATIC_CONFIG_SIZE                   (4u)
#define CapSense_BTNRO_STATIC_CONFIG_PARAM_ID               (0xD5000014u)

#define CapSense_BTNRO_TOTAL_NUM_SNS_VALUE                  (CapSense_dsFlash.wdgtArray[0].totalNumSns)
#define CapSense_BTNRO_TOTAL_NUM_SNS_OFFSET                 (24u)
#define CapSense_BTNRO_TOTAL_NUM_SNS_SIZE                   (2u)
#define CapSense_BTNRO_TOTAL_NUM_SNS_PARAM_ID               (0x99000018u)

#define CapSense_BTNRO_TYPE_VALUE                           (CapSense_dsFlash.wdgtArray[0].wdgtType)
#define CapSense_BTNRO_TYPE_OFFSET                          (26u)
#define CapSense_BTNRO_TYPE_SIZE                            (1u)
#define CapSense_BTNRO_TYPE_PARAM_ID                        (0x5D00001Au)

#define CapSense_BTNRO_NUM_COLS_VALUE                       (CapSense_dsFlash.wdgtArray[0].numCols)
#define CapSense_BTNRO_NUM_COLS_OFFSET                      (27u)
#define CapSense_BTNRO_NUM_COLS_SIZE                        (1u)
#define CapSense_BTNRO_NUM_COLS_PARAM_ID                    (0x5B00001Bu)

#define CapSense_BTNCOLD_PTR2SNS_FLASH_VALUE                (CapSense_dsFlash.wdgtArray[1].ptr2SnsFlash)
#define CapSense_BTNCOLD_PTR2SNS_FLASH_OFFSET               (28u)
#define CapSense_BTNCOLD_PTR2SNS_FLASH_SIZE                 (4u)
#define CapSense_BTNCOLD_PTR2SNS_FLASH_PARAM_ID             (0xD401001Cu)

#define CapSense_BTNCOLD_PTR2WD_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[1].ptr2WdgtRam)
#define CapSense_BTNCOLD_PTR2WD_RAM_OFFSET                  (32u)
#define CapSense_BTNCOLD_PTR2WD_RAM_SIZE                    (4u)
#define CapSense_BTNCOLD_PTR2WD_RAM_PARAM_ID                (0xD8010020u)

#define CapSense_BTNCOLD_PTR2SNS_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[1].ptr2SnsRam)
#define CapSense_BTNCOLD_PTR2SNS_RAM_OFFSET                 (36u)
#define CapSense_BTNCOLD_PTR2SNS_RAM_SIZE                   (4u)
#define CapSense_BTNCOLD_PTR2SNS_RAM_PARAM_ID               (0xD9010024u)

#define CapSense_BTNCOLD_PTR2FLTR_HISTORY_VALUE             (CapSense_dsFlash.wdgtArray[1].ptr2FltrHistory)
#define CapSense_BTNCOLD_PTR2FLTR_HISTORY_OFFSET            (40u)
#define CapSense_BTNCOLD_PTR2FLTR_HISTORY_SIZE              (4u)
#define CapSense_BTNCOLD_PTR2FLTR_HISTORY_PARAM_ID          (0xDA010028u)

#define CapSense_BTNCOLD_PTR2DEBOUNCE_VALUE                 (CapSense_dsFlash.wdgtArray[1].ptr2DebounceArr)
#define CapSense_BTNCOLD_PTR2DEBOUNCE_OFFSET                (44u)
#define CapSense_BTNCOLD_PTR2DEBOUNCE_SIZE                  (4u)
#define CapSense_BTNCOLD_PTR2DEBOUNCE_PARAM_ID              (0xDB01002Cu)

#define CapSense_BTNCOLD_STATIC_CONFIG_VALUE                (CapSense_dsFlash.wdgtArray[1].staticConfig)
#define CapSense_BTNCOLD_STATIC_CONFIG_OFFSET               (48u)
#define CapSense_BTNCOLD_STATIC_CONFIG_SIZE                 (4u)
#define CapSense_BTNCOLD_STATIC_CONFIG_PARAM_ID             (0xDD010030u)

#define CapSense_BTNCOLD_TOTAL_NUM_SNS_VALUE                (CapSense_dsFlash.wdgtArray[1].totalNumSns)
#define CapSense_BTNCOLD_TOTAL_NUM_SNS_OFFSET               (52u)
#define CapSense_BTNCOLD_TOTAL_NUM_SNS_SIZE                 (2u)
#define CapSense_BTNCOLD_TOTAL_NUM_SNS_PARAM_ID             (0x93010034u)

#define CapSense_BTNCOLD_TYPE_VALUE                         (CapSense_dsFlash.wdgtArray[1].wdgtType)
#define CapSense_BTNCOLD_TYPE_OFFSET                        (54u)
#define CapSense_BTNCOLD_TYPE_SIZE                          (1u)
#define CapSense_BTNCOLD_TYPE_PARAM_ID                      (0x57010036u)

#define CapSense_BTNCOLD_NUM_COLS_VALUE                     (CapSense_dsFlash.wdgtArray[1].numCols)
#define CapSense_BTNCOLD_NUM_COLS_OFFSET                    (55u)
#define CapSense_BTNCOLD_NUM_COLS_SIZE                      (1u)
#define CapSense_BTNCOLD_NUM_COLS_PARAM_ID                  (0x51010037u)

#define CapSense_BTNHOT_PTR2SNS_FLASH_VALUE                 (CapSense_dsFlash.wdgtArray[2].ptr2SnsFlash)
#define CapSense_BTNHOT_PTR2SNS_FLASH_OFFSET                (56u)
#define CapSense_BTNHOT_PTR2SNS_FLASH_SIZE                  (4u)
#define CapSense_BTNHOT_PTR2SNS_FLASH_PARAM_ID              (0xDA020038u)

#define CapSense_BTNHOT_PTR2WD_RAM_VALUE                    (CapSense_dsFlash.wdgtArray[2].ptr2WdgtRam)
#define CapSense_BTNHOT_PTR2WD_RAM_OFFSET                   (60u)
#define CapSense_BTNHOT_PTR2WD_RAM_SIZE                     (4u)
#define CapSense_BTNHOT_PTR2WD_RAM_PARAM_ID                 (0xDB02003Cu)

#define CapSense_BTNHOT_PTR2SNS_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[2].ptr2SnsRam)
#define CapSense_BTNHOT_PTR2SNS_RAM_OFFSET                  (64u)
#define CapSense_BTNHOT_PTR2SNS_RAM_SIZE                    (4u)
#define CapSense_BTNHOT_PTR2SNS_RAM_PARAM_ID                (0xDA020040u)

#define CapSense_BTNHOT_PTR2FLTR_HISTORY_VALUE              (CapSense_dsFlash.wdgtArray[2].ptr2FltrHistory)
#define CapSense_BTNHOT_PTR2FLTR_HISTORY_OFFSET             (68u)
#define CapSense_BTNHOT_PTR2FLTR_HISTORY_SIZE               (4u)
#define CapSense_BTNHOT_PTR2FLTR_HISTORY_PARAM_ID           (0xDB020044u)

#define CapSense_BTNHOT_PTR2DEBOUNCE_VALUE                  (CapSense_dsFlash.wdgtArray[2].ptr2DebounceArr)
#define CapSense_BTNHOT_PTR2DEBOUNCE_OFFSET                 (72u)
#define CapSense_BTNHOT_PTR2DEBOUNCE_SIZE                   (4u)
#define CapSense_BTNHOT_PTR2DEBOUNCE_PARAM_ID               (0xD8020048u)

#define CapSense_BTNHOT_STATIC_CONFIG_VALUE                 (CapSense_dsFlash.wdgtArray[2].staticConfig)
#define CapSense_BTNHOT_STATIC_CONFIG_OFFSET                (76u)
#define CapSense_BTNHOT_STATIC_CONFIG_SIZE                  (4u)
#define CapSense_BTNHOT_STATIC_CONFIG_PARAM_ID              (0xD902004Cu)

#define CapSense_BTNHOT_TOTAL_NUM_SNS_VALUE                 (CapSense_dsFlash.wdgtArray[2].totalNumSns)
#define CapSense_BTNHOT_TOTAL_NUM_SNS_OFFSET                (80u)
#define CapSense_BTNHOT_TOTAL_NUM_SNS_SIZE                  (2u)
#define CapSense_BTNHOT_TOTAL_NUM_SNS_PARAM_ID              (0x90020050u)

#define CapSense_BTNHOT_TYPE_VALUE                          (CapSense_dsFlash.wdgtArray[2].wdgtType)
#define CapSense_BTNHOT_TYPE_OFFSET                         (82u)
#define CapSense_BTNHOT_TYPE_SIZE                           (1u)
#define CapSense_BTNHOT_TYPE_PARAM_ID                       (0x54020052u)

#define CapSense_BTNHOT_NUM_COLS_VALUE                      (CapSense_dsFlash.wdgtArray[2].numCols)
#define CapSense_BTNHOT_NUM_COLS_OFFSET                     (83u)
#define CapSense_BTNHOT_NUM_COLS_SIZE                       (1u)
#define CapSense_BTNHOT_NUM_COLS_PARAM_ID                   (0x52020053u)

#define CapSense_BTNLOCK_PTR2SNS_FLASH_VALUE                (CapSense_dsFlash.wdgtArray[3].ptr2SnsFlash)
#define CapSense_BTNLOCK_PTR2SNS_FLASH_OFFSET               (84u)
#define CapSense_BTNLOCK_PTR2SNS_FLASH_SIZE                 (4u)
#define CapSense_BTNLOCK_PTR2SNS_FLASH_PARAM_ID             (0xDD030054u)

#define CapSense_BTNLOCK_PTR2WD_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[3].ptr2WdgtRam)
#define CapSense_BTNLOCK_PTR2WD_RAM_OFFSET                  (88u)
#define CapSense_BTNLOCK_PTR2WD_RAM_SIZE                    (4u)
#define CapSense_BTNLOCK_PTR2WD_RAM_PARAM_ID                (0xDE030058u)

#define CapSense_BTNLOCK_PTR2SNS_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[3].ptr2SnsRam)
#define CapSense_BTNLOCK_PTR2SNS_RAM_OFFSET                 (92u)
#define CapSense_BTNLOCK_PTR2SNS_RAM_SIZE                   (4u)
#define CapSense_BTNLOCK_PTR2SNS_RAM_PARAM_ID               (0xDF03005Cu)

#define CapSense_BTNLOCK_PTR2FLTR_HISTORY_VALUE             (CapSense_dsFlash.wdgtArray[3].ptr2FltrHistory)
#define CapSense_BTNLOCK_PTR2FLTR_HISTORY_OFFSET            (96u)
#define CapSense_BTNLOCK_PTR2FLTR_HISTORY_SIZE              (4u)
#define CapSense_BTNLOCK_PTR2FLTR_HISTORY_PARAM_ID          (0xD3030060u)

#define CapSense_BTNLOCK_PTR2DEBOUNCE_VALUE                 (CapSense_dsFlash.wdgtArray[3].ptr2DebounceArr)
#define CapSense_BTNLOCK_PTR2DEBOUNCE_OFFSET                (100u)
#define CapSense_BTNLOCK_PTR2DEBOUNCE_SIZE                  (4u)
#define CapSense_BTNLOCK_PTR2DEBOUNCE_PARAM_ID              (0xD2030064u)

#define CapSense_BTNLOCK_STATIC_CONFIG_VALUE                (CapSense_dsFlash.wdgtArray[3].staticConfig)
#define CapSense_BTNLOCK_STATIC_CONFIG_OFFSET               (104u)
#define CapSense_BTNLOCK_STATIC_CONFIG_SIZE                 (4u)
#define CapSense_BTNLOCK_STATIC_CONFIG_PARAM_ID             (0xD1030068u)

#define CapSense_BTNLOCK_TOTAL_NUM_SNS_VALUE                (CapSense_dsFlash.wdgtArray[3].totalNumSns)
#define CapSense_BTNLOCK_TOTAL_NUM_SNS_OFFSET               (108u)
#define CapSense_BTNLOCK_TOTAL_NUM_SNS_SIZE                 (2u)
#define CapSense_BTNLOCK_TOTAL_NUM_SNS_PARAM_ID             (0x9F03006Cu)

#define CapSense_BTNLOCK_TYPE_VALUE                         (CapSense_dsFlash.wdgtArray[3].wdgtType)
#define CapSense_BTNLOCK_TYPE_OFFSET                        (110u)
#define CapSense_BTNLOCK_TYPE_SIZE                          (1u)
#define CapSense_BTNLOCK_TYPE_PARAM_ID                      (0x5B03006Eu)

#define CapSense_BTNLOCK_NUM_COLS_VALUE                     (CapSense_dsFlash.wdgtArray[3].numCols)
#define CapSense_BTNLOCK_NUM_COLS_OFFSET                    (111u)
#define CapSense_BTNLOCK_NUM_COLS_SIZE                      (1u)
#define CapSense_BTNLOCK_NUM_COLS_PARAM_ID                  (0x5D03006Fu)


#endif /* End CY_SENSE_CapSense_REGISTER_MAP_H */


/* [] END OF FILE */
