#include "../ECUAL/DC_Motor/DC_Motor.h"
#include "../Library/Constants.h" 

//incomplete data type
typedef enum
{
	Motor_Off,
	Motor_On
}MTR_State_t;

//extern variables
_E DioChannel_t       MTR_H1H2_CFG    [Mtr_End][MOTOR_H1H2];
_E PWM_CH_t			  MTR_PWM_CFG     [Mtr_End];
//static global variables
_S MTR_Dircetion_t    Motor_Direction [Mtr_End] = {Motor_CW, Motor_CW};
_S MTR_State_t        Motor_State     [Mtr_End] = {Motor_Off, Motor_Off};
//static functions
_S MOTOR_ERROR_state  Motor_Start	  (Motor_t   num , uint8_t Duty);



MOTOR_ERROR_state	Motor_Init     (Motor_t   num)
{
	MOTOR_ERROR_state   return_value   = Valid_MTR_init;
	/* check if num is in correct range */
	if((num < Mtr_Start) || (num > Mtr_End))
	{
		return_value   = Invalid_MTR_Num;
	}
	else
	{
		PWM_Init(MTR_PWM_CFG[num]);
		
		/* H1 Pin */
		/* set as output */
		Dio_ChannelMode(MTR_H1H2_CFG[num][MOTOR_H1], DIO_EN_M_Output);
		/* default value is off */
		Dio_ChannelWrite(MTR_H1H2_CFG[num][MOTOR_H1], DIO_EN_W_Low);
		
		/* H2 Pin */
		/* set as output */
		Dio_ChannelMode(MTR_H1H2_CFG[num][MOTOR_H2], DIO_EN_M_Output);
		/* default value is off */
		Dio_ChannelWrite(MTR_H1H2_CFG[num][MOTOR_H2], DIO_EN_W_Low);
	
		Motor_State [num] = Motor_Off;
	}
	return return_value;
}

MOTOR_ERROR_state 		Motor_RunDirection (Motor_t   num , MTR_Direction_t Direction, uint8_t Duty)
{
	MOTOR_ERROR_state   return_value   = Valid_MTR_init;
	/* check if num is in correct range */
	if((num < Mtr_Start) || (num > Mtr_End))
	{
		return_value   = Invalid_MTR_Num;
	}
	else
	{
		/* 1. stop the motor */
		Motor_Stop (num);
		
		/* 2. store the state for the next restart */
		Motor_Direction[num] = Direction;
		
		/* 3. stop the motor */
		Motor_Start (num , Duty);
	}
	return return_value;
}



MOTOR_ERROR_state 		Motor_Stop       (Motor_t   num )
{
	MOTOR_ERROR_state   return_value   = Valid_MTR_init;
	/* check if num is in correct range */
	if((num < Mtr_Start) || (num > Mtr_End))
	{
		return_value   = Invalid_MTR_Num;
	}
	else
	{
		PWM_Stop(MTR_PWM_CFG[num]);
		Dio_ChannelWrite(MTR_H1H2_CFG[num][MOTOR_H1], DIO_EN_W_Low);
		Dio_ChannelWrite(MTR_H1H2_CFG[num][MOTOR_H2], DIO_EN_W_Low);
			
		/* store the state for the next re-stop */
		Motor_State[num] = Motor_Off;
	}
	return return_value;
}


static MOTOR_ERROR_state 	Motor_Start (Motor_t   num , uint8_t Duty)
{
	MOTOR_ERROR_state   return_value   = Valid_MTR_init;
	/* check if num is in correct range */
	if((num < Mtr_Start) || (num > Mtr_End))
	{
		return_value   = Invalid_MTR_Num;
	}
	else
	{
		if(Motor_State[num] == Motor_Off)
		{
			if(Motor_Direction[num] == Motor_CW)
			{
				Dio_ChannelWrite(MTR_H1H2_CFG[num][MOTOR_H2], DIO_EN_W_Low);
				Dio_ChannelWrite(MTR_H1H2_CFG[num][MOTOR_H1], DIO_EN_W_High);
			}
			else
			{
				Dio_ChannelWrite(MTR_H1H2_CFG[num][MOTOR_H1], DIO_EN_W_Low);
				Dio_ChannelWrite(MTR_H1H2_CFG[num][MOTOR_H2], DIO_EN_W_High);
			}
			Motor_State[num] = Motor_On;
			PWM_DutyCycle(MTR_PWM_CFG[num], Duty);	
		}
	}
	return return_value;
}


/**************************************************************************************************
* End of file
***************************************************************************************************/