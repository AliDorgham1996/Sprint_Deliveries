#include "../MCAL/I2C/I2C.h"
#include "../Library/System_Delays/Delays.h"

void I2C_Driver(void)
{
	I2C_init(100000);
	while(1)
	{
		Delay_Ms(100);
		I2C_Start();
		I2C_Write(I2C_SLAVE_ADDRESS, I2C_MT_SLAW_ACK);
		I2C_Write('A', I2C_MT_DATA_ACK);
		I2C_Stop();
	}
}
/*
#include "../Library/Registers.h"
void I2C_Driver(void)
{
	I2C_init(100000);
	DDRA = 0xFF;
	uint8_t Data = 0;
	while(1)
	{
		I2C_Read(&Data, I2C_MR_DATA_ACK);
		PORTA = Data;
	}
}
*/