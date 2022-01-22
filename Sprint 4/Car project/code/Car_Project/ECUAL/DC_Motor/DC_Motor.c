/*
 * DC_Motor.c
 *
 * Created: 1/4/2022 1:11:44 PM
 *  Author: Ali Dorgham
 */ 


/**************************************************************************************************
* User defined Libraries
***************************************************************************************************/

#include "DC_Motor.h"
#include "DIO.h"
#include "DC_Motor_cfg.h"
#include "Library.h"
#include "PWM.h" 

/**************************************************************************************************
* Extern variables
***************************************************************************************************/
extern MTR_CFG_t  Arr_ST_Mtr_cfg  [Mtr_End];
extern PWM_ID   MTR_PWM_CFG    [Mtr_End];

static MOTOR_ERROR_state 		MOTOR_Start		(Motor_t   num , uint8_t Duty);
/**************************************************************************************************
* Incomplete data types
***************************************************************************************************/
typedef enum 
{
	Motor_Off,
	Motor_On
}MTR_State_t;

typedef enum 
{
	Motor_CW,  /* H1 is on , H2 is off */
	Motor_ACW,  /* H2 is on , H1 is off */
    Motor_CWACW_init
}MTR_Dircetion_t;

/**************************************************************************************************
* Static Local variables
***************************************************************************************************/
#define InvalidDuty   0xFF

static MTR_Dircetion_t   Motor_Direction [Mtr_End] = {Motor_CWACW_init, Motor_CWACW_init};
static MTR_State_t       Motor_State     [Mtr_End] = {Motor_Off, Motor_Off};
static uint8_t           motorspeed      [Mtr_End] = {0,0};


/**************************************************************************************************
* implementations of extern functions
***************************************************************************************************/

/**************************************************************************************************
* MOTOR_INIT
***************************************************************************************************/

void	MOTOR_INIT     (Motor_t   num)
{
	PWM_Init(num);
		
	/* H1 Pin */
	/* set as output */
	DIO_setPinDirection(Arr_ST_Mtr_cfg[num][MOTOR_H1].PORT, Arr_ST_Mtr_cfg[num][MOTOR_H1].num_pin, DIO_u8_OUTPUT);
	/* default value is off */
	DIO_writePinValue(Arr_ST_Mtr_cfg[num][MOTOR_H1].PORT, Arr_ST_Mtr_cfg[num][MOTOR_H1].num_pin, DIO_u8_LOW);
		
	/* H2 Pin */
	/* set as output */
	DIO_setPinDirection(Arr_ST_Mtr_cfg[num][MOTOR_H2].PORT, Arr_ST_Mtr_cfg[num][MOTOR_H2].num_pin, DIO_u8_OUTPUT);
	/* default value is off */
	DIO_writePinValue(Arr_ST_Mtr_cfg[num][MOTOR_H2].PORT, Arr_ST_Mtr_cfg[num][MOTOR_H2].num_pin, DIO_u8_LOW);
	
	Motor_State    [num] = Motor_Off;
	motorspeed     [num] = InvalidDuty;
	Motor_Direction[num] = Motor_CWACW_init;	
}

MOTOR_ERROR_state 		MOTOR_Direction (Motor_t   num , MTR_Direction_t Direction, uint8_t Duty)
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
			motorspeed[num] = Duty;
			Motor_Direction[num] = Direction;
			MOTOR_Start (num , Duty);
			Motor_State[num] = Motor_On;
		}
		else if (Motor_State[num]== Motor_On)
		{
			if(Motor_Direction[num] != Direction)
			{
				motorspeed[num] = Duty;
				Motor_Direction[num] = Direction;
				Motor_State[num] == Motor_Off;
				MOTOR_Start (num , Duty);
				Motor_State[num] = Motor_On;
			}
			else if(Motor_Direction[num] == Direction)
			{
				if(motorspeed[num] != Duty)
				{
					motorspeed[num] = Duty;
					Motor_Direction[num] = Direction;
					Motor_State[num] == Motor_Off;
					MOTOR_Start (num , Duty);
					Motor_State[num] = Motor_On;
				}
			}
		}
	}
	return return_value;
}

/**************************************************************************************************
* MOTOR_Start
***************************************************************************************************/

static MOTOR_ERROR_state 		MOTOR_Start (Motor_t   num , uint8_t Duty)
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
				DIO_writePinValue(Arr_ST_Mtr_cfg[num][MOTOR_H2].PORT, Arr_ST_Mtr_cfg[num][MOTOR_H2].num_pin, DIO_u8_LOW);
				DIO_writePinValue(Arr_ST_Mtr_cfg[num][MOTOR_H1].PORT, Arr_ST_Mtr_cfg[num][MOTOR_H1].num_pin, DIO_u8_HIGH);
			}
			else if(Motor_Direction[num] == Motor_ACW)
			{
				DIO_writePinValue(Arr_ST_Mtr_cfg[num][MOTOR_H1].PORT, Arr_ST_Mtr_cfg[num][MOTOR_H1].num_pin, DIO_u8_LOW);
				DIO_writePinValue(Arr_ST_Mtr_cfg[num][MOTOR_H2].PORT, Arr_ST_Mtr_cfg[num][MOTOR_H2].num_pin, DIO_u8_HIGH);
			}
		}
		SET_PWM_DutyCycle(MTR_PWM_CFG[num], Duty);
	}
	return return_value;
}

/**************************************************************************************************
* MOTOR_Stop
***************************************************************************************************/


MOTOR_ERROR_state 		MOTOR_Stop       (Motor_t   num )
{
	MOTOR_ERROR_state   return_value   = Valid_MTR_init;
	/* check if num is in correct range */
	if((num < Mtr_Start) || (num > Mtr_End))
	{
		return_value   = Invalid_MTR_Num;
	}
	else
	{
		/* 2. start the motor! */
		PWM_Stop(MTR_PWM_CFG[num]);
		//SET_PWM_DutyCycle(num, 0);
		DIO_writePinValue(Arr_ST_Mtr_cfg[num][MOTOR_H1].PORT, Arr_ST_Mtr_cfg[num][MOTOR_H1].num_pin, DIO_u8_LOW);
		DIO_writePinValue(Arr_ST_Mtr_cfg[num][MOTOR_H2].PORT, Arr_ST_Mtr_cfg[num][MOTOR_H2].num_pin, DIO_u8_LOW);
		
		/* 2. store the state for the next re-stop */
		Motor_State[num]     = Motor_Off;
		motorspeed[num]      = InvalidDuty;
		Motor_Direction[num] = Motor_CWACW_init;
		PWM_Stop(num);
	}
	return return_value;
}

/**************************************************************************************************
* End of file
***************************************************************************************************/