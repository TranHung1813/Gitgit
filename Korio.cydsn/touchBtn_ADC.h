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
#ifndef _TOUCH_BTN_ADC_H
#define _TOUCH_BTN_ADC_H
#include "myHeader.h"

    /* FOR TOUCH BTN */
#define TOUCH_TIME_HOLDING1 500
#define TOUCH_TIME_HOLDING2 2000
#define TOUCH_TIME_HOLDING_TIMEOUT 5000

/* -------------------------------*/
#define NUM_TOUCH_BTN CapSense_TOTAL_SCAN_SLOTS
uint8_t myBtn[NUM_TOUCH_BTN];
#define BTN_RO   CapSense_BTNRO_WDGT_ID   //myBtn[0]
#define BTN_COLD CapSense_BTNCOLD_WDGT_ID //myBtn[1]
#define BTN_HOT  CapSense_BTNHOT_WDGT_ID  //myBtn[2]
#define BTN_LOCK CapSense_BTNLOCK_WDGT_ID //myBtn[3]
/* -------------------------------*/

typedef enum
{
    MODE_RAW = 0,
    MODE_BASELINE = 1,
    MODE_DIF = 2,
} modeData_t;

typedef enum 
{
    TOUCH_BTN_INACTIVE = 0,
    TOUCH_BTN_ACTIVE = 1
} touch_status_t;

typedef enum
{
    TOUCH_BTN_RELEASE = 0,
    TOUCH_BTN_PRESS,
    TOUCH_BTN_HOLDING1,
    TOUCH_BTN_HOLDING2,
} touch_btn_status_t;

typedef struct
{
    bool btnActive;
    uint8_t state;
    uint32_t timeStartPress;
    uint32_t timeTotalPress;
    
} touchBtnProfile_t;

void Touch_init(void);
void Touch_process(void);
void Touch_pressEvent(uint8_t btnId);
void Touch_holdEvent(uint8_t btnId, uint32_t timeHolding);
void Touch_releaseEvent(uint8_t btnId, uint32_t timeHolding);
    /* END TOUCH BTN */
/* -------------------------------*/
        /* FOR ADC */
//#define T17 14300 // < 14.3kOhm
//#define T13 17300 // > 17.28kOhm    

#define T15 15700 // < 15714 Ohm
#define T10 19400 // > 19376 Ohm

#define VREF 5000 // 5V
#define RES  10  // resolution 10bits ADC
#define RES_VALUE 1024
    
#define R49 10000 // 10kOhm    
    
#define NGUONG_TREN ((VREF*R49/(T15+R49)))
#define NGUONG_DUOI ((VREF*R49/(T10+R49)))   
#define DELTA_NGUONG (0)
void MF58_init(void);    
void MF58_control(void);
        /* END ADC */
#endif    
/* [] END OF FILE */
