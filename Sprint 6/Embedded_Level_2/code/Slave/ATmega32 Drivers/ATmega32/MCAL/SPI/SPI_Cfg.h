#ifndef SPI_CFG_H_
#define SPI_CFG_H_

#include <stdint.h>
#include "../Library/Constants.h"
#include "../Library/Types_Defs.h"

#define SPI_DUMMY			0x00
#define SPI_TIMEOUT         5000UL


typedef enum
{
	SPI_EN_Slave,	
	SPI_EN_Master
}SPI_t;

typedef enum
{
	SPI_F_4, 
	SPI_F_16, 
	SPI_F_64, 
	SPI_F_128,
	SPI_F_2,
	SPI_F_8,
	SPI_F_32
}SPI_Clock_t;
#define SPI_CLOCK      SPI_F_4

typedef enum
{
	SPI_SAMPLE_at_LEADING, 
	SPI_SAMPLE_at_TRAILING
}SPI_CLK_Phase_t;
#define SPI_PHASE      SPI_SAMPLE_at_LEADING

typedef enum
{
	SPI_LEADING_TRAILING, 
	SPI_TRAILING_LEADING
}SPI_CLK_Polar_t;
#define SPI_PPLARITY   SPI_LEADING_TRAILING

typedef enum
{
	SPI_MSB_First,
	SPI_LSB_First
}SPI_Order_t;
#define SPI_ORDER      SPI_MSB_First

typedef struct
{
	SPI_t             Type;
	SPI_Clock_t       Clock;
	SPI_CLK_Phase_t   Phase;
	SPI_CLK_Polar_t   Polarity;
	SPI_Order_t       Data_Order;
}SPI_CFG_t;

#endif /* SPI_CFG_H_ */