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
#include <device.h>
#include <stdio.h>

// Number of maximum events captured
#define NUM_Capture 10

uint8 InterruptCnt = 0; // Number of interrupts occured
char buffer[10]; // UartPutString buffer
uint32 t0; // timer count

// Interrupt routine
CY_ISR(InterruptHandler) {
    // Clear Interrupt, CC: Compare/Capture
    Timer_ClearInterrupt(Timer_INTR_MASK_CC_MATCH);
    if (InterruptCnt==0)
        t0=Timer_ReadCapture();
    else {
        sprintf(buffer, "%d", (int)(Timer_ReadCapture()-t0));
        UART_UartPutString(buffer);
        UART_UartPutChar(0x20);
        t0 = Timer_ReadCapture();
    }
    InterruptCnt++;
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
