#include "../ECUAL/EEPROM/I2C_EEPROM/I2C_EEPROM.h"
#include "../MCAL/DIO/Dio.h"
#include <string.h>
#include "../Library/System_Delays/Delays.h"

I2C_EEPROM_Error_t		I2C_EEPROM_Write	(uint16_t Address, uint8_t Data);
I2C_EEPROM_Error_t		I2C_EEPROM_Write	(uint16_t Address, uint8_t Data)
{
	I2C_EEPROM_Error_t return_value = I2C_EEPROM_valid;
	return_value |= I2C_Start();
	return_value |= I2C_Write(I2C_EEPROM_SLA_W, I2C_MT_SLAW_ACK);
	return_value |= I2C_Write((uint8_t)(Address>>8), I2C_MT_DATA_ACK);
	return_value |= I2C_Write((uint8_t)Address, I2C_MT_DATA_ACK);
	return_value |= I2C_Write(Data, I2C_MT_DATA_ACK);
	I2C_Stop();
	return return_value;
}
void		I2C_EEPROM_init		(void)
{
	I2C_init(I2C_EEPROM_SPEED);
	Delay_Ms(I2C_EEPROM_DELAY_MS);
}
I2C_EEPROM_Error_t		I2C_EEPROM_Update	(uint16_t Address, uint8_t  Data)
{
	I2C_EEPROM_Error_t return_value = I2C_EEPROM_valid;
	uint8_t LocalData ;
	return_value = I2C_EEPROM_Read(Address, &LocalData);
	if(return_value == I2C_EEPROM_valid)
	{
		if(LocalData != Data)
		{
			Delay_Ms(6);
			return_value = I2C_EEPROM_Write(Address, Data);
		}
		else{/*MISRA C*/}
	}
	else
	{
		return_value = I2C_EEPROM_InvalidRead;
	}
	return return_value;
}
I2C_EEPROM_Error_t		I2C_EEPROM_Read		(uint16_t Address, uint8_t* Data)
{
	I2C_EEPROM_Error_t return_value = I2C_EEPROM_valid;
	if(Data != NULL)
	{
		return_value |= I2C_Start();
		return_value |= I2C_Write(I2C_EEPROM_SLA_W, I2C_MT_SLAW_ACK);
		return_value |= I2C_Write((uint8_t)(Address>>8), I2C_MT_DATA_ACK);
		return_value |= I2C_Write((uint8_t)Address, I2C_MT_DATA_ACK);
		return_value |= I2C_Start();
		return_value |= I2C_Write(I2C_EEPROM_SLA_R, I2C_MT_SLAW_ACK);
		return_value |= I2C_Read(Data, I2C_MR_DATA_NOACK);
		I2C_Stop();
	}
	else
	{
		return_value = I2C_EEPROM_InvalidPointer;
	}
	
	return return_value;
}
I2C_EEPROM_Error_t	I2C_EEPROM_ReadPage		(uint16_t Address, uint8_t* Data, uint16_t size)
{
	I2C_EEPROM_Error_t return_value = I2C_EEPROM_valid;
	if(Data != NULL)
	{
		uint16_t index = 0;
		return_value |= I2C_Start();
		return_value |= I2C_Write(I2C_EEPROM_SLA_W, I2C_MT_SLAW_ACK);
		return_value |= I2C_Write((uint8_t)(Address>>8), I2C_MT_DATA_ACK);
		return_value |= I2C_Write((uint8_t)Address, I2C_MT_DATA_ACK);
		return_value |= I2C_Start();
		return_value |= I2C_Write(I2C_EEPROM_SLA_R, I2C_MT_SLAW_ACK);
		for(index = 0; index < size-1; index++)
		{
			return_value |= I2C_Read(&Data[index], I2C_MR_DATA_ACK);
		}
		return_value |= I2C_Read(Data[index], I2C_MR_DATA_NOACK);
		I2C_Stop();	
	}
	else
	{
		return_value = I2C_EEPROM_InvalidPointer;
	}
	return return_value;
}
I2C_EEPROM_Error_t	I2C_EEPROM_WritePage	(uint16_t Address, uint8_t* Data)
{
	I2C_EEPROM_Error_t return_value = I2C_EEPROM_valid;
	if(Data != NULL)
	{
		uint16_t size = strlen(Data);
		uint8_t index = 0;
		return_value |= I2C_Start();
		return_value |= I2C_Write(I2C_EEPROM_SLA_W, I2C_MT_SLAW_ACK);
		return_value |= I2C_Write((uint8_t)(Address>>8), I2C_MT_DATA_ACK);
		return_value |= I2C_Write((uint8_t)Address, I2C_MT_DATA_ACK);
		for(index = 0; index < size; index++)
		{
			//return_value |= I2C_EEPROM_Update(Data[index], I2C_MT_DATA_ACK);
			return_value |= I2C_Write(Data[index], I2C_MT_DATA_ACK);
		}
		I2C_Stop();
	}
	else
	{
		return_value = I2C_EEPROM_InvalidPointer;
	}
	return return_value;
}