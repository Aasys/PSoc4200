/* ========================================
 * Aasys Sresta
 * 02/15/2018
 * ========================================
*/
#include "project.h"
#include <stdio.h>

// states definition
#define RISING_EDGE 1
#define FALLING_EDGE 0

// capture and output values
uint16 CapturePosEdge;
uint16 PulseWidth;

// Declare flag and state
uint8 data_ready = 0;
uint8 state = RISING_EDGE;

// Interrupt routine: reads new count updates
// old count t0 and flags control loop
CY_ISR(InterruptHandler) {
    Timer_ClearInterrupt(Timer_INTR_MASK_CC_MATCH);
    
    // State Machine
    if (state == RISING_EDGE) {
        CapturePosEdge = Timer_ReadCapture();
        Timer_SetCaptureMode(Timer_TRIG_FALLING);
        // next state
        state = FALLING_EDGE;
    } else if (state == FALLING_EDGE) {
        // Calculate PulseWidth
        PulseWidth = Timer_ReadCapture() - CapturePosEdge;
        // Change capture mode to rising
        Timer_SetCaptureMode(Timer_TRIG_RISING);
        // next_state
        state = RISING_EDGE;
        
        // data ready
        data_ready = 1;       
    }    
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
            printInt(PulseWidth);
            data_ready = 0;
        }    
    }
}

/* [] END OF FILE */
