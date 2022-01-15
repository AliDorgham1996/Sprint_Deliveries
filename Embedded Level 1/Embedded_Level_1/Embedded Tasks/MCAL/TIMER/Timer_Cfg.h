#ifndef TIMER_CFG_H
#define TIMER_CFG_H


#include <stdint.h>		
#include "../MCAL/PWM/PWM_Cfg.h"		
#include "../Library/Constants.h"

typedef enum
{
	TMR_EN_FallingEdge = 6,
	TMR_EN_RisingEdge,
}TMR_Edge_t;


typedef enum
{
	TMR_Start,
	Timer0 = TMR_Start,
	Timer2,
	TMR_End
}Timer_t;

typedef enum
{
	//common
	TMR_EN_NoClock,
	TMR_EN_FCPU_Clock,
	TMR_EN_PRESCAL_8,
	//T0
	TMR_EN_T0_PRESCAL_64,
	TMR_EN_T0_PRESCAL_256,
	TMR_EN_T0_PRESCAL_1024,
	//T2
	TMR_EN_T2_PRESCAL_32 = 3,
	TMR_EN_T2_PRESCAL_64,
	TMR_EN_T2_PRESCAL_128,
	TMR_EN_T2_PRESCAL_256,
	TMR_EN_T2_PRESCAL_1024
}TMR_Clock_t;


typedef union
{
	enum
	{
		TMR_EN_CTC_Disconnect,
		TMR_EN_CTC_Toggle,
		TMR_EN_CTC_Low,
		TMR_EN_CTC_High
	}TMR_CTC_Mode;
	
	enum
	{
		TMR_EN_PWM_Disconnect,
		TMR_EN_PWM_Non_Inverting = 2,
		TMR_EN_PWM_Inverting,
	}TMR_PWM_Mode;
	uint8_t OCR_Pin;
}TMR_OutOnCompareMatch_t;

/*
typedef enum
{
	TMR_EN_MIN_Freq = 31,
	TMR_EN_MAX_Freq = 31000
}TMR_Frequency_t;
*/

typedef enum
{
	TMR_EN_T0_Normal,
	TMR_EN_T0_PWM,
	TMR_EN_T0_CTC,
	TMR_EN_T0_F_PWM	
}TMR_Mode_t;


typedef enum
{
	TMR_EN_OverFlow,
	TMR_EN_CompMatch
}TMR_Interrupt_t;


typedef struct
{
	Timer_t						 Timer;
	TMR_Mode_t				     Mode;
	TMR_Clock_t					 Clock;
	TMR_OutOnCompareMatch_t      Action;
	uint8_t				         CompareValue;
}TMR_Configuration_t;


#endif /* TIMER_CFG_H */
