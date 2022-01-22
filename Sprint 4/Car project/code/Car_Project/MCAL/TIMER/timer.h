#ifndef TIMER_H_
#define TIMER_H_

#include "Bit_Math.h"
#include "Global_Enums.h"
#include "Library.h"
#include "Timer_Cfg.h"


typedef enum
{
	Timer_0, 
	Timer_2
}TIMER_ID_t;


typedef enum
{
	TMR_NO_CLOCK = 0, TMR_F_CPU_CLOCK, TMR_F_CPU_8
}TIMER_Clock_t;


void TIMER_setCallBack(void(*fun)(void), TIMER_ID_t Timer);
void TIMER_start(TIMER_ID_t Timer, uint8_t duty);
void TIMER_stop(TIMER_ID_t Timer);


#endif /* TIMER_H_ */
