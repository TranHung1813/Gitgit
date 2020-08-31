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
#include "touchBtn_ADC.h"

static touchBtnProfile_t touchBtn[NUM_TOUCH_BTN];
/* -------------------------------*/
static struct sensorParams_t
{
    uint16_t baseline;
    uint16_t rawData;
    uint16_t diffData;
    uint32_t startTimeDiffData;
    uint32_t stopTimeDiffData;
} sensorParams[NUM_TOUCH_BTN];
/* -------------------------------*/
static uint16_t getDataMode(modeData_t mode, uint8_t btnId)
{
    if(mode == MODE_RAW)
    {
        if(btnId == BTN_RO) return CapSense_BTNRO_SNS0_RAW0_VALUE;   
        if(btnId == BTN_COLD) return CapSense_BTNCOLD_SNS0_RAW0_VALUE;
        if(btnId == BTN_HOT) return CapSense_BTNHOT_SNS0_RAW0_VALUE;
        if(btnId == BTN_LOCK) return CapSense_BTNLOCK_SNS0_RAW0_VALUE;
    }
    
    if(mode == MODE_BASELINE)
    {
        if(btnId == BTN_RO) return CapSense_BTNRO_SNS0_BSLN0_VALUE;   
        if(btnId == BTN_COLD) return CapSense_BTNCOLD_SNS0_BSLN0_VALUE;
        if(btnId == BTN_HOT) return CapSense_BTNHOT_SNS0_BSLN0_VALUE;
        if(btnId == BTN_LOCK) return CapSense_BTNLOCK_SNS0_BSLN0_VALUE;
    }
    
    if(mode == MODE_DIF)
    {
        if(btnId == BTN_RO) return CapSense_BTNRO_SNS0_DIFF_VALUE;   
        if(btnId == BTN_COLD) return CapSense_BTNCOLD_SNS0_DIFF_VALUE;
        if(btnId == BTN_HOT) return CapSense_BTNHOT_SNS0_DIFF_VALUE;
        if(btnId == BTN_LOCK) return CapSense_BTNLOCK_SNS0_DIFF_VALUE;
    }
    return 0xFFFF;
}
/* -------------------------------*/
void Touch_init(void)
{
    CapSense_Start();	
    CapSense_ScanAllWidgets();
    CapSense_ProcessAllWidgets();
    CyDelay(100);
	/* Initialize the baselines of all CapSense widgets. */ 
	CapSense_InitializeAllBaselines();
}

static bool startConv = false;
uint16_t mVolts = 0;
void Touch_process(void)
{
    
    if(CapSense_NOT_BUSY == CapSense_IsBusy() && CapSense_AdcIsBusy() == CapSense_AdcSTATUS_IDLE)
    {
        /* Start an ADC Conversion conversion */
        if(startConv == false)
        {
            CapSense_AdcStartConvert(CapSense_AdcCHANNEL_0);
            CapSense_ProcessAllWidgets();
            startConv = true;
        }
        else if(startConv)
        {
            mVolts = CapSense_AdcGetResult_mVolts(CapSense_AdcCHANNEL_0);
//            LOG_INFO("Dien ap: %d mV\n", mVolts);
            startConv = false;
            CapSense_ScanAllWidgets();
            CapSense_ProcessAllWidgets();
            CapSense_UpdateAllBaselines();
            for(uint8_t i = 0; i < NUM_TOUCH_BTN; i++) 
            {
                sensorParams[i].baseline = getDataMode(MODE_BASELINE, i);
                sensorParams[i].rawData  = getDataMode(MODE_RAW, i);
                sensorParams[i].diffData = getDataMode(MODE_DIF, i);
                sensorParams[i].stopTimeDiffData = g_SysTime;
                if(sensorParams[i].diffData == 0) sensorParams[i].startTimeDiffData = g_SysTime;
                else 
                {
                    if(elapstime(sensorParams[i].stopTimeDiffData, sensorParams[i].startTimeDiffData) > TOUCH_TIME_HOLDING_TIMEOUT)
                    {
                        CapSense_InitializeWidgetBaseline(i);
                        Touch_holdEvent(i, TOUCH_TIME_HOLDING_TIMEOUT);
                    }
                }
            }
            LOG_RAW("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\r\n",  
                                sensorParams[0].baseline, sensorParams[0].rawData, sensorParams[0].diffData, 
                                sensorParams[1].baseline, sensorParams[1].rawData, sensorParams[1].diffData, 
                                sensorParams[2].baseline, sensorParams[2].rawData, sensorParams[2].diffData, 
                                sensorParams[3].baseline, sensorParams[3].rawData, sensorParams[3].diffData, 
                                mVolts);
        
            for(uint8_t i = 0; i < NUM_TOUCH_BTN; i++)
            {             
                touchBtn[i].btnActive = CapSense_IsWidgetActive(i);
                touchBtn[i].timeTotalPress = elapstime(g_SysTime, touchBtn[i].timeStartPress);
                
                switch(touchBtn[i].state)
                {
                    case TOUCH_BTN_RELEASE:
                        if(touchBtn[i].btnActive == TOUCH_BTN_ACTIVE)
                        {
                            touchBtn[i].timeStartPress = g_SysTime;
                            touchBtn[i].state = TOUCH_BTN_PRESS;
                            /*-------------------------------*/
                            /*   call press event btn */
                            Touch_pressEvent(i);
                        }
                        break;
                    case TOUCH_BTN_PRESS:
                        if(touchBtn[i].timeTotalPress > TOUCH_TIME_HOLDING1)
                        {
                            touchBtn[i].state = TOUCH_BTN_HOLDING1;
                            /*-------------------------------*/
                            /*   call hoding1 event btn */
                            Touch_holdEvent(i, TOUCH_TIME_HOLDING1);
                        }
                        break;
                    case TOUCH_BTN_HOLDING1:
                        if(touchBtn[i].timeTotalPress > TOUCH_TIME_HOLDING2)
                        {
                            touchBtn[i].state = TOUCH_BTN_HOLDING2;
                            /*-------------------------------*/
                            /*   call hoding1 event btn */
                            Touch_holdEvent(i, TOUCH_TIME_HOLDING2);
                        }
                        break;
                }
                
                if(touchBtn[i].state != TOUCH_BTN_RELEASE)
                {
                    if(touchBtn[i].btnActive == TOUCH_BTN_INACTIVE)
                    {   
                        touchBtn[i].state = TOUCH_BTN_RELEASE;
                        /*-------------------------------*/
                        /*   call release event btn */
                        Touch_releaseEvent(i, touchBtn[i].timeTotalPress);
                    }
                }        
            }
        }
    }
}
/* -------------------------------*/
void Touch_pressEvent(uint8_t btnId)
{
    LOG_INFO("btn %d press\r\n", btnId);
    Sys_touchPress(btnId);
}
/* -------------------------------*/
void Touch_holdEvent(uint8_t btnId, uint32_t timeHolding)
{
    LOG_INFO("btn %d hold, timeholding %d\r\n", btnId, timeHolding);
    if(timeHolding == TOUCH_TIME_HOLDING2) Sys_touchHold(btnId);
    else if(timeHolding == TOUCH_TIME_HOLDING1) Sys_RoColdHold(btnId);
}
/* -------------------------------*/
void Touch_releaseEvent(uint8_t btnId, uint32_t timeHolding)
{
    LOG_INFO("btn %d release, timeholding %d\r\n", btnId, timeHolding);
    if(timeHolding < TOUCH_TIME_HOLDING1) Sys_touchShortPress(btnId);
    if(btnId == BTN_HOT) enteringTestMode = false;
}
/* -------------------------------*/

static uint8_t coldStatus = K1_OFF;
void MF58_init(void)
{
    coldStatus = K1_OFF;
    COLD_K1_Write(K1_OFF);
}

void MF58_control(void)
{
    LOG_INFO("Dien ap: %d mV\n", mVolts);
    if(mVolts != 0xFFFF)
    {
        if(coldStatus == K1_ON && mVolts < (uint16_t)(NGUONG_DUOI+DELTA_NGUONG))
        {
            coldStatus = K1_OFF;
            COLD_K1_Write(K1_OFF);
            LOG_INFO("K1_OFF\n");
        }

        if(coldStatus == K1_OFF && mVolts > (uint16_t)(NGUONG_TREN-DELTA_NGUONG))
        {
            coldStatus = K1_ON;
            COLD_K1_Write(K1_ON);
            LOG_INFO("K1_ON\n");
        }
    }
}
/* [] END OF FILE */
