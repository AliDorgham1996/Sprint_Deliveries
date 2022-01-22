#include "timer.h"
#include "Timer_Private.h"
#include "avr/interrupt.h"

static void (*TMR_CALLBACKS[])(void) = {NULL_PTR,NULL_PTR};

void TIMER_setCallBack(void(*fun)(void), TIMER_ID_t Timer)
{
	TMR_CALLBACKS[Timer]=fun;
}
void TIMER_start(TIMER_ID_t Timer, uint8_t duty)
{
	if(Timer == Timer_0)
	{
		TIMER.T0.Counter      = 0;
		TIMER.T0.CompareValue = 0xFF - duty;//1
		TIMER.T0.Interrupts.Comp_Match = ENABLE;//3
		TIMER.T0.Control.PWM_wave_generation = ENABLE;//2
		TIMER.T0.Control.Clock = 4;
	}
	else if(Timer == Timer_2)
	{
		TIMER.T2.Counter      = 0;
		TIMER.T2.CompareValue = 0xFF - duty;//1
		TIMER.T2.Interrupts.Comp_Match = ENABLE;//3
		TIMER.T2.Control.PWM_wave_generation = ENABLE;//2
		TIMER.T2.Control.Clock = 6;
	}
}
void TIMER_stop(TIMER_ID_t Timer)
{
	if(Timer == Timer_0)
	{
		TIMER.T0.Control.Clock = TMR_EN_NoClock;
	}
	else if (Timer == Timer_2)
	{
		TIMER.T2.Control.Clock = TMR_EN_NoClock;
	}
}
ISR(TIMER0_OVF_vect)
{
	TIMER.T0.Flags.OverFlow = ENABLE;
	TMR_CALLBACKS[Timer_0]();
}
ISR(TIMER2_OVF_vect)
{
	TIMER.T2.Flags.OverFlow = ENABLE;
	TMR_CALLBACKS[Timer_2]();
}
ISR(TIMER0_COMP_vect)
{
	TIMER.T0.Flags.Comp_Match = ENABLE;
	TMR_CALLBACKS[Timer_0]();
}
ISR(TIMER2_COMP_vect)
{
	TIMER.T2.Flags.Comp_Match = ENABLE;
	TMR_CALLBACKS[Timer_2]();
}