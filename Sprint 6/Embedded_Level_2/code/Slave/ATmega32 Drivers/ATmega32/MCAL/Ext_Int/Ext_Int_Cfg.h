#ifndef EXT_INT_CFG_H_
#define EXT_INT_CFG_H_

#include "../Library/Constants.h"
#include "../Library/Types_Defs.h"

typedef enum
{
	ExtInt_Start = 0,
	ExtInt_0 = ExtInt_Start,
	ExtInt_1,
	ExtInt_2,
	ExtInt_End
}ExtInt_t;

typedef enum
{
	ExtInt_EN_LowLevel,
	ExtInt_EN_AnyChange,
	ExtInt_EN_FalingEdge,
	ExtInt_EN_RisingEdge
}ExtInt_Sense_t;

typedef enum
{
	ExtInt_Disable,
	ExtInt_Enable
}ExtInt_Enanble_t;



#endif /* EXT_INT_CFG_H_ */