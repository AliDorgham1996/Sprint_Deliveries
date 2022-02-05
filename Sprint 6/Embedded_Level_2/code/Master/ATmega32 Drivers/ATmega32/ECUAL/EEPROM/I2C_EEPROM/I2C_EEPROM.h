#ifndef I2C_EEPROM_H_
#define I2C_EEPROM_H_

#include "../MCAL/I2C/I2C.h"

#define I2C_EEPROM_SLA_W		0xA0
#define I2C_EEPROM_SLA_R		0xA1
#define I2C_EEPROM_SPEED		100000UL
#define I2C_EEPROM_DELAY_MS     1U

typedef enum
{
	I2C_EEPROM_valid,
	I2C_EEPROM_Invalid,
	I2C_EEPROM_InvalidRead,
	I2C_EEPROM_InvalidPointer	
}I2C_EEPROM_Error_t;

void				I2C_EEPROM_init			(void);
I2C_EEPROM_Error_t	I2C_EEPROM_Update		(uint16_t Address, uint8_t  Data);
I2C_EEPROM_Error_t	I2C_EEPROM_Read			(uint16_t Address, uint8_t* Data);
I2C_EEPROM_Error_t	I2C_EEPROM_ReadPage		(uint16_t Address, uint8_t* Data, uint16_t size);
I2C_EEPROM_Error_t	I2C_EEPROM_WritePage	(uint16_t Address, uint8_t* Data);
I2C_EEPROM_Error_t		I2C_EEPROM_Write	(uint16_t Address, uint8_t Data);
#endif /* I2C_EEPROM_H_ */