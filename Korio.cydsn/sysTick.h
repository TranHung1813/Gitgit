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
#ifndef _SYSTICK_H
#define _SYSTICK_H
#include "myHeader.h"

extern uint32_t g_SysTime;

void SYSTICK_regSysTickISRCallback(void *func);
uint32_t elapstime(uint32_t newTime, uint32_t oldTime);    
#endif    
/* [] END OF FILE */
