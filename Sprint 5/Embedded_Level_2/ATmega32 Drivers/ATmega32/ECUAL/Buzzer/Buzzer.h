#ifndef BUZZER_H_
#define BUZZER_H_

#include "../MCAL/DIO/Dio.h"

#define BUZZER_PIN   DIO_EN_Channel_B_3

typedef enum
{
	Buzzer_OFF    = DIO_EN_W_Low,
	Buzzer_ON     = DIO_EN_W_High,
	Buzzer_Toggle = DIO_EN_W_Toggle
}Buzzer_State_t;

void Buzzer_Init(void);
void Buzzer_State(Buzzer_State_t State);



#endif /* BUZZER_H_ */