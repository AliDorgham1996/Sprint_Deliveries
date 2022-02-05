#ifndef I2C_CFG_H_
#define I2C_CFG_H_

#include "../Library/Types_Defs.h"

#define I2C_SLAVE_ADDRESS     0x01

typedef enum
{
	/* Control Status Codes */
	I2C_SC_START         = 0x01,//08
	I2C_SC_RESTART       = 0x02,//10
	I2C_SC_STOP          = 0x14,//a0
	/*******************************/
	/* Master */
	I2C_M_LOSE_ARBIT	 = 0x07,//38
	// Transmit Codes	 
	// Address			 
	I2C_MT_SLAW_ACK		 = 0x03,//18
	I2C_MT_SLAW_NOACK	 = 0x04,//20
	// Data				 
	I2C_MT_DATA_ACK		 = 0x05,//28
	I2C_MT_DATA_NOACK	 = 0x06,//30
	// Receive Codes 	 
	// Address			 
	I2C_MR_SLAR_ACK		 = 0x08,//40
	I2C_MR_SLAR_NOACK	 = 0x09,//48
	// Data				 
	I2C_MR_DATA_ACK		 = 0x0A,//50
	I2C_MR_DATA_NOACK	 = 0x0B,//58
	/*******************************/
	/* Slave */
	// Transmit Data Codes
	I2C_ST_DATA_ACK      = 0x17,//b8
	I2C_ST_DATA_NOACK    = 0x18,//c0
    // Receive Data Codes
	I2C_SR_DATA_ACK      = 0x10,//80
	I2C_SR_DATA_NOACK	 = 0x11,//88
	// Listen Own Address Codes
	// Slave is receiving
	I2C_S_OwnAd_R1_ACK   = 0x0C,//60 
	I2C_S_OwnAd_R2_ACK   = 0x0D,//68
	// Slave will transmit
	I2C_S_OwnAd_W1_ACK   = 0x15,//a8
	I2C_S_OwnAd_W2_ACK   = 0x16 //b0
}I2C_StatusCode_t;

#define STATUS_CODE_ENABLE_ACK ( (Code == I2C_MR_DATA_ACK)\
							   ||(Code == I2C_SR_DATA_ACK))

#define STATUS_CODE_SLAVE_R    ( (I2C.Status.status_code == I2C_S_OwnAd_R1_ACK)\
							   ||(I2C.Status.status_code == I2C_S_OwnAd_R2_ACK))

#define STATUS_CODE_SLAVE_W    ( (I2C.Status.status_code == I2C_S_OwnAd_W1_ACK)\
							   ||(I2C.Status.status_code == I2C_S_OwnAd_W2_ACK))


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