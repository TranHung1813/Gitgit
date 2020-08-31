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
#include "sys.h"
#define IGNORE_ALL_LED 1

#define THOI_GIAN_TU_KHOA  (30000)   //30s
#define THOI_GIAN_CHO_NUOC (3*60000) // 3p
static struct ledStatus_t
{
    uint8_t ro;
    uint8_t cold;
    uint8_t hot;
    uint8_t lock;
} ledStt = {LED_RESET, LED_RESET, LED_RESET, LED_SET};

static uint8_t lockStatus = LOCK;
static bool dangLayNuoc = false;
static uint32_t thoiGianLayNuoc = 0;
static uint32_t thoiGianChoKhoaPhim = 0;
static bool autoLock = false;

volatile bool enteringTestMode = false;

static void Beep(void)
{
    BUZZ_ON;
    CyDelay(100);
    BUZZ_OFF;
}

static bool ledLOCKIsBlink = false;
static bool lockBlinkOnOff = false;
static uint32_t ledLOCKBinkTime = 0;
static void ledLOCKBlinkProcess(void)
{
    if(ledLOCKIsBlink && elapstime(g_SysTime, ledLOCKBinkTime) > 1000)
    {
        if(lockBlinkOnOff == false) { LED_LOCK_ON; lockBlinkOnOff = true; }     
        else { LED_LOCK_OFF; lockBlinkOnOff = false; }            
        ledLOCKBinkTime = g_SysTime;
    }
}

static void enableTestInd(void)
{
    ledLOCKIsBlink = true;
    ledLOCKBinkTime = g_SysTime;
}

static void disableTestInd(void)
{
    ledLOCKIsBlink = false;
    LED_LOCK_ON;
}

static bool ledHOTIsBlink = false;
static bool hotBlinkOnOff = false;
static uint32_t ledHOTBinkTime = 0;
static void ledHOTBlinkProcess(void)
{
    if(ledHOTIsBlink && elapstime(g_SysTime, ledHOTBinkTime) > 300)
    {
        if(hotBlinkOnOff == false) { LED_HOT_ON; hotBlinkOnOff = true; }     
        else { LED_HOT_OFF; hotBlinkOnOff = false; }            
        ledHOTBinkTime = g_SysTime;
    }
}

static bool ledROIsBlink = false;
static bool roBlinkOnOff = false;
static uint32_t ledROBinkTime = 0;
static void ledROBlinkProcess(void)
{
    if(ledROIsBlink && elapstime(g_SysTime, ledROBinkTime) > 300)
    {
        if(roBlinkOnOff == false) { LED_RO_ON; roBlinkOnOff = true; }
        else { LED_RO_OFF; roBlinkOnOff = false; }
        ledROBinkTime = g_SysTime;
    }
}

static bool ledCOLDIsBlink = false;
static bool coldBlinkOnOff = false;
static uint32_t ledCOLDBinkTime = 0;
static void ledCOLDBlinkProcess(void)
{
    if(ledCOLDIsBlink && elapstime(g_SysTime, ledCOLDBinkTime) > 300)
    {
        if(coldBlinkOnOff == false) { LED_COLD_ON; coldBlinkOnOff = true; }
        else { LED_COLD_OFF; coldBlinkOnOff = false;}              
        ledCOLDBinkTime = g_SysTime;
    }
}

static void ledBlinkProcess(void)
{
    ledLOCKBlinkProcess();
    ledHOTBlinkProcess();
    ledROBlinkProcess();
    ledCOLDBlinkProcess();
}

static void Lay_nuoc_RO(void)
{
    dangLayNuoc = true;
    thoiGianLayNuoc = g_SysTime;
    VL1_ON;
    VL2_OFF;
    VL3_OFF;
    ledROIsBlink = true;
    ledROBinkTime = g_SysTime;
//    thoiGianChoKhoaPhim = g_SysTime;
}

static void Lay_nuoc_COLD(void)
{    
    dangLayNuoc = true;
    thoiGianLayNuoc = g_SysTime;
    VL1_OFF;
    VL2_ON;
    VL3_OFF;
    ledCOLDIsBlink = true;
    ledCOLDBinkTime = g_SysTime;
//    thoiGianChoKhoaPhim = g_SysTime;
}

static void Lay_nuoc_HOT(void)
{
    dangLayNuoc = true;
    thoiGianLayNuoc = g_SysTime;
    VL1_OFF;
    VL2_OFF;
    VL3_ON;
    ledHOTIsBlink = true;
    ledHOTBinkTime = g_SysTime;
    autoLock = false;
}

static void SwitchState(uint8_t status)
{
    if(status == LOCK)
    {
        LOG_INFO("switch to lock\n");
//        LED_RO_OFF;    
//        LED_COLD_OFF;
//        LED_HOT_OFF;
//#if (IGNORE_ALL_LED==0)
        LED_LOCK_ON;
//#endif
//    if(MODE_TEST == false) LED_LOCK_OFF;
//        ledStt.ro = ledStt.cold = ledStt.hot = LED_RESET;
        ledStt.lock = LED_SET;      
        autoLock = false;
    }
    else if(status == UNLOCK)
    {
//#if (IGNORE_ALL_LED==0)       
        LED_LOCK_OFF;
//#endif
//    if(MODE_TEST == true) LED_LOCK_OFF;
        ledStt.lock = LED_RESET;
        LOG_INFO("switch to unlock\n");
        thoiGianChoKhoaPhim = g_SysTime;
        autoLock = true;
    }
    lockStatus = status;
}

static void Dung_lay_nuoc(void)
{
#if (IGNORE_ALL_LED==0)
    LED_RO_OFF;             
    LED_COLD_OFF;
    LED_HOT_OFF;
#endif
    if(MODE_TEST == true)
    {
        LED_RO_OFF;             
        LED_COLD_OFF;
        LED_HOT_OFF;
    }
    dangLayNuoc = false;
    
    VL1_OFF;
    VL2_OFF;
    VL3_OFF;
    if(ledHOTIsBlink) 
    {
        thoiGianChoKhoaPhim = g_SysTime;
        autoLock = true;
    }
    ledHOTIsBlink = ledCOLDIsBlink = ledROIsBlink = false;
}

void Sys_init(void)
{
//    PWM_Start();
//    PWM_WritePeriod(6000); // clock 12MHz -> PWM 2kHz
//    PWM_WriteCompare(1500); // duty 25%
    enteringTestMode = false;
    MODE_TEST = false;
    LED_LOCK_OFF;
    LED_RO_OFF;    
    LED_COLD_OFF;
    LED_HOT_OFF;
    SwitchState(LOCK);
    Dung_lay_nuoc();
}

void Sys_touchPress(uint8_t btnId)
{
//    if(lockStatus == LOCK)
//    {
//        if(btnId == BTN_LOCK || btnId == BTN_COLD || btnId == BTN_RO)
//        {
//            thoiGianChoKhoaPhim = g_SysTime;
//        }
//    }
//    else if(lockStatus == UNLOCK)
//    {
//        thoiGianChoKhoaPhim = g_SysTime;        
//    }
    
    if(dangLayNuoc) 
    {
        Dung_lay_nuoc();
        Beep();
    }
    else
    {
        if(lockStatus == UNLOCK)
        {
            if(btnId == BTN_RO)
            {           
                Beep();
                Lay_nuoc_RO();
            }
            else if(btnId == BTN_COLD)
            {
                Beep();
                Lay_nuoc_COLD();
            }
            else if(btnId == BTN_HOT)
            {
                Beep();
                Lay_nuoc_HOT();                
            }
        }
    } 
}

void Sys_touchShortPress(uint8_t btnId)
{
    uint8_t id = btnId;
    if(enteringTestMode) 
    {
        if(btnId == BTN_LOCK) 
        {
            enteringTestMode = false;
            if(MODE_TEST == false){
                MODE_TEST = true;
                SwitchState(UNLOCK);
                enableTestInd();
                LOG_INFO("-->TestMode: running\r\n");
            } else{
                MODE_TEST = false;
                SwitchState(LOCK);
                disableTestInd();
                LOG_INFO("-->TestMode: EXIT\r\n");
            }
        }
    }
}

void Sys_touchHold(uint8_t btnId)
{
    if(enteringTestMode == false)
    {
        if(btnId == BTN_LOCK && MODE_TEST == false) 
        {
            Beep();
            if(lockStatus == LOCK) SwitchState(UNLOCK);
            else SwitchState(LOCK);        
        }
        else if(btnId == BTN_HOT)
        {
            Beep();
            CyDelay(100);
            Beep();
            enteringTestMode = true;
            LOG_INFO("-->enteringTestMode\r\n");
        }
    }
}

void Sys_RoColdHold(uint8_t btnId)
{
    if(enteringTestMode == false)
    {
        if(lockStatus == LOCK)
        {
            
    //        SwitchState(UNLOCK);
            if(btnId == BTN_RO) 
            {
                Beep();
                Dung_lay_nuoc();
                Lay_nuoc_RO();
            }
            else if(btnId == BTN_COLD) 
            {
                Beep();
                Dung_lay_nuoc();
                Lay_nuoc_COLD();
            }
        }
    }
}

static void KiemTra_dungLayNuoc(void)
{
    if(dangLayNuoc == true && (elapstime(g_SysTime, thoiGianLayNuoc) > THOI_GIAN_CHO_NUOC))
    {
        Dung_lay_nuoc();
    }
}

static void KiemTra_tuKhoaPhim(void)
{
    if(lockStatus == UNLOCK)
    {
        if(autoLock && elapstime(g_SysTime, thoiGianChoKhoaPhim) > THOI_GIAN_TU_KHOA)
        {
            SwitchState(LOCK);   
            if(dangLayNuoc == false) Beep();
        }
    }
}

void Sys_process(void)
{
    if(MODE_TEST == false)
    {
        KiemTra_dungLayNuoc();
        KiemTra_tuKhoaPhim();
#if (IGNORE_ALL_LED==0)
    ledBlinkProcess();
#endif    
    } 
    else ledBlinkProcess();
}
/* [] END OF FILE */
