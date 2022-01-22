#include "../ECUAL/DC_Motor/DC_Motor.h"
#include "../Library/System_Delays/Delays.h"
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
_S MTR_Dircetion_t    Motor_Direction [Mtr_End] = {Motor_CWACW_init, Motor_CWACW_init};
_S MTR_State_t        Motor_State     [Mtr_End] = {Motor_Off, Motor_Off};
_S uint8_t            Motor_Speed     [Mtr_End] = {0,0};
//static functions
_S MOTOR_ERROR_state  Motor_Start	  (Motor_t   num);


/**************************************************************************************************
* Motor_Init
***************************************************************************************************/

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
		/* EN Pin */
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
	
		Motor_State    [num] = Motor_Off;
		Motor_Speed    [num] = 0;
		Motor_Direction[num] = Motor_CWACW_init;
	}
	return return_value;
}

/**************************************************************************************************
* Motor_RunDirection
***************************************************************************************************/
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
		if(Motor_State[num]== Motor_Off)
		{
			Motor_Speed[num]     = Duty;
			Motor_Direction[num] = Direction;
			Motor_Start(num);
		}
		else if (Motor_State[num]== Motor_On)
		{
			if(Motor_Direction[num] != Direction)
			{
				Motor_Speed[num]     = Duty;
				Motor_Direction[num] = Direction;
				Motor_Stop(num);
				Delay_Ms(MTR_RESTART_TIME_MS);
				Motor_Start(num);
			}
			else if(Motor_Direction[num] == Direction)
			{
				if(Motor_Speed[num] != Duty)
				{
					Motor_Speed[num]     = Duty;
					Motor_Direction[num] = Direction;
					Motor_Start(num);
				}
			}
		}
	}
	return return_value;
}

/**************************************************************************************************
* Motor_Stop
***************************************************************************************************/

MOTOR_ERROR_state 		Motor_Stop       (Motor_t   num)
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
		Motor_State[num]     = Motor_Off;
		Motor_Speed[num]     = 0;
		Motor_Direction[num] = Motor_CWACW_init;
		PWM_Stop(num);
	}
	return return_value;
}

/**************************************************************************************************
* Motor_Start
***************************************************************************************************/
_S MOTOR_ERROR_state 	Motor_Start (Motor_t   num)
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
		}
		else{/*MISRA C*/}
		PWM_DutyCycle(MTR_PWM_CFG[num], Motor_Speed[num]);
	}
	return return_value;
}


/**************************************************************************************************
* End of file
***************************************************************************************************/