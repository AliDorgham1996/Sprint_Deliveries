#ifndef PWM_CFG_H_
#define PWM_CFG_H_

#include "../MCAL/DIO/Dio.h"
#include "../MCAL/TIMER/Timer.h"
#include "../Library/Constants.h"

typedef enum
{
	PWM_Start,
	PWM_Channel_0 = PWM_Start,
	PWM_Channel_2,
	PWM_End
}PWM_CH_t;

typedef enum
{
	PWM_EN_Inverted,
	PWM_EN_NotInvert
}PWM_Edge_t;


typedef struct  
{
	PWM_CH_t     Channel;
	uint8_t      Timer;
	uint8_t      Clock;
}PWM_CFG_t;

#endif /* PWM_CFG_H_ */