#include "../MCAL/Timer/Timer_Private.h"    
#include "../MCAL/Timer/Timer.h"	        
#include "../Library/Registers.h"			
#include "../Library/Constants.h"	
#include <avr/interrupt.h>		

 

_V _S V_CallBack_V_t Timer_Triggers [2]  = {NULL, NULL};
_V _S uint8_t        Triggers       [2]  = {0, 0};
_V _S uint8_t        Overflows		[2]  = {0, 0};
_V _S uint8_t        Flag           [2]  = {Flag_Available, Flag_Available};

Flag_t			  Timer_Status          (Timer_t Timer)
{
	return Flag[Timer];
}
TimerError_t      Timer_SetTrigger		(Timer_t Timer, V_CallBack_V_t Notifier, uint8_t Time_MS)
{
	TimerError_t return_value = TMR_EN_valid_inti;
	if((Notifier != NULL))
	{
		if(Flag[Timer] == Flag_Available)
		{
			if(Timer == Timer_0)
			{
				Flag[Timer_0]						 = Flag_Busy;
				TIMER.T0.Control.CTC_wave_generation = ENABLE;
				TIMER.T0.CompareValue                = TIMER0_1_ms_P_64_F_8MHz;
				Timer_Triggers[Timer_0]				 = Notifier;
				Triggers[Timer_0]					 = Time_MS;
				Overflows[Timer_0]                   = 0;
				TIMER.T0.Counter                     = 0;
				TIMER.T0.Interrupts.Comp_Match	     = ENABLE;
				TIMER.T0.Control.Clock               = TIMER0_Prescal;
			}
			else if(Timer == Timer_2)
			{
				Flag[Timer_2]						 = Flag_Busy;
				TIMER.T2.Control.CTC_wave_generation = ENABLE;
				TIMER.T2.CompareValue                = TIMER2_1_ms_P_64_F_8MHz;
				Timer_Triggers[Timer_2]				 = Notifier;
				Triggers[Timer_2]					 = Time_MS;
				Overflows[Timer_2]                   = 0;
				TIMER.T2.Counter                     = 0;
				TIMER.T2.Interrupts.Comp_Match	     = ENABLE;
				TIMER.T2.Control.Clock               = TIMER2_Prescal;
			}
			else{/*MISRA C*/}
		}
		else
		{
			return_value = TMR_EN_TimerBusy;
		}
	}
	else
	{
		return_value = TMR_EN_InvalidPointer;
	}
	return return_value;
}
ISR(TIMER0_COMP_vect)
{
	TIMER.T0.Flags.Comp_Match = ENABLE;
	Overflows[Timer_0]++;
	if(Overflows[Timer_0] >= Triggers[Timer_0])
	{
		TIMER.T0.Interrupts.Comp_Match = DISABLE;
		TIMER.T0.Control.Clock         = TMR_EN_NoClock;
		Flag[Timer_0] = Flag_Available;
		if(Timer_Triggers[Timer_0] != NULL)
		{
			Timer_Triggers[Timer_0]();
		}
	}
}
ISR(TIMER2_COMP_vect)
{
	TIMER.T2.Flags.Comp_Match = ENABLE;
	Overflows[Timer_2]++;
	if(Overflows[Timer_2] >= Triggers[Timer_2])
	{
		TIMER.T2.Interrupts.Comp_Match = DISABLE;
		TIMER.T2.Control.Clock         = TMR_EN_NoClock;
		Flag[Timer_2] = Flag_Available;
		if(Timer_Triggers[Timer_2] != NULL)
		{
			Timer_Triggers[Timer_2]();
		}
	}
}