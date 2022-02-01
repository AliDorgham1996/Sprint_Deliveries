#ifndef SPI_H_
#define SPI_H_

#include "../MCAL/SPI/SPI_Cfg.h"

typedef enum
{
	SPI_EN_valid,
	SPI_EN_InvalidPointer,
	SPI_EN_Invalid_TIMEOUT
}SPI_Error_t;

void			SPI_Init			(SPI_t    Type);
uint8_t			SPI_Transceive		(uint8_t  Data);
SPI_Error_t		SPI_SendString	    (uint8_t* Data);
SPI_Error_t		SPI_RecieveString   (uint8_t* Data, uint32_t size);




#endif /* SPI_H_ */