#include "../MCAL/I2C/I2C.h"
#include "../MCAL/I2C/I2C_Private.h"
#include "../Library/Configurations.h"
#include "../Library/Constants.h"

void			I2C_Wait		(void);
void			I2C_Wait		(void)//done
{
	I2C.Control.TWCR_Reg |= (1<<TWINT);
	while((I2C.Control.TWCR_Bits.interrupt_flag == 0));
}
void            I2C_init		(uint32_t Speed)//done
{
	I2C.Status.prescaler             = I2C_SPEED;
	I2C.Address.slave_address        = I2C_SLAVE_ADDRESS;
	I2C.BitRate                      = ((F_CPU/Speed) - 16)/(2*I2C_TWBR);
	I2C.Control.TWCR_Bits.i2c_enable = ENABLE;
}
I2C_Error_t     I2C_Start		(void)//done
{
	I2C_Error_t return_value = I2C_EN_Invalid;
	I2C.Control.TWCR_Reg = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	I2C_Wait();
	if(I2C.Status.status_code == I2C_SC_START)
	{
		return_value = I2C_EN_valid;
	}
	else if(I2C_M_LOSE_ARBIT == I2C.Status.status_code)
	{
		return_value = I2C_EN_LoseArbitration;
	}
	else
	{
		return_value = I2C_EN_InvalidCode;
	}
	return return_value;
}
I2C_Error_t     I2C_Restart		(void)//done
{
	I2C_Error_t return_value = I2C_EN_Invalid;
	I2C.Control.TWCR_Reg = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	if(I2C.Status.status_code == I2C_SC_RESTART)
	{
		return_value = I2C_EN_valid;
	}
	else
	{
		return_value = I2C_EN_InvalidCode;
	}
	return return_value;
}
void			I2C_Stop		(void)//done
{
	I2C.Control.TWCR_Reg = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
I2C_Error_t		I2C_Listen      (void)//done
{
	I2C_Error_t return_value = I2C_EN_Invalid;
	I2C.Control.TWCR_Reg = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	I2C_Wait();
	if(STATUS_CODE_SLAVE_R)
	{
		return_value = I2C_EN_SlaveTransmit;
	}
	else if(STATUS_CODE_SLAVE_W)
	{
		return_value = I2C_EN_SlaveReceive;
	}
	else
	{
		return_value = I2C_EN_Invalid;
	}
	return return_value;
}
I2C_Error_t		I2C_Write		(uint8_t  Data, I2C_StatusCode_t Code)//done
{
	I2C_Error_t return_value = I2C_EN_Invalid;
	I2C.Data = Data;
	I2C.Control.TWCR_Reg = (1<<TWINT)|(1<<TWEN);
	if(Code == I2C_ST_DATA_ACK)//for slave transmit
	{
		I2C.Control.TWCR_Bits.acknowledge = ENABLE;
	}
	else
	{
		I2C.Control.TWCR_Bits.acknowledge = DISABLE;
	}
	I2C_Wait();
	if(I2C.Status.status_code == Code)
	{
		return_value = I2C_EN_valid;
	}
	else if (I2C_M_LOSE_ARBIT == I2C.Status.status_code)
	{
		return_value = I2C_EN_LoseArbitration;
	}
	else
	{
		return_value = I2C_EN_InvalidCode;
	}
	return return_value;
}
I2C_Error_t		I2C_Read		(uint8_t* Data, I2C_StatusCode_t Code)//done
{
	I2C_Error_t return_value = I2C_EN_valid;
	if(Data != NULL)
	{
		I2C.Control.TWCR_Reg = (1<<TWEN)|(1<<TWINT);
		if(STATUS_CODE_ENABLE_ACK)
		{
			I2C.Control.TWCR_Bits.acknowledge = ENABLE;
		}
		else
		{
			I2C.Control.TWCR_Bits.acknowledge = DISABLE;
		}
		I2C_Wait();
		if(I2C.Status.status_code == Code)
		{
			*Data = I2C.Data;
		}
		else
		{
			return_value = I2C_EN_InvalidCode;
		}
	}
	else
	{
		return_value = I2C_EN_InvalidPointer;
	}
	return return_value;
}