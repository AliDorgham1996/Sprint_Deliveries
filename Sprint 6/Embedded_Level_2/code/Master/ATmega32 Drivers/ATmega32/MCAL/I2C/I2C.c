#include "../MCAL/I2C/I2C.h"
#include "../MCAL/I2C/I2C_Private.h"
#include "../Library/Configurations.h"
#include "../Library/Constants.h"

_S I2C_Error_t	 TWI_Wait		(void);
_S I2C_Error_t	 TWI_Wait		(void)
{
	I2C_Error_t return_value = I2C_EN_Invalid;
	uint32_t timeout = 0;
	while((I2C.Control.TWCR_Bits.interrupt_flag == 0) && (timeout <= I2C_TIME_OUT))
	{
		timeout++;
	}
	
	if(I2C.Control.TWCR_Bits.interrupt_flag == 1)
	{
		return_value = I2C_EN_valid;
	}
	else{/*MISRA C*/}
	return return_value;
}
void            I2C_init			(uint32_t Speed)
{
	I2C.Status.prescaler             = I2C_SPEED;
	I2C.Address.slave_address        = I2C_SLAVE_ADDRESS;
	I2C.BitRate                      = ((F_CPU/Speed) - 16)/(2*I2C_TWBR);
	I2C.Control.TWCR_Bits.i2c_enable = ENABLE;
}
I2C_Error_t     I2C_Start			(void)
{
	I2C_Error_t return_value = I2C_EN_Invalid;
	I2C.Control.TWCR_Reg = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	return_value = TWI_Wait();
	if(return_value != I2C_EN_valid)
	{
		if(I2C.Status.status_code == I2C_START)
		{
			return_value = I2C_EN_valid;
		}
		else{/*MISRA C*/}	
	}
	else{/*MISRA C*/}
	return return_value;
}
I2C_Error_t     I2C_Restart			(void)
{
	I2C_Error_t return_value = I2C_EN_Invalid;
	I2C.Control.TWCR_Reg = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	if(I2C.Status.status_code == I2C_RESTART)
	{
		return_value = I2C_EN_valid;
	}
	else{/*MISRA C*/}
	return return_value;
}
void			I2C_Stop			(void)
{
	I2C.Control.TWCR_Reg = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
I2C_Error_t		I2C_Write			(uint8_t  Data, I2C_StatusCode_t Code)
{
	I2C_Error_t return_value = I2C_EN_Invalid;
	I2C.Data = Data;
	I2C.Control.TWCR_Reg = (1<<TWINT)|(1<<TWEN);
	return_value = TWI_Wait();
	if(return_value != I2C_EN_valid)
	{
		if(I2C.Status.status_code == Code)
		{
			return_value = I2C_EN_valid;
		}
		else{/*MISRA C*/}
	}
	else{/*MISRA C*/}
	return return_value;
}
I2C_Error_t		I2C_Read			(uint8_t* Data, I2C_StatusCode_t Code)
{	
	I2C_Error_t return_value = I2C_EN_Invalid;
	if(Data != NULL)
	{
		I2C.Control.TWCR_Reg = (1<<TWINT)|(1<<TWEN);
		if(I2C.Status.status_code == I2C_MR_DATA_ACK)
		{
			I2C.Control.TWCR_Bits.acknowledge = ENABLE;
		}
		else{/*MISRA C*/}
		return_value = TWI_Wait();
		if(return_value == I2C_EN_valid)
		{
			if(I2C.Status.status_code == Code)
			{
				*Data = I2C.Data;
				return_value = I2C_EN_valid;
			}
			else{/*MISRA C*/}
		}
		else{/*MISRA C*/}
	}
	else
	{
		return_value = I2C_EN_InvalidPointer;
	}
	return return_value;
}