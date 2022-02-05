#include "../MCAL/I2C/I2C.h"
#include "../Library/Registers.h"
#include "../Library/System_Delays/Delays.h"
#include "../ECUAL/LCD/LCD.h"

void I2C_Driver(void)
{
	uint8_t Data = 7;
	//LCD_init();
	I2C_Error_t result = I2C_EN_valid;
	DDRA  = 0xFF;
	I2C_init(100000);
	Delay_Ms(100);
// 	I2C_Start();
// 	I2C_Write(I2C_SLAVE_ADDRESS, I2C_MT_SLAW_ACK);
// 	I2C_Write(Data, I2C_MT_DATA_ACK);
// 	//LCD_Display_StringXY(2,1,"OK");
// 	Delay_Ms(50);
// 	I2C_Stop();
// 	PORTA = Data;
// 	//LCD_Display_NumXY(1,1,Data);
// 	Data++;
// 	Delay_Ms(1000);
	while(1)
	{
		I2C_Start();
		I2C_Write(I2C_SLAVE_ADDRESS, I2C_MT_SLAW_ACK);
		I2C_Write(Data, I2C_MT_DATA_ACK);
		I2C_Stop();
		PORTA = Data;
		Data++;
		Delay_Ms(1000);
	}
}