#ifndef TIMER_H
#define TIMER_H
#include "../MCAL/Timer/Timer_Cfg.h"
#include "../Library/Types_Defs.h"								
			
typedef enum
{
	TMR_EN_valid_inti,
	TMR_EN_InvalidPointer,
	TMR_EN_TimerBusy	
}TimerError_t;

TimerError_t      Timer_SetTrigger		(Timer_t Timer, V_CallBack_V_t Notifier, uint8_t Time_MS);
Flag_t            Timer_Status          (Timer_t Timer);

#endif /* TIMER_H */