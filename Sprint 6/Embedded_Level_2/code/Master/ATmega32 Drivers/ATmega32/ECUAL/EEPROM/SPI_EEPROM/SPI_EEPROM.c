#include "../ECUAL/EEPROM/SPI_EEPROM/SPI_EEPROM.h"
#include "../MCAL/DIO/Dio.h"


void				SPI_EEPROM_init		(void)
{
	SPI_Init(SPI_EN_Master);
}

SPI_EEPROM_Error_t	SPI_EEPROM_Write	(uint16_t Address, uint8_t  Data)
{
	//latch on
	Dio_ChannelWrite(DIO_EN_Channel_B_4, DIO_EN_W_Low);
	SPI_Transceive(SPI_EEPROM_W_ENABLE);
	Dio_ChannelWrite(DIO_EN_Channel_B_4, DIO_EN_W_High);
	//address + data
	Dio_ChannelWrite(DIO_EN_Channel_B_4, DIO_EN_W_Low);
	SPI_Transceive(SPI_EEPROM_WRITE);
	SPI_Transceive(Address>>8);
	SPI_Transceive(Address);
	SPI_Transceive(Data);
	Dio_ChannelWrite(DIO_EN_Channel_B_4, DIO_EN_W_High);
	//latch off
	Dio_ChannelWrite(DIO_EN_Channel_B_4, DIO_EN_W_Low);
	SPI_Transceive(SPI_EEPROM_W_DISABLE);
	Dio_ChannelWrite(DIO_EN_Channel_B_4, DIO_EN_W_High);
}

SPI_EEPROM_Error_t	SPI_EEPROM_Read		(uint16_t Address, uint8_t* Data)
{
	Dio_ChannelWrite(DIO_EN_Channel_B_4, DIO_EN_W_Low);
	SPI_Transceive(SPI_EEPROM_READ);
	SPI_Transceive(Address>>8);
	SPI_Transceive(Address);
	*Data = SPI_Transceive(SPI_DUMMY);
	Dio_ChannelWrite(DIO_EN_Channel_B_4, DIO_EN_W_High);	
}