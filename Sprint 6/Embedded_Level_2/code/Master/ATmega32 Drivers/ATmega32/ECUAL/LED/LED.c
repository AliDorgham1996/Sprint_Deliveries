#include "../ECUAL/LED/LED.h"			


_E DioChannel_t  LED_Configuration  [LED_End];


void				  LED_init_All   (void)
{
	LED_t LED_Num = LED_Start;
	for(LED_Num = LED_Start; LED_Num < LED_End; LED_Num++)
	{
		LED_init(LED_Num);
	} 	
}
LEDError_t            LED_init       (LED_t LED_Num)
{
	LEDError_t return_value = LED_EN_valid_init;
	DioError_t    Dio_returnValue = DIO_EN_valid_inti;
	if((LED_Num >= LED_Start) && (LED_Num < LED_End))
	{
		/* 1. set the direction as output */
		Dio_returnValue	|= Dio_ChannelMode (LED_Configuration[LED_Num], DIO_EN_M_Output);
		/* 2. init value low */
		Dio_returnValue	|= Dio_ChannelWrite (LED_Configuration[LED_Num], DIO_EN_W_Low);
		if(Dio_returnValue != DIO_EN_valid_inti)
		{
			return_value = LED_EN_invalidNum;
		}
		else{/* MISRA C */}
	}
	else
	{
		return_value = LED_EN_invalidNum;
	}
	return return_value;
}
LEDError_t            LED_Only       (LED_t LED_Num, LED_State_t State)
{
	LEDError_t return_value = LED_EN_valid_init;
	if((State == LED_EN_ON) || (State == LED_EN_OFF))
	{
		if((LED_Num >= LED_Start) && (LED_Num < LED_End))
		{
			LED_t Local_LED_Num = LED_Start;
			for(Local_LED_Num = LED_Start; Local_LED_Num < LED_End; Local_LED_Num++)
			{
				LED_State(Local_LED_Num, ((LED_EN_OFF == State)?(LED_EN_ON):(LED_EN_OFF)));
			}
			LED_State(LED_Num, State);
		}
		else
		{
			return_value = LED_EN_invalidNum;
		}
	}
	else
	{
		return_value = LED_EN_invalidState;
	}
	return return_value;
}
LEDError_t            LED_State      (LED_t LED_Num, LED_State_t State)
{
	LEDError_t return_value = LED_EN_valid_init;
	DioError_t    Dio_returnValue = DIO_EN_valid_inti;
	if((LED_Num >= LED_Start) && (LED_Num < LED_End))
	{
		Dio_returnValue	= Dio_ChannelWrite (LED_Configuration[LED_Num], State);
		if(Dio_returnValue == DIO_EN_invalidState)
		{
			return_value = LED_EN_invalidState;
		}
		else{/* MISRA C */}
	}
	else
	{
		return_value = LED_EN_invalidNum;
	}
	return return_value;
}
LEDError_t            LED_State_All      (LED_State_t State)
{
	LEDError_t return_value = LED_EN_valid_init;
	if((State == LED_EN_ON) || (State == LED_EN_OFF) || (State == LED_EN_Toggle))
	{
		LED_t Local_LED_Num = LED_Start;
		for(Local_LED_Num = LED_Start; Local_LED_Num < LED_End; Local_LED_Num++)
		{
			LED_State(Local_LED_Num, State);
		}
	}
	else
	{
		return_value = LED_EN_invalidState;
	}
	return return_value;
}