/*
 * Button.c
 *
 * Created: 1/4/2022 1:11:44 PM
 *  Author: Ali Dorgham
 */ 
/**************************************************************************************************
* User defined Libraries
***************************************************************************************************/

#include "Button.h"
#include "DIO.h"

/**************************************************************************************************
* Extern variables
***************************************************************************************************/

extern BTN_CFG_t  Arr_ST_Btn_cfg  [Btn_End];


/**************************************************************************************************
* Static Local variables
***************************************************************************************************/


/**************************************************************************************************
* implementations of extern functions
***************************************************************************************************/
/**************************************************************************************************
* BUTTON_init
***************************************************************************************************/
void                           BUTTON_init       (void)
{
	uint8_t  index = Btn_Start; 
	for(index = Btn_Start ; index < Btn_End ; index++)
	{
		/* 1. set the direction as input */
		DIO_setPinDirection (Arr_ST_Btn_cfg [index].PORT, Arr_ST_Btn_cfg [index].num_pin, DIO_u8_INPUT);
		/* 2. set pull-up resistor */
		//DIO_SetPullupRes(Arr_ST_Btn_cfg [index].PORT, Arr_ST_Btn_cfg [index].num_pin);
	}
	//for row2
	DIO_setPinDirection(PORTc, PIN3, DIO_u8_OUTPUT);
	DIO_writePinValue(PORTc,PIN3, DIO_u8_HIGH);
}

/**************************************************************************************************
* BUTTON_READ
***************************************************************************************************/

BUTTON_ERROR_state_t            BUTTON_READ       (EN_Button_t num, BTN_State_t * ptr_return_value)
{
	//return Error state
	BUTTON_ERROR_state_t return_value = Valid_BTN_init;
	/* 1. check if num is in correct range */
	if((num < Btn_Start) || (num > Btn_End))
	{
		return_value = Invalid_Num ;
	}
	else
	{	
		/* 2. check the return pointer is Valid */
		if(ptr_return_value == NULL)
		{
			return_value = Invalid_Pointer ;
		}
		else
		{
			/* 3. set the return value in the return pointer */
			DIO_readPin(Arr_ST_Btn_cfg [num].PORT, Arr_ST_Btn_cfg [num].num_pin, ptr_return_value);
		}
	}
	return return_value;
}

/**************************************************************************************************
* implementations of static functions
***************************************************************************************************/



/**************************************************************************************************
* End of file
***************************************************************************************************/