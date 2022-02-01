#ifndef I2C_CFG_H_
#define I2C_CFG_H_

#include "../Library/Types_Defs.h"

#define I2C_TIME_OUT          5000UL
#define I2C_SLAVE_ADDRESS     0x01

typedef enum
{
	/* Control Status Codes */
	I2C_START         = 0x01,
	I2C_RESTART       = 0x02,
	/* Master Transmit Codes */
	I2C_MT_SLAW_ACK   = 0x03,//0011
	I2C_MT_SLAW_NOACK = 0x04,//0100
	I2C_MT_DATA_ACK   = 0x05,//0101
	I2C_MT_DATA_NOACK = 0x06,//0110
	/* Master Receive Codes */
	I2C_MR_SLAR_ACK   = 0x08,//1000
	I2C_MR_SLAR_NOACK = 0x09,//1001
	I2C_MR_DATA_ACK   = 0x0A,//1010
	I2C_MR_DATA_NOACK = 0x0B //1011
}I2C_StatusCode_t;

typedef enum
{
	I2C_F_1, 
	I2C_F_4, 
	I2C_F_16, 
	I2C_F_64
}I2C_Clock_t;
#define I2C_SPEED			I2C_F_1 

#if (I2C_SPEED == I2C_F_1)
	#define I2C_TWBR		1
#elif (I2C_SPEED == I2C_F_4)
	#define I2C_TWBR		4
#elif (I2C_SPEED == I2C_F_16)
	#define I2C_TWBR		16
#elif (I2C_SPEED == I2C_F_64)
	#define I2C_TWBR		64
#endif /* I2C_TWBR */

#endif /* I2C_CFG_H_ */