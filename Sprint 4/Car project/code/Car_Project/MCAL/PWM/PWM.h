/*
 * PWM.h
 *
 * Created: 1/13/2022 10:15:51 PM
 *  Author: Ali Hassan Dorgham
 */ 


#ifndef PWM_H_
#define PWM_H_


#include "DIO.h"

typedef enum
{
	PWM_EN_Duty_30 = 77,
	PWM_EN_Duty_60 = 154,
	PWM_EN_Duty_90 = 230,
}PWM_DutyValue_t;

typedef enum
{
	PWM_0, PWM_2
}PWM_ID; 

void PWM_Init(PWM_ID pwm_ch);
void PWM_Stop(PWM_ID pwm_ch);
void SET_PWM_DutyCycle(PWM_ID pwm_ch, uint8_t Duty);



#endif /* PWM._H_ */