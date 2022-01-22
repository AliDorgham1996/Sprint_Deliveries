#ifndef PWM_H_
#define PWM_H_

#include "../MCAL/PWM/PWM_Cfg.h"

typedef enum
{
	PWM_EN_valid_inti,
	PWM_EN_InvalidChannel,
	PWM_EN_InvalidDioChannel,
	PWM_EN_InvalidDuty,
	PWM_EN_InvalidFrequency
}PWMError_t;

PWMError_t PWM_Init		(PWM_CH_t pwm_ch);
PWMError_t PWM_Stop		(PWM_CH_t pwm_ch);
PWMError_t PWM_DutyCycle(PWM_CH_t pwm_ch, uint8_t Duty);



#endif /* PWM._H_ */