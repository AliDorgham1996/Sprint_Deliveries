#include "../MCAL/Timer/Timer_Private.h"    
#include "../MCAL/Timer/Timer.h"
#include "../Library/Configurations.h"	        
#include "../Library/Registers.h"			
#include "../Library/Bit_Math.h"
#include "../Library/Constants.h"	
#include <avr/interrupt.h>		

typedef enum {ON_Cycle, OFF_Cycle, CycleS}Cycle_t;

_V _S V_CallBack_V_t  CounterAction               = NULL;
_V _S V_CallBack_V_t  NotifierAction[TMR_End]     = {NULL};
   _S TMR_Clock_t	  Clock         [TMR_End]     = {TMR_EN_NoClock};
_V _S uint64_t	      OverFlows     [TMR_End]     = {RESET};
_V _S Cycle_t	      Cycle         [TMR_End]     = {OFF_Cycle};
_V _S uint64_t	      Duty          [TMR_End][2]  = {RESET};	
_V _S V_CallBack_V_t  PWMAction     [TMR_End]     = {NULL};
	






TimerError_t      Timer_Init			(_C TMR_Configuration_t * _C Configuration)
{
	TimerError_t return_value = TMR_EN_valid_inti;
	if(Configuration != NULL)
	{
		if(Configuration->Timer == Timer0)
		{
			Timer_Stop(Configuration->Timer);
			Timer_ResetCounter(Configuration->Timer);
			TIMER0.Control.CTC_wave_generation = Configuration->Mode>>1;
			TIMER0.Control.PWM_wave_generation = Configuration->Mode<<1;
			TIMER0.Control.Clock = TMR_EN_NoClock;
			TIMER0.Control.Modes_out_on_comp = Configuration->Action.OCR_Pin;
			TIMER0.CompareValue = Configuration->CompareValue;
			Clock[Configuration->Timer] = Configuration->Clock;
		}
		else if(Configuration->Timer == Timer2)
		{
			Timer_Stop(Configuration->Timer);
			Timer_ResetCounter(Configuration->Timer);
			TIMER2.Control.CTC_wave_generation = Configuration->Mode>>1;
			TIMER2.Control.PWM_wave_generation = Configuration->Mode<<1;
			TIMER2.Control.Clock = TMR_EN_NoClock;
			TIMER2.Control.Modes_out_on_comp = Configuration->Action.OCR_Pin;
			TIMER2.CompareValue = Configuration->CompareValue;
			Clock[Configuration->Timer] = Configuration->Clock;
		}
		else
		{
			return_value = TMR_EN_InvalidTimer;	
		}
	}
	else
	{
		return_value = TMR_EN_InvalidPointer;
	}
	return return_value;
}
void              Timer_De_init			(Timer_t Timer)
{
	if(Timer == Timer0)
	{
		Timer_Stop(Timer);
		Timer_ResetCounter(Timer);
		TIMER0.Interrupts.Comp_Match       = DISABLE;
		TIMER0.Interrupts.OverFlow         = DISABLE;
		TIMER0.Control.CTC_wave_generation = DISABLE;
		TIMER0.Control.PWM_wave_generation = DISABLE;
		TIMER0.Control.Modes_out_on_comp   = TMR_EN_CTC_Disconnect;
		TIMER0.CompareValue = RESET;
	}
	else if (Timer == Timer2)
	{
		Timer_Stop(Timer);
		Timer_ResetCounter(Timer);
		TIMER2.Interrupts.Comp_Match       = DISABLE;
		TIMER2.Interrupts.OverFlow         = DISABLE;
		TIMER2.Control.CTC_wave_generation = DISABLE;
		TIMER2.Control.PWM_wave_generation = DISABLE;
		TIMER2.Control.Modes_out_on_comp   = TMR_EN_CTC_Disconnect;
		TIMER2.CompareValue = RESET;
	}
	else{/*MISRA C*/}
}
void			  Timer_Start			(Timer_t Timer)
{
	if(Timer == Timer0)
	{
		TIMER0.Control.Clock = Clock[Timer0];
	}
	else if(Timer == Timer2)
	{
		TIMER2.Control.Clock = Clock[Timer2];
	}
	else{/*MISRA C*/}
}
void			  Timer_Stop			(Timer_t Timer)
{
	if(Timer == Timer0)
	{
		TIMER0.Control.Clock = TMR_EN_NoClock;	
	}
	else if(Timer == Timer2)
	{
		TIMER2.Control.Clock = TMR_EN_NoClock;
	}
	else{/*MISRA C*/}
}
TimerError_t      Timer_Counter_0		(V_CallBack_V_t Ptr_Action, uint8_t Counts, TMR_Edge_t Edge)
{
	TimerError_t return_value = TMR_EN_valid_inti;
	if((Ptr_Action != NULL))
	{
		Timer_Stop(Timer0);
		TIMER0.Control.CTC_wave_generation = ENABLE;
		TIMER0.Control.PWM_wave_generation = DISABLE;
		
		CounterAction = Ptr_Action;
		TIMER0.CompareValue = Counts;
		
		TIMER0.Interrupts.Comp_Match = ENABLE;
		TIMER0.Control.Clock = Edge;
		//DDRB0 = INPUT;
	}
	else
	{
		return_value = TMR_EN_InvalidPointer;
	}
	return return_value;
}
void		      Timer_Delay_MS		(Timer_t Timer, uint32_t Delay)
{
	if(Timer == Timer0)
	{
		TIMER0.Control.CTC_wave_generation = DISABLE;
		TIMER0.Control.PWM_wave_generation = DISABLE;
		TIMER0.Control.Modes_out_on_comp   = TMR_EN_CTC_Disconnect;
		
		Timer_ResetCounter(Timer0);
		TIMER0.Interrupts.OverFlow		   = ENABLE;
		TIMER0.Control.Clock               = TMR_EN_FCPU_Clock;

		while(((OverFlows[Timer0]*256UL + (TIMER0.Counter) + 1)) < (Delay*8000UL));
	}
	else if(Timer == Timer2)
	{
		TIMER2.Control.CTC_wave_generation = DISABLE;
		TIMER2.Control.PWM_wave_generation = DISABLE;
		TIMER2.Control.Modes_out_on_comp   = TMR_EN_CTC_Disconnect;
		
		Timer_ResetCounter(Timer2);
		TIMER2.Interrupts.OverFlow		   = ENABLE;
		TIMER2.Control.Clock               = TMR_EN_FCPU_Clock;

		while(((OverFlows[Timer2]*256UL + (TIMER2.Counter) + 1)) < (Delay*8000UL));
	}
	else{/*MISRA C*/}
}
void	          Timer_ResetCounter    (Timer_t Timer)
{
	
	if(Timer == Timer0)
	{
		OverFlows[Timer0]	= RESET;
		TIMER0.Counter		= RESET;
	}
	else if(Timer == Timer2)
	{
		OverFlows[Timer2]	= RESET;
		TIMER2.Counter		= RESET;
	}
	else{/*MISRA C*/}
}
TimerError_t      Timer_SetTrigger		(Timer_t Timer, V_CallBack_V_t Notifier, uint32_t Time_On_MS, uint32_t Time_Off_MS)
{
	TimerError_t return_value = TMR_EN_valid_inti;
	if((Notifier != NULL))
	{
		if(Timer == Timer0)
		{
			TIMER0.Control.CTC_wave_generation = DISABLE;
			TIMER0.Control.PWM_wave_generation = DISABLE;
			TIMER0.Control.Modes_out_on_comp   = TMR_EN_CTC_Disconnect;
			
			NotifierAction[Timer0]  = Notifier;
			OverFlows[Timer0]       = RESET;
			
			Duty[Timer0][ON_Cycle]  = (Time_On_MS  * 1000UL) / 256 ;//no. OverFlowsT0 for on Duty
			Duty[Timer0][OFF_Cycle] = (Time_Off_MS * 1000UL) / 256 ;//no. OverFlowsT0 for off Duty
			
			TIMER0.Interrupts.OverFlow		   = ENABLE;
			TIMER0.Control.Clock               = TMR_EN_PRESCAL_8;
		}
		else if(Timer == Timer2)
		{
			TIMER2.Control.CTC_wave_generation = DISABLE;
			TIMER2.Control.PWM_wave_generation = DISABLE;
			TIMER2.Control.Modes_out_on_comp   = TMR_EN_CTC_Disconnect;
			
			NotifierAction[Timer2]  = Notifier;
			OverFlows[Timer2]       = RESET;
			
			Duty[Timer2][ON_Cycle]  = (Time_On_MS  * 1000UL) / 256 ;//no. OverFlowsT0 for on Duty
			Duty[Timer2][OFF_Cycle] = (Time_Off_MS * 1000UL) / 256 ;//no. OverFlowsT0 for off Duty
			
			TIMER2.Interrupts.OverFlow		   = ENABLE;
			TIMER2.Control.Clock               = TMR_EN_PRESCAL_8;
		}
		else{/*MISRA C*/}
	}
	else
	{
		return_value = TMR_EN_InvalidPointer;
	}
	return return_value;
}
void			  Timer_PWM_SetDuty		(Timer_t Timer, uint8_t PWMDuty)
{
	if(Timer == Timer0)
	{
		TIMER0.Control.CTC_wave_generation = DISABLE;
		TIMER0.Control.PWM_wave_generation = ENABLE;
		if(PWMDuty >= 100)
		{
			TIMER0.CompareValue = 0xFF;
		}
		else
		{
			TIMER0.CompareValue = (0xFFUL*PWMDuty)/100.0;
		}
		//DDRB3 = OUTPUT;
		TIMER0.Interrupts.Comp_Match       = DISABLE;
		TIMER0.Control.Clock = TMR_EN_T0_PRESCAL_1024;
	}
	else if(Timer == Timer2)
	{
		TIMER2.Control.CTC_wave_generation = DISABLE;
		TIMER2.Control.PWM_wave_generation = ENABLE;
		if(PWMDuty >= 100)
		{
			TIMER2.CompareValue = 0xFF;
		}
		else
		{
			TIMER2.CompareValue = (0xFFUL*PWMDuty)/100.0;
		}
		//DDRD7 = OUTPUT;
		TIMER2.Interrupts.Comp_Match       = DISABLE;
		TIMER2.Control.Clock = TMR_EN_T2_PRESCAL_1024;
	}
	else{/*MISRA C*/}
}
void			  Timer_PWMCallBack     (Timer_t Timer, V_CallBack_V_t pwm_toggle)
{
	if(Timer == Timer0)
	{
		PWMAction[Timer0] = pwm_toggle;
	}
	else if(Timer == Timer2)
	{
		PWMAction[Timer2] = pwm_toggle;
	}
	else{/*MISRA C*/}
}
void		      Timer_SoftWarePWM		(Timer_t Timer, uint8_t PWMDuty, TMR_Clock_t Clock)
{
	float localDuty = 0;
	if(Timer == Timer0)
	{
		TIMER0.Control.CTC_wave_generation = DISABLE;
		TIMER0.Control.PWM_wave_generation = ENABLE;
		if(PWMDuty >= 100)
		{
			TIMER0.CompareValue = 0xFF;
		}
		else
		{
			localDuty = (0xFFUL*PWMDuty)/100.0;
			TIMER0.CompareValue = localDuty;
		}
		//DDRB3 = OUTPUT;
		TIMER0.Interrupts.Comp_Match       = DISABLE;
		TIMER0.Control.Clock = Clock;
	}
	else if(Timer == Timer2)
	{
		TIMER2.Control.CTC_wave_generation = DISABLE;
		TIMER2.Control.PWM_wave_generation = ENABLE;
		if(PWMDuty >= 100)
		{
			TIMER2.CompareValue = 0xFF;
		}
		else
		{
			localDuty = (0xFFUL*PWMDuty)/100.0;
			TIMER2.CompareValue = localDuty;
		}
		//DDRD7 = OUTPUT;
		TIMER2.Interrupts.Comp_Match       = DISABLE;
		TIMER2.Control.Clock = Clock;
	}
	else{/*MISRA C*/}
}


ISR(TIMER0_OVF_vect)
{
	TIMER0.Flags.OverFlow = ENABLE;
	OverFlows[Timer0]++;
	if(OverFlows[Timer0] == Duty[Timer0][Cycle[Timer0]])
	{
		OverFlows[Timer0] = RESET;
		NotifierAction[Timer0]();
		if(Cycle[Timer0] == ON_Cycle)
		{
			Cycle[Timer0] = OFF_Cycle;
			TIMER0.Counter  = 256 - ((Duty[Timer0][OFF_Cycle] * 1000UL)%256 -1);
		}
		else if(Cycle[Timer0] == OFF_Cycle)
		{
			Cycle[Timer0] = ON_Cycle;
			TIMER0.Counter  = 256 - ((Duty[Timer0][ON_Cycle] * 1000UL)%256 -1);
		}
	}
}
ISR(TIMER2_OVF_vect)
{
	TIMER2.Flags.OverFlow = ENABLE;
	OverFlows[Timer2]++;
	if(OverFlows[Timer2] == Duty[Timer2][Cycle[Timer2]])
	{
		OverFlows[Timer2] = RESET;
		NotifierAction[Timer2]();
		if(Cycle[Timer2] == ON_Cycle)
		{
			Cycle[Timer2] = OFF_Cycle;
			TIMER0.Counter  = 256 - ((Duty[Timer2][OFF_Cycle] * 1000UL)%256 -1);
		}
		else if(Cycle[Timer2] == OFF_Cycle)
		{
			Cycle[Timer2] = ON_Cycle;
			TIMER2.Counter  = 256 - ((Duty[Timer2][ON_Cycle] * 1000UL)%256 -1);
		}
	}
}
ISR(TIMER0_COMP_vect)
{
	TIMER0.Flags.Comp_Match = ENABLE;
	if(CounterAction != NULL)
	{
		CounterAction();
		Timer_ResetCounter(Timer0);
	}
	PWMAction[Timer0]();
}
ISR(TIMER2_COMP_vect)
{
	TIMER2.Flags.Comp_Match = ENABLE;
	PWMAction[Timer2]();
}