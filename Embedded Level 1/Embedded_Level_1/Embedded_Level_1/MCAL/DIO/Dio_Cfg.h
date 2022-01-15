#ifndef DIO_CFG_H
#define DIO_CFG_H

#include <stdint.h>
#include "../Library/Constants.h"

typedef enum
{
	DIO_EN_MIN_PORT,
	DIO_EN_Port_D = DIO_EN_MIN_PORT,
	DIO_EN_Port_C,
	DIO_EN_Port_B,
	DIO_EN_Port_A,
	DIO_EN_MAX_PORT
}DioPort_t;



typedef enum
{
	DIO_EN_MIN_Channel,
	
	DIO_EN_Channel_D_Base = DIO_EN_MIN_Channel,
	DIO_EN_Channel_D_0    = DIO_EN_Channel_D_Base,             
	DIO_EN_Channel_D_1,             
	DIO_EN_Channel_D_2,             
	DIO_EN_Channel_D_3,             
	DIO_EN_Channel_D_4,             
	DIO_EN_Channel_D_5,             
	DIO_EN_Channel_D_6,             
	DIO_EN_Channel_D_7,
	DIO_EN_Channel_D_End = DIO_EN_Channel_D_7,
	
	DIO_EN_Channel_C_Base,
	DIO_EN_Channel_C_0    = DIO_EN_Channel_C_Base,
	DIO_EN_Channel_C_1,
	DIO_EN_Channel_C_2,
	DIO_EN_Channel_C_3,
	DIO_EN_Channel_C_4,
	DIO_EN_Channel_C_5,
	DIO_EN_Channel_C_6,
	DIO_EN_Channel_C_7,
	DIO_EN_Channel_C_End = DIO_EN_Channel_C_7,
   
	DIO_EN_Channel_B_Base,
	DIO_EN_Channel_B_0    = DIO_EN_Channel_B_Base,
	DIO_EN_Channel_B_1,
	DIO_EN_Channel_B_2,
	DIO_EN_Channel_B_3,
	DIO_EN_Channel_B_4,
	DIO_EN_Channel_B_5,
	DIO_EN_Channel_B_6,
	DIO_EN_Channel_B_7,
	DIO_EN_Channel_B_End = DIO_EN_Channel_B_7,
	
	DIO_EN_Channel_A_Base,
	DIO_EN_Channel_A_0    = DIO_EN_Channel_A_Base,
	DIO_EN_Channel_A_1,
	DIO_EN_Channel_A_2,
	DIO_EN_Channel_A_3,
	DIO_EN_Channel_A_4,
	DIO_EN_Channel_A_5,
	DIO_EN_Channel_A_6,
	DIO_EN_Channel_A_7,
	DIO_EN_Channel_A_End = DIO_EN_Channel_A_7,
                
	DIO_EN_MAX_Channel = DIO_EN_Channel_A_End   
}DioChannel_t;


#define DIO_CHANNELS_PER_PORT       8U



typedef enum 
{
	DIO_EN_M_Input,
	DIO_EN_M_Output
}DioMode_t;

typedef enum
{
	DIO_EN_W_Low,
	DIO_EN_W_High,
	DIO_EN_W_Toggle	
}DioWrite_t;

typedef enum
{
	DIO_EN_S_Low,
	DIO_EN_S_High
}DioState_t;

//group
typedef uint8_t DioGroupValue_t;
typedef uint8_t DioGroupBits_t;

//port
typedef uint8_t DioPortValue_t;



#endif /* DIO_CFG_H */
