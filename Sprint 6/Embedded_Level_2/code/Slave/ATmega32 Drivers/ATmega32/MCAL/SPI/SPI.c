#include "../MCAL/SPI/SPI.h"
#include "../MCAL/SPI/SPI_Private.h"
#include "../Library/Constants.h"
#include "../Library/Registers.h"
#include <string.h>


void			SPI_Init			(SPI_t Type)
{
	DDRB7				   = Type;    //SCK
	DDRB6				   = (Type+1);//MISO
	DDRB5				   = Type;    //MOSI
	DDRB4				   = Type;    //SS!
	SPI.Control.Clock      = SPI_CLOCK;
	SPI.Status.doublespeed = SPI_CLOCK/3;
	SPI.Control.Data_Order = SPI_ORDER;
	SPI.Control.phase      = SPI_PHASE;
	SPI.Control.polarity   = SPI_PPLARITY;
	SPI.Control.Type       = Type;
	SPI.Control.Enable     = ENABLE;
}
uint8_t		    SPI_Transceive	    (uint8_t Data)
{
	uint32_t timeout = 0;
	SPI.Data = Data;
	while((SPI.Status.interrupt_flag == 0) && (timeout <= SPI_TIMEOUT))
	{
		timeout++;
	}
	
	if(SPI.Status.interrupt_flag == 1)
	{
		return SPI_DUMMY;
	}
	else{/*MISRA C*/}
	return SPI.Data;
}
SPI_Error_t		SPI_SendString	    (uint8_t* Data)
{
	SPI_Error_t return_value = SPI_EN_valid;
	uint32_t timeout = 0;
	uint32_t index   = 0;
	uint32_t size = strlen(Data);
	if(Data != NULL)
	{
		for(index = 0; index < size; index++)
		{
			SPI.Data = Data[index];
			while((SPI.Status.interrupt_flag == 0) && (timeout <= SPI_TIMEOUT))
			{
				timeout++;
			}
			
			if(SPI.Status.interrupt_flag == 1)
			{
				return_value = SPI_EN_Invalid_TIMEOUT;
				break;
			}
			else{/*MISRA C*/}
		}
	}
	else
	{
		return_value = SPI_EN_InvalidPointer;
	}
	return return_value;
}
SPI_Error_t	   SPI_RecieveString		(uint8_t* Data, uint32_t size)
{
	SPI_Error_t return_value = SPI_EN_valid;
	uint32_t timeout = 0;
	uint32_t index   = 0;
	if(Data != NULL)
	{
		for(index = 0; index < size; index++)
		{
			SPI.Data = SPI_DUMMY;
			while((SPI.Status.interrupt_flag == 0) && (timeout <= SPI_TIMEOUT))
			{
				timeout++;
			}
			
			if(SPI.Status.interrupt_flag == 1)
			{
				return_value = SPI_EN_Invalid_TIMEOUT;
				break;
			}
			else			
			{
				SPI.Data = Data[index];
			}
		}
	}
	else
	{
		return_value = SPI_EN_InvalidPointer;
	}
	return return_value;
}