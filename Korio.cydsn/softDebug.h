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
#ifndef _SOFTDEBUG_H
#define _SOFTDEBUG_H
#include "myHeader.h"
    
//#define DISABLE_DEBUG_ALL
#define DEBUG_RAW_DATA    
    
#ifndef DISABLE_DEBUG_ALL    
#ifndef DEBUG_RAW_DATA
#define LOG_INFO(string, ...) DEBUG_SW_UART(string, ##__VA_ARGS__)  
#define LOG_RAW(string, ...)    
#else    
#define LOG_INFO(string, ...)
#define LOG_RAW(string, ...) DEBUG_SW_UART(string, ##__VA_ARGS__)  
#endif
#else
#define LOG_INFO(string, ...)
#define LOG_RAW(string, ...)    
#endif
void DEBUG_SW_UART(const char *format, ...);
#endif
/* [] END OF FILE */
