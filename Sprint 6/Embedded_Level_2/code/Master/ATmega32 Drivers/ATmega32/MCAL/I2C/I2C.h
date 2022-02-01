#ifndef I2C_H_
#define I2C_H_

#include "../MCAL/I2C/I2C_Cfg.h"

typedef enum
{
	I2C_EN_valid,
	I2C_EN_Invalid,
	I2C_EN_InvalidPointer
}I2C_Error_t;

void            I2C_init			(uint32_t Speed);
I2C_Error_t     I2C_Start			(void);
I2C_Error_t     I2C_Restart			(void);
void			I2C_Stop			(void);
I2C_Error_t		I2C_Write			(uint8_t  Data, I2C_StatusCode_t Code);
I2C_Error_t		I2C_Read			(uint8_t* Data, I2C_StatusCode_t Code);

#endif /* I2C_H_ */