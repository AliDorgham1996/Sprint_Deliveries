#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


#include "../Library/Types_Defs.h"

typedef struct
{
	PORT_t   PIN;
	PORT_t   DDR;
	PORT_t   PORT;
}DioChannelHandler_t;

typedef DioChannelHandler_t  DIO_HANDLER [4];
typedef DIO_HANDLER*    DIO_HandlerPtr_t;

#define DIO		 io_(DIO_HandlerPtr_t)

#endif /* DIO_PRIVATE_H_ */