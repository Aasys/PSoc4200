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
extern uint8 Time_Expired = 0;
extern uint8 Max_Count = 5;
extern uint8 count = 0;

CY_ISR(my_PWM_TC_isr){
    uint32 interrupt_source;
    if (Time_Expired == 0) {
        count++;
        if (count == Max_Count) {
            Time_Expired = 1;
            count = 0;
        }
    }
    my_isr_ClearPending();
    interrupt_source = my_PWM_GetInterruptSourceMasked();
    my_PWM_ClearInterrupt(interrupt_source);
}

int main(void)
{
    CyGlobalIntDisable;
    my_isr_Start();
    my_isr_SetVector(my_PWM_TC_isr);
    my_PWM_Start();
    my_isr_Disable();
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    while (1) {
        Time_Expired = 0;
        my_isr_Enable();
        while (!Time_Expired);
        my_isr_Disable();
        LED_Write(!LED_Read());
    }
}

/* [] END OF FILE */
