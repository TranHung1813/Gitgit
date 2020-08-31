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
#ifndef _SYS_H
#define _SYS_H
#include "myHeader.h"
 
void Sys_init(void);    
void Sys_touchPress(uint8_t btnId);
void Sys_touchShortPress(uint8_t btnId);
void Sys_touchHold(uint8_t btnId);
void Sys_RoColdHold(uint8_t btnId);
void Sys_process(void);
#endif    
/* [] END OF FILE */
