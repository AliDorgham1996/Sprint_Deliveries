#ifndef TIMER_CFG_H
#define TIMER_CFG_H


#include <stdint.h>				
#include "../Library/Constants.h"

#define TIMER0_1_ms_P_64_F_8MHz         125
#define TIMER2_1_ms_P_64_F_8MHz         125

typedef enum
{
	Timer_0,
	Timer_2
}Timer_t;

typedef enum
{
	TMR_EN_NoClock,
	TMR_EN_FCPU_Clock,
	TMR_EN_PRESCAL_8,
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

#define TIMER0_Prescal     TMR_EN_T0_PRESCAL_64
#define TIMER2_Prescal     TMR_EN_T2_PRESCAL_64

#endif /* TIMER_CFG_H */
