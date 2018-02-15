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
uint8 Ped_Waiting;
uint8 Time_Expired;
uint16 Max_Count;
uint16 count;

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

CY_ISR(SW_int) {
    CyDelay(50);
    while (!CrossWalk_Button_Read());
    CyDelay(50);
    Ped_Waiting = 1;
    CrossWalk_Button_ClearInterrupt();
}


#define T_yellow 1
#define T_Traffic 3
#define T_Ped 6
#define T_Ped_Warning 3
#define RedGreen 0
#define RedYellow 1
#define GreenRed 2
#define YellowRed 3
uint8 state;

int main(void)
{
    CyGlobalIntDisable;
    my_isr_Start();
    my_isr_SetVector(my_PWM_TC_isr);
    my_PWM_Start();
    my_isr_Disable();
    
    isr_btn_Start();
    isr_btn_SetVector(SW_int);
    
    state = GreenRed;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    while (1) {
        
        if (state == GreenRed) {
            LED_Red_Write(0);
            LED_Green_Write(1);
            Time_Expired = 0;
            Max_Count = T_Traffic;
            count = 0;
            my_PWM_Stop();
            my_PWM_WriteCounter(0);
            my_PWM_Start();
            
            my_isr_Enable();
            while (!Time_Expired);
            my_isr_Disable();
            while (!Ped_Waiting);
            Ped_Waiting = 0;
            state = YellowRed;            
        }
        else if (state == YellowRed) {
            LED_Red_Write(0);
            LED_Green_Write(1);
            Time_Expired = 0;
            Max_Count = T_yellow;
            count = 0;
            my_PWM_Stop();
            my_PWM_WriteCounter(0);
            my_PWM_Start();
            
            my_isr_Enable();
            while (!Time_Expired);
            my_isr_Disable();
            
            state = RedGreen;            
        }
        else if (state == RedGreen) {
            LED_Red_Write(1);
            LED_Green_Write(0);
            Time_Expired = 0;
            Max_Count = T_Ped;
            count = 0;
            my_PWM_Stop();
            my_PWM_WriteCounter(0);
            my_PWM_Start();
            
            my_isr_Enable();
            while (!Time_Expired);
            my_isr_Disable();   
            state = RedYellow;            
        }
        else if (state == RedYellow) {
            LED_Red_Write(0);
            LED_Green_Write(0);
            
            Time_Expired = 0;
            Max_Count = T_Ped_Warning;
            count = 0;
            my_PWM_Stop();
            my_PWM_WriteCounter(0);
            my_PWM_Start();
            
            my_isr_Enable();
            while (!Time_Expired) {
                CyDelay(100); LED_Red_Write(0); LED_Green_Write(0);
                CyDelay(100); LED_Red_Write(1); LED_Green_Write(0);
            }
            my_isr_Disable();
            state = GreenRed;            
        }
        
        
    }
}


/* [] END OF FILE */
