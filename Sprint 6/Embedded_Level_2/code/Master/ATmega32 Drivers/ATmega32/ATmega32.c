#include "../APP/Sprint_6.h"

#define Task_UART_Driver		1
#define Task_Traffic_System		2
#define Task_SPI_Driver			3
#define Task_SPI_UART			4
#define Task_I2C_Driver			5
#define Task_I2C_EEPROM			6

#define Running_Task  Task_I2C_Driver

int main(void)
{
#if (Running_Task == Task_UART_Driver)
	UART_Driver();
#elif (Running_Task == Task_Traffic_System)
	Traffic_System();
#elif (Running_Task == Task_SPI_Driver)
	SPI_Driver();
#elif (Running_Task == Task_SPI_UART)
	SPI_UART();
#elif (Running_Task == Task_I2C_Driver)
	I2C_Driver();
#elif (Running_Task == Task_I2C_EEPROM)
	I2C_EEPROM();
#endif /* Task */
}