#ifndef SPI_EEPROM_H_
#define SPI_EEPROM_H_

#include "../MCAL/SPI/SPI.h"

#define SPI_EEPROM_W_ENABLE 	0x06
#define SPI_EEPROM_W_DISABLE  	0x04
#define SPI_EEPROM_WRITE	    0x02
#define SPI_EEPROM_READ			0x03

typedef enum
{
	SPI_EEPROM_valid,
	SPI_EEPROM_Invalid,
	SPI_EEPROM_InvalidPointer
}SPI_EEPROM_Error_t;

void				SPI_EEPROM_init			(void);
SPI_EEPROM_Error_t	SPI_EEPROM_Write		(uint16_t Address, uint8_t  Data);
SPI_EEPROM_Error_t	SPI_EEPROM_Read			(uint16_t Address, uint8_t* Data);
SPI_EEPROM_Error_t	SPI_EEPROM_WriteBytes	(uint16_t Address, uint8_t* Data);
SPI_EEPROM_Error_t	SPI_EEPROM_ReadBytes	(uint16_t Address, uint8_t* Data, uint16_t size);

#endif /* SPI_EEPROM_H_ */