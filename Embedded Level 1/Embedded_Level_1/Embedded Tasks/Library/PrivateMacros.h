#ifndef PRIVATEMACROS_H_
#define PRIVATEMACROS_H_


#include "../Library/Bit_Math.h"

/*****************************
* DIO
*****************************/

#ifndef io_
#define io_(TYPE)     (*( _V TYPE _C)(_Base_DIO))
#endif

#ifndef MMIO_
#define _Base_DIO              0x30U
#define MMIO_(TYPE, address)   (*( _V TYPE _C)(address + _Base_DIO))
#endif

#ifndef tio()
#define _Base_Timer            0x42U
#define tio(TYPE)			   (*( _V TYPE _C)(_Base_Timer))
#endif



#endif /* PRIVATEMACROS_H_ */