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
#include "sysTick.h"

uint32_t g_SysTime;

void SYSTICK_regSysTickISRCallback(void *func)
{
    CySysTickStart();
    /* Find unused callback slot and assign the callback. */
    for(uint8_t i = 0u; i < CY_SYS_SYST_NUM_OF_CALLBACKS; ++i)
    {
        if (CySysTickGetCallback(i) == NULL)
        {
            /* Set callback */
            CySysTickSetCallback(i, func);
            break;
        }
    }
}

uint32_t elapstime(uint32_t newTime, uint32_t oldTime)
{
    return (newTime - oldTime);
}
/* [] END OF FILE */
