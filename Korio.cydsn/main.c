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
#include "project.h"
#include "myHeader.h"

#define MAX_SOFT_TIMER 3
static uint16_t softTimer[MAX_SOFT_TIMER] = {0};
static bool flag_systick = false;

static void systickInt(void)
{
    g_SysTime++;
    flag_systick = true;
}

volatile bool MODE_TEST = false;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */    
    Sys_init();    
    MF58_init();
    SYSTICK_regSysTickISRCallback(systickInt);
    Touch_init();    
    LOG_INFO("\r\nRunning after reset\r\n");
    for(;;)
    {
        /* Place your application code here. */
        if(flag_systick)
        {
            flag_systick = false;
            for(uint8_t i = 0; i < MAX_SOFT_TIMER; i++) softTimer[i]++;
        }
        
        if(softTimer[0] >= 10)
        {
            softTimer[0] = 0;
            Touch_process();
        }
        
        if(softTimer[1] >= 50)
        {
            softTimer[1] = 0;
            Sys_process();
        }
        
        if(MODE_TEST == false)
        {
            /* 10s dieu khien K1 */
            if(softTimer[2] >= 10000)
            {
                softTimer[2] = 0;
                MF58_control();
            }
        } else
        {
            if(softTimer[2] >= 1000)
            {
                softTimer[2] = 0;
                MF58_control();
            }
        }
    }
}

/* [] END OF FILE */
