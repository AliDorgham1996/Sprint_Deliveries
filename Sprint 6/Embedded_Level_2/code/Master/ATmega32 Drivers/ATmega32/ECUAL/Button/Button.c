#include "../ECUAL/Button/Button.h"
#include "../Library/System_Delays/Delays.h"

_E BTN_Configuration_t  BTN_Configuration  [Btn_End];


ButtonError_t            BUTTON_init       (Button_t BTN_Num)
{
	ButtonError_t return_value = BTN_EN_valid_init;
	DioError_t    Dio_returnValue = DIO_EN_valid_inti;
	if((BTN_Num >= Btn_Start) && (BTN_Num < Btn_End))
	{
		/* 1. set the direction as input */
		Dio_returnValue	|= Dio_ChannelMode (BTN_Configuration[BTN_Num].Channel, DIO_EN_M_Input);
		/* 2. set pull-up resistor */
		if(BTN_Configuration[BTN_Num].Resistor == BTN_EN_Pull_Up)
		{
			Dio_returnValue	|= Dio_ChannelPullUp (BTN_Configuration[BTN_Num].Channel);
		}
		else{ /* MISRA C */ }
			
		if(Dio_returnValue != DIO_EN_valid_inti)
		{
			return_value = BTN_EN_invalidNum;
		}
		else{ /* MISRA C */ }
	}
	else
	{
		return_value = BTN_EN_invalidNum;
	}
	return return_value;
}



ButtonError_t            BUTTON_IsPressed       (Button_t BTN_Num, BTN_State_t * State)
{
	ButtonError_t return_value = BTN_EN_valid_init;
	DioState_t    PrevState   = DIO_EN_S_Low; 
	DioState_t   CurrentState = DIO_EN_S_Low; 
	if((BTN_Num >= Btn_Start) && (BTN_Num < Btn_End))
	{
		if(State != NULL)
		{
			Dio_ChannelRead(BTN_Configuration[BTN_Num].Channel, &PrevState);
			Delay_Ms(BUTTON_DEBOUNCING_MS);
			Dio_ChannelRead(BTN_Configuration[BTN_Num].Channel, &CurrentState);
			if(CurrentState == PrevState)
			{
				if(BTN_Configuration[BTN_Num].Resistor == BTN_EN_Pull_Down)
				{
					if(CurrentState == DIO_EN_S_Low)
					{
						*State = BTN_NotPressed;
					}
					else
					{
						*State = BTN_IS_Pressed;
					}
				}
				else
				{
					if(CurrentState == DIO_EN_S_High)
					{
						*State = BTN_NotPressed;
					}
					else
					{
						*State = BTN_IS_Pressed;
					}
				}	
			}
			else
			{
				*State = BTN_NotPressed;
			}
		}		
		else
		{
			return_value = BTN_EN_invalidPointer;
		}
	}
	else
	{
		return_value = BTN_EN_invalidNum;
	}
	return return_value;
}