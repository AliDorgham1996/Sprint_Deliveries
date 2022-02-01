#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "../Library/PrivateMacros.h"
#include "../Library/Types_Defs.h"

typedef struct
{
	PORT_t   PIN;
	PORT_t   DDR;
	PORT_t   PORT;
}DioChannelHandler_t;

#define ATmega32_DIO_PORTS        4

typedef DioChannelHandler_t  DIO_HANDLER [ATmega32_DIO_PORTS];
typedef DIO_HANDLER*    DIO_HandlerPtr_t;

#define DIO		 dio_(DIO_HandlerPtr_t)

#endif /* DIO_PRIVATE_H_ */