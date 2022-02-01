#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#include "../Library/PrivateMacros.h"
#include "../Library/Constants.h"
#include <stdint.h>


typedef struct
{	
	uint8_t Clock			:2;
	uint8_t phase			:1;
	uint8_t polarity		:1;
	uint8_t Type			:1;
	uint8_t Data_Order		:1;
	uint8_t Enable			:1;
	uint8_t Interrupt		:1;
}_V SPCR_t;


typedef struct
{
	uint8_t doublespeed     :1;
	uint8_t					:5;
	uint8_t write_collision :1;
	uint8_t interrupt_flag  :1;
}_V SPSR_t;


typedef struct
{
	SPCR_t	  Control;
	SPSR_t    Status;
	uint8_t   Data;
}_V SPI_REG_t;

typedef SPI_REG_t*    SPI_PTRREG_t;

#define SPI   spi_(SPI_PTRREG_t)


#endif /* SPI_PRIVATE_H_ */