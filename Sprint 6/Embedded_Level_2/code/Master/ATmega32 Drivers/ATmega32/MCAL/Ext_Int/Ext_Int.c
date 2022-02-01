#include "../MCAL/Ext_Int/Ext_Int.h"
#include "../MCAL/Ext_Int/Ext_Int_Private.h"
#include "../Library/Constants.h"

_V _S V_CallBack_V_t ExtI_Callbacks [ExtInt_End] = {NULL};

ExtInt_Error_t     ExtI_Init(ExtInt_t num, ExtInt_Sense_t sense, V_CallBack_V_t callback)
{
	ExtInt_Error_t return_value = ExtInt_EN_valid;
	switch(num)
	{
		case ExtInt_0:
		{
			EXTI.Control.INT_0.Sense = sense;
		}
		break;
		case ExtInt_1:
		{
			EXTI.Control.INT_1.Sense = sense;
		}
		break;
		case ExtInt_2:
		{
			EXTI.Control.INT_2.Sense = sense;
		}
		break;
		default:
		{
			return ExtInt_EN_Invalid;
		}
		break;
	}
	ExtI_Callbacks[num] = callback;
	return return_value;
}
ExtInt_Error_t     ExtI_State(ExtInt_t num, ExtInt_Enanble_t state)
{
	ExtInt_Error_t return_value = ExtInt_EN_valid;
	switch(num)
	{
		case ExtInt_0:
		{
			EXTI.Enable.INT_0 = state;
		}
		break;
		case ExtInt_1:
		{
			EXTI.Enable.INT_1 = state;
		}
		break;
		case ExtInt_2:
		{
			EXTI.Enable.INT_2 = state;
		}
		break;
		default:
		{
			return_value = ExtInt_EN_Invalid;
		}
		break;
	}
	return return_value;	
}
ISR(INT0_vect)
{
	EXTI.Flag.INT_0 = ENABLE;
	if(ExtI_Callbacks[0] != NULL)
	{
		ExtI_Callbacks[0]();
	}
}
ISR(INT1_vect)
{
	EXTI.Flag.INT_1 = ENABLE;
	if(ExtI_Callbacks[1] != NULL)
	{
		ExtI_Callbacks[1]();
	}
}
ISR(INT2_vect)
{
	EXTI.Flag.INT_2 = ENABLE;
	if(ExtI_Callbacks[2] != NULL)
	{
		ExtI_Callbacks[2]();
	}
}