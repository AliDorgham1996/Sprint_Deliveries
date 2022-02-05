#include "../MCAL/I2C/I2C.h"
#include "../Library/Registers.h"
#include "../Library/System_Delays/Delays.h"

void I2C_Driver(void)
{
	uint8_t Data = 0;
	I2C_Error_t result = I2C_EN_valid;
	DDRA = 0xFF;
	I2C_init(100000);
	Delay_Ms(10);
	while(1)
	{
		result = I2C_Listen();
		if(result == I2C_EN_SlaveReceive)
		{
			I2C_Read(&Data, I2C_SR_DATA_ACK);
			PORTA = Data;
		}
	}
}