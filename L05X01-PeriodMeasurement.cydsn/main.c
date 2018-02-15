/* ========================================
 * Aasys Sresta
 * 02/15/2018
 * ========================================
*/
#include "project.h"
#include <stdio.h>

// variable and flag
uint32 t0;
uint32 Period;
uint8 data_ready = 0;

// Interrupt routine: reads new count updates
// old count t0 and flags control loop
CY_ISR(InterruptHandler) {
    Timer_ClearInterrupt(Timer_INTR_MASK_CC_MATCH);
    Period = Timer_ReadCapture() - t0;
    t0 = Timer_ReadCapture(); // update  old count
    data_ready = 1; // flag control loop data ready
}

// Function print integer to serial terminal
// sprintf prints int to string at buffer
// UartPutString prints string on serial terminal
void printInt(int i) {
    char buffer[10];
    sprintf(buffer, "%d", i);    
    UART_UartPutString(buffer);
    UART_UartPutChar(10); // ascii space
    UART_UartPutChar(13); // ascii return
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    CC_ISR_StartEx(InterruptHandler); // set interrupt address
    
    UART_Start();  // Start UART
    PWM_Start();   // Start PWM
    Timer_Start(); // Start Timer

    // Control Loop
    for(;;)
    {
        if (data_ready == 1) {
            CyDelay(200); // delay 200ms for terminal print 
            printInt(Period);
            data_ready = 0;
        }    
    }
}

/* [] END OF FILE */
