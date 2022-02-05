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
void		    SPI_Send	        (uint8_t Data)
{
	SPI.Data = Data;
	while((SPI.Status.interrupt_flag == 0));
}
uint8_t		    SPI_Receive			(void)
{
	while((SPI.Status.interrupt_flag == 0));
	return SPI.Data;
}
SPI_Error_t		SPI_SendString	    (uint8_t* Data)
{
	SPI_Error_t return_value = SPI_EN_valid;
	uint32_t index   = 0;
	if(Data != NULL)
	{
		for(index = 0; Data[index] != '\0' ; index++)
		{
			SPI_Send(Data[index]);
		}
		SPI_Send('\0');
	}
	else
	{
		return_value = SPI_EN_InvalidPointer;
	}
	return return_value;
}
SPI_Error_t	   SPI_RecieveString		(uint8_t* Data, uint8_t term)
{
	SPI_Error_t return_value = SPI_EN_valid;
	uint32_t index   = 0;
	if(Data != NULL)
	{
		for(index = 0; ; index++)
		{
			Data[index] = SPI_Receive();
			if(Data[index] == term)
			{
				break;
			}
		}
	}
	else
	{
		return_value = SPI_EN_InvalidPointer;
	}
	return return_value;
}