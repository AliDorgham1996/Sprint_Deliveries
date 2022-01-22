#ifndef LED_CFG_H
#define LED_CFG_H

#include "../MCAL/DIO/Dio.h"

typedef enum
{
	LED_Start ,
	LED_0 = LED_Start ,
	LED_1 ,
	LED_2 ,
	LED_3 ,
	LED_End
}LED_t;

typedef enum
{
	LED_EN_OFF    = DIO_EN_W_Low,
	LED_EN_ON     = DIO_EN_W_High,
	LED_EN_Toggle = DIO_EN_W_Toggle
}LED_State_t;

#endif /* LED_CFG_H */
