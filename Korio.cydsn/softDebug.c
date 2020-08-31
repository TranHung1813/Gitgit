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
#include "softDebug.h"
/* ---- DEBUG ----- */

//static uint8_t stringDebug[100];
//void DEBUG_UC(const char *format, ...)
//{
//	va_list arg;
//	va_start(arg, format);
//	vsprintf((char*)stringDebug, format, arg); 
//	va_end(arg);
//}

void DEBUG_SW_UART(const char *format, ...)
{
    const char8 string[100];
   	va_list arg;
	va_start(arg, format);
	vsprintf((char*)string, format, arg); 
    SW_Tx_UART_PutString(string);
	va_end(arg); 
}

/* --------------- */
/* [] END OF FILE */
