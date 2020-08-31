/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef _MYHEADER_H
#define _MYHEADER_H
#include "project.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "softDebug.h"
#include "sysTick.h"
#include "sys.h"
#include "touchBtn_ADC.h"
typedef enum
{
    LED_SET = 0,
    LED_RESET = 1,
} Led_value;

typedef enum
{
    VLx_SET = 1,
    VLx_RESET = 0,
} VLx_value;

typedef enum
{
    CN1_SET = 1,
    CN1_RESET = 0,
} CN1_value;

typedef enum
{
    LOCK = 0,
    UNLOCK = 1,
} LOCK_status;

typedef enum
{
    K1_ON = 1,
    K1_OFF = 0,
} K1_status;
/* LED */
#define LED_RO_ON   LED_RO_Write(LED_SET)
#define LED_COLD_ON LED_COLD_Write(LED_SET)
#define LED_HOT_ON  LED_HOT_Write(LED_SET)
#define LED_LOCK_ON LED_LOCK_Write(LED_SET)

#define LED_RO_OFF   LED_RO_Write(LED_RESET)
#define LED_COLD_OFF LED_COLD_Write(LED_RESET)
#define LED_HOT_OFF  LED_HOT_Write(LED_RESET)
#define LED_LOCK_OFF LED_LOCK_Write(LED_RESET)
/* VLx */
#define VL1_ON  VL1_Write(VLx_SET)
#define VL2_ON  VL2_Write(VLx_SET)
#define VL3_ON  VL3_Write(VLx_SET)
//#define VL4_ON  VL4_Write(VLx_SET)
#define BUZZ_ON Buzzer_Write(1)

#define VL1_OFF  VL1_Write(VLx_RESET)
#define VL2_OFF  VL2_Write(VLx_RESET)
#define VL3_OFF  VL3_Write(VLx_RESET)
//#define VL4_OFF  VL4_Write(VLx_RESET)
#define BUZZ_OFF Buzzer_Write(0)
/* CN1 */
#define CN1_ON  CN1_Write(CN1_SET)

#define CN1_OFF  CN1_Write(CN1_RESET)

extern volatile bool MODE_TEST;
extern volatile bool enteringTestMode;
#endif
/* [] END OF FILE */
