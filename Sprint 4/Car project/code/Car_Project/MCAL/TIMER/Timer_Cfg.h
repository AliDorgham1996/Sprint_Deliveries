#ifndef TIMER_CFG_H
#define TIMER_CFG_H


#include <stdint.h>		



typedef enum
{
	//common
	TMR_EN_NoClock,
	TMR_EN_FCPU_Clock,
	TMR_EN_PRESCAL_8,
}TMR_Clock_t;


#endif /* TIMER_CFG_H */
