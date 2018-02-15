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

CY_ISR(PWM_TC_isr){
    uint32 interrupt_source;
    TC_Sig_Write(1);
    interrupt_source = PWM_GetInterruptSourceMasked();
    PWM_ClearInterrupt(interrupt_source);
    TC_Sig_Write(0);
}

int main(void)
{
    PWM_Start();
    isr_TC_StartEx(PWM_TC_isr);
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
