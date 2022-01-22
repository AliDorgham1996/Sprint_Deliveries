#include "App.h"
#include "Indications.h"

static Car_StateMachine_t   CAR          = CAR_EN_Init;
static Car_StateMachine_t   CAR_Gear     = CAR_EN_Stop;
static uint8_t              speed    [3] = {PWM_EN_Duty_30, PWM_EN_Duty_60, PWM_EN_Duty_90};

static void Move_Update(void);
static void GEAR_Update(void);
static void APP_Apply(void);

void App_Init(void)
{
	Basic_io_init();
	BUTTON_init();
	MOTOR_INIT(Motor1);
	MOTOR_INIT(Motor2);	
	sei();
}

void App_Update(void)
{
	GEAR_Update();
	Move_Update();
	APP_Apply();
}

static void GEAR_Update(void)
{  
	BTN_State_t  BTN_value = BTN_LOW;
	BUTTON_READ (BUTTON_GEAR, &BTN_value);	
	if(BTN_value == BTN_HIGH)
	{
		do 
		{
			BUTTON_READ (BUTTON_GEAR, &BTN_value);
		} while(BTN_value == BTN_HIGH);
		
		switch (CAR_Gear)
		{
			case CAR_EN_Stop:
			{
				Led_only_on(Led0);
				CAR_Gear = CAR_EN_F_30;
			}break;
			case CAR_EN_F_30:
			{
				Led_only_on(Led1);
				CAR_Gear = CAR_EN_F_60;
			}break;
			case CAR_EN_F_60:
			{
				Led_only_on(Led2);
				CAR_Gear = CAR_EN_F_90;
			
			}break;
			case CAR_EN_F_90:
			{
				Led_only_on(Led3);
				CAR_Gear = CAR_EN_BACK;
			}break;
			case CAR_EN_BACK:
			{
				Led_only_on(Led0);
				CAR_Gear = CAR_EN_F_30;					
			}break;
			default:{/*MISRA C*/}break;
		}		
	}
	else{/*MISRA C*/}	
}
void Move_Update(void)
{  
	BTN_State_t  BTN_value = BTN_LOW;
	switch(CAR)
	{
		case CAR_EN_Init:
		{
			if(CAR_Gear == CAR_EN_F_30)
			{
				CAR = CAR_EN_Stop;
			}
			else{/*MISRA C*/}
		}break;	
		case CAR_EN_B_30:
		{
			//check transfer conditions
			BUTTON_READ (BUTTON_MOVE, &BTN_value);
			if(BTN_value == BTN_HIGH)
			{
				CAR = CAR_EN_B_30;
			}
			else
			{
				CAR = CAR_EN_Stop;
			}
		}break;
		case CAR_EN_B_R_30:
		{
			//check transfer conditions
			BUTTON_READ (BUTTON_RIGHT, &BTN_value);
			if(BTN_value == BTN_HIGH)
			{
				CAR = CAR_EN_B_R_30;
			}
			else
			{
				CAR = CAR_EN_Stop;
			}
		}break;
		case CAR_EN_B_L_30:
		{
			//check transfer conditions
			BUTTON_READ (BUTTON_LEFT, &BTN_value);
			if(BTN_value == BTN_HIGH)
			{
				CAR = CAR_EN_B_L_30;
			}
			else
			{
				CAR = CAR_EN_Stop;
			}
		}break;
		case CAR_EN_Move:
		{
			//check transfer conditions
			BUTTON_READ (BUTTON_MOVE, &BTN_value);
			if(BTN_value == BTN_HIGH)
			{
				CAR = CAR_EN_Move;
			}
			else
			{
				CAR = CAR_EN_Stop;
			}
		}break;
		case CAR_EN_Right:
		{
			//check transfer conditions
			BUTTON_READ (BUTTON_RIGHT, &BTN_value);
			if(BTN_value == BTN_HIGH)
			{
				CAR = CAR_EN_Right;
			}
			else
			{
				CAR = CAR_EN_Stop;
			}
		}break;
		case CAR_EN_Left:
		{
			//check transfer conditions
			BUTTON_READ (BUTTON_LEFT, &BTN_value);
			if(BTN_value == BTN_HIGH)
			{
				CAR = CAR_EN_Left;
			}
			else
			{
				CAR = CAR_EN_Stop;
			}
		}break;
		case CAR_EN_Stop :
		{
			if(CAR_Gear == CAR_EN_BACK)
			{
				//priority 1
				//check transfer conditions
				BUTTON_READ (BUTTON_MOVE, &BTN_value);
				if(BTN_value == BTN_HIGH)
				{
					CAR = CAR_EN_B_30;
				}
				else
				{
					//priority 2
					//check transfer conditions
					BUTTON_READ (BUTTON_RIGHT, &BTN_value);
					if(BTN_value == BTN_HIGH)
					{
						CAR = CAR_EN_B_R_30;
					}
					else
					{
						//priority 3
						//check transfer conditions
						BUTTON_READ (BUTTON_LEFT, &BTN_value);
						if(BTN_value == BTN_HIGH)
						{
							CAR = CAR_EN_B_L_30;
						}
						else
						{
							CAR = CAR_EN_Stop;
						}
					}
				}
			}
			else
			{
				//priority 1
				//check transfer conditions
				BUTTON_READ (BUTTON_MOVE, &BTN_value);
				if(BTN_value == BTN_HIGH)
				{
					CAR = CAR_EN_Move;
				}
				else
				{
					//priority 2
					//check transfer conditions
					BUTTON_READ (BUTTON_RIGHT, &BTN_value);
					if(BTN_value == BTN_HIGH)
					{
						CAR = CAR_EN_Right;
					}
					else
					{
						//priority 3
						//check transfer conditions
						BUTTON_READ (BUTTON_LEFT, &BTN_value);
						if(BTN_value == BTN_HIGH)
						{
							CAR = CAR_EN_Left;
						}
						else
						{
							CAR = CAR_EN_Stop;
						}
					}
				}
			}			
		}break;
		default:{/*MISRA C*/}break;
	}	
}


static void  APP_Apply(void)
{
	switch (CAR)
	{
		case CAR_EN_Stop:
		{
			MOTOR_Stop(Motor1);
			MOTOR_Stop(Motor2);
		}break;
		case CAR_EN_Move:
		{
			MOTOR_Direction(Motor1, MTR_DIR_CW, speed[CAR_Gear]);
			MOTOR_Direction(Motor2, MTR_DIR_CW, speed[CAR_Gear]);
		}break;
		case CAR_EN_Right:
		{
			MOTOR_Stop(Motor2);	
			MOTOR_Direction(Motor1, MTR_DIR_CW, speed[CAR_Gear]);	
		}break;
		case CAR_EN_Left:
		{
			MOTOR_Stop(Motor1);
			MOTOR_Direction(Motor2, MTR_DIR_CW, speed[CAR_Gear]);
		}break;
		case CAR_EN_B_30:
		{
			MOTOR_Direction(Motor1, MTR_DIR_ACW, PWM_EN_Duty_30);
			MOTOR_Direction(Motor2, MTR_DIR_ACW, PWM_EN_Duty_30);
		}break;
		case CAR_EN_B_R_30:
		{
			MOTOR_Stop(Motor1);
			MOTOR_Direction(Motor2, MTR_DIR_ACW, PWM_EN_Duty_30);
		}break;
		case CAR_EN_B_L_30:
		{
			MOTOR_Stop(Motor2);
			MOTOR_Direction(Motor1, MTR_DIR_ACW, PWM_EN_Duty_30);
		}break;
		default:{/*MISRA C*/}break;
	}
}