#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include "../Library/PrivateMacros.h"
#include "../Library/Types_Defs.h"


typedef struct
{
	uint8_t MultiProcessor  :1;
	uint8_t double_speed  	:1;
	uint8_t parity_error	:1;
	uint8_t dataOverRun	    :1;
	uint8_t frame_error	    :1;
	uint8_t udr_isEmpty	    :1;
	uint8_t trns_cmplt      :1;
	uint8_t rciv_cmplt      :1;
}_V UCSRA_t;

typedef struct
{
	uint8_t bit8_Transmit   :1;
	uint8_t bit8_Recieve    :1;
	uint8_t bit8		   	:1;
	uint8_t transmit		:1;
	uint8_t recieve         :1;
	uint8_t udrEmptyIntrrpt :1;
	uint8_t trnsCompIntrrpt :1;
	uint8_t rcivCompIntrrpt :1;
}_V UCSRB_t;


/* UCSRC */
#define URSEL   7
#define UMSEL   6
#define UPM		4
#define USBS    3
#define UCSZ	1
#define UCPOL   0

typedef struct
{
	uint8_t         BaudL;
	UCSRB_t			Enables;
	UCSRA_t			Flags;
	uint8_t			Data;
	//19 empty
	uint8_t         :8;//1
	uint8_t         :8;//2
	uint8_t         :8;//3
	uint8_t         :8;//4
	uint8_t         :8;//5
	uint8_t         :8;//6
	uint8_t         :8;//7
	uint8_t         :8;//8
	uint8_t         :8;//9
	uint8_t         :8;//10
	uint8_t         :8;//11
	uint8_t         :8;//12
	uint8_t         :8;//13
	uint8_t         :8;//14
	uint8_t         :8;//15
	uint8_t         :8;//16
	uint8_t         :8;//17
	uint8_t         :8;//18
	uint8_t         :8;//19
	uint8_t			Control_BaudH;
}_V UART_t;

typedef UART_t*   UARTPTR_t;

#define  UART   uart_(UARTPTR_t)

#endif /* UART_PRIVATE_H_ */