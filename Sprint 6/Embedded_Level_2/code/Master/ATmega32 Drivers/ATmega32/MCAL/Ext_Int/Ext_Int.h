#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "../MCAL/Ext_Int/Ext_Int_Cfg.h"
#include <avr/interrupt.h>

typedef enum
{
	ExtInt_EN_valid,
	ExtInt_EN_Invalid
}ExtInt_Error_t;

ExtInt_Error_t     ExtI_Init(ExtInt_t num, ExtInt_Sense_t sense, V_CallBack_V_t callback);
ExtInt_Error_t     ExtI_State(ExtInt_t num, ExtInt_Enanble_t state);


#endif /* EXT_INT_H_ */