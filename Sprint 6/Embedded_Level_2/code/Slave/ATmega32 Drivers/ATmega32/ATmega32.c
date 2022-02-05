#include "../APP/Sprint_6.h"

#define Task_IDLE				0
#define Task_SPI_Driver			3
#define Task_SPI_UART			4
#define Task_I2C_Driver			5

#define Running_Task            Task_I2C_Driver

int main(void)
{
#if (Running_Task == Task_SPI_Driver)
	SPI_Driver();
#elif (Running_Task == Task_SPI_UART)
	SPI_UART();
#elif (Running_Task == Task_I2C_Driver)
	I2C_Driver();
#elif (Running_Task == Task_IDLE)
	IDLE();
#endif /* Task */
}