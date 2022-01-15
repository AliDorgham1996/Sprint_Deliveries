#ifndef TIMER_H
#define TIMER_H

#include "../Library/Types_Defs.h"								
#include "../MCAL/Timer/Timer_Cfg.h"			

typedef enum
{
	TMR_EN_valid_inti,
	TMR_EN_InvalidPointer,
	TMR_EN_InvalidTimer	
}TimerError_t;



//only T0
TimerError_t      Timer_Counter_0	    (V_CallBack_V_t Ptr_Action, uint8_t Counts, TMR_Edge_t Edge);

//T0, T2
TimerError_t      Timer_Init			(_C TMR_Configuration_t * _C Configuration);
void              Timer_De_init			(Timer_t Timer);
void			  Timer_Start			(Timer_t Timer);
void			  Timer_Stop			(Timer_t Timer);
void	          Timer_ResetCounter    (Timer_t Timer);
void		      Timer_Delay_MS		(Timer_t Timer, uint32_t Delay);
TimerError_t      Timer_SetTrigger		(Timer_t Timer, V_CallBack_V_t Notifier, uint32_t Time_On_MS, uint32_t Time_Off_MS);
void			  Timer_PWM_SetDuty		(Timer_t Timer, uint8_t Duty);
void			  Timer_PWMCallBack     (Timer_t Timer, V_CallBack_V_t pwm_toggle);
void		      Timer_SoftWarePWM		(Timer_t Timer, uint8_t PWMDuty, TMR_Clock_t Clock);



#endif /* TIMER_H */

/*********************************************************************************************************
* End of file
**********************************************************************************************************/
