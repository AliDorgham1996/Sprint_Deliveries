#include "../ECUAL/Buzzer/Buzzer.h"

void Buzzer_Init(void)
{
	Dio_ChannelMode(BUZZER_PIN, DIO_EN_M_Output);
	Dio_ChannelWrite(BUZZER_PIN, DIO_EN_W_Low);
}

void Buzzer_State(Buzzer_State_t State)
{
	Dio_ChannelWrite(BUZZER_PIN, State);
}