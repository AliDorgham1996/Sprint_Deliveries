#include "../MCAL/I2C/I2C.h"
#include "../Library/Registers.h"
#include "../Library/System_Delays/Delays.h"

void I2C_Driver(void)
{
	uint8_t Data = 0;
	DDRA = 0xFF; 
	I2C_init(100000);
	Delay_Ms(100);
	while(1)
	{
		I2C_Start();
		I2C_Write(I2C_SLAVE_ADDRESS, I2C_MT_SLAW_ACK);
		I2C_Write(Data, I2C_MT_DATA_ACK);
		PORTA = Data++;
		I2C_Stop();
		Delay_Ms(1000);
	}
}