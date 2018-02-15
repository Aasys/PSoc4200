/* ========================================
 * Aasys Sresta
 * 02/15/2018
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
    
    // First interrupt | init
    if (InterruptCnt==0)
        t0=Timer_ReadCapture();
    else {
        // string print int to string of ascii
        // diff of current and previous
        sprintf(buffer, "%d", (int)(Timer_ReadCapture()-t0));
        UART_UartPutString(buffer);
        UART_UartPutChar(0x20); // ascii space
        t0 = Timer_ReadCapture();
    }
    InterruptCnt++; // increment # of interrupts
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    // set interrupt address
    CC_ISR_StartEx(InterruptHandler);
    UART_Start();
    
    // After reset the board put string
    UART_UartPutString(10); // ascii new line
    UART_UartPutString(13); // ascii return
    UART_UartPutString("Press button to start");
    UART_UartPutString(10); // ascii new line
    UART_UartPutString(13); // ascii return
    
    // stuck on switch press and release    
    while (Capture_Pin_Read());
    while (!Capture_Pin_Read());
    
    PWM_Start(); // start PWM
    
    Timer_Start();
    
    // wait for 10 captures, i.e. 9 diffs
    while (InterruptCnt < NUM_Capture);
    
    // Stop when done
    Timer_Stop();
    CC_ISR_Disavle();
    PWM_Stop();
    
    // control loop
    for(;;)
    { 
    }
}

/* [] END OF FILE */
