#ifndef REGISTERS_H
#define REGISTERS_H


#include <stdint.h>				

#include "../Library/Types_Defs.h"

//SREG
#define STATUS  sreg_(SREGPRT_t)

#define IO_Ports        0x04
//D
#define PIN_D			io_(0)
#define DDR_D			io_(1)
#define PORT_D			io_(2)
//C						  	
#define PIN_C			io_(3)
#define DDR_C			io_(4)
#define PORT_C			io_(5)
//B						  	
#define PIN_B			io_(6)
#define DDR_B			io_(7)
#define PORT_B			io_(8)
//A						  	
#define PIN_A			io_(9)
#define DDR_A			io_(10)
#define PORT_A			io_(11)


//D
//PIN
#define PIND            PIN_D.Register
#define PIND0           PIN_D.pin0
#define PIND1           PIN_D.pin1
#define PIND2           PIN_D.pin2
#define PIND3           PIN_D.pin3
#define PIND4           PIN_D.pin4
#define PIND5           PIN_D.pin5
#define PIND6           PIN_D.pin6
#define PIND7           PIN_D.pin7 
//DDR
#define DDRD            DDR_D.Register
#define DDRD0           DDR_D.pin0
#define DDRD1           DDR_D.pin1
#define DDRD2           DDR_D.pin2
#define DDRD3           DDR_D.pin3
#define DDRD4           DDR_D.pin4
#define DDRD5           DDR_D.pin5
#define DDRD6           DDR_D.pin6
#define DDRD7           DDR_D.pin7
//PORT
#define PORTD           PORT_D.Register
#define PORTD0          PORT_D.pin0
#define PORTD1          PORT_D.pin1
#define PORTD2          PORT_D.pin2
#define PORTD3          PORT_D.pin3
#define PORTD4          PORT_D.pin4
#define PORTD5          PORT_D.pin5
#define PORTD6          PORT_D.pin6
#define PORTD7          PORT_D.pin7

//C
//PIN
#define PINC            PIN_C.Register
#define PINC0           PIN_C.pin0
#define PINC1           PIN_C.pin1
#define PINC2           PIN_C.pin2
#define PINC3           PIN_C.pin3
#define PINC4           PIN_C.pin4
#define PINC5           PIN_C.pin5
#define PINC6           PIN_C.pin6
#define PINC7           PIN_C.pin7
//DDR
#define DDRC            DDR_C.Register
#define DDRC0           DDR_C.pin0
#define DDRC1           DDR_C.pin1
#define DDRC2           DDR_C.pin2
#define DDRC3           DDR_C.pin3
#define DDRC4           DDR_C.pin4
#define DDRC5           DDR_C.pin5
#define DDRC6           DDR_C.pin6
#define DDRC7           DDR_C.pin7
//PORT
#define PORTC           PORT_C.Register
#define PORTC0          PORT_C.pin0
#define PORTC1          PORT_C.pin1
#define PORTC2          PORT_C.pin2
#define PORTC3          PORT_C.pin3
#define PORTC4          PORT_C.pin4
#define PORTC5          PORT_C.pin5
#define PORTC6          PORT_C.pin6
#define PORTC7          PORT_C.pin7

//B
//PIN
#define PINB            PIN_B.Register
#define PINB0           PIN_B.pin0
#define PINB1           PIN_B.pin1
#define PINB2           PIN_B.pin2
#define PINB3           PIN_B.pin3
#define PINB4           PIN_B.pin4
#define PINB5           PIN_B.pin5
#define PINB6           PIN_B.pin6
#define PINB7           PIN_B.pin7
//DDR	   				
#define DDRB            DDR_B.Register
#define DDRB0           DDR_B.pin0
#define DDRB1           DDR_B.pin1
#define DDRB2           DDR_B.pin2
#define DDRB3           DDR_B.pin3
#define DDRB4           DDR_B.pin4
#define DDRB5           DDR_B.pin5
#define DDRB6           DDR_B.pin6
#define DDRB7           DDR_B.pin7
//PORT
#define PORTB           PORT_B.Register
#define PORTB0          PORT_B.pin0
#define PORTB1          PORT_B.pin1
#define PORTB2          PORT_B.pin2
#define PORTB3          PORT_B.pin3
#define PORTB4          PORT_B.pin4
#define PORTB5          PORT_B.pin5
#define PORTB6          PORT_B.pin6
#define PORTB7          PORT_B.pin7

//A
//PIN
#define PINA            PIN_A.Register
#define PINA0           PIN_A.pin0
#define PINA1           PIN_A.pin1
#define PINA2           PIN_A.pin2
#define PINA3           PIN_A.pin3
#define PINA4           PIN_A.pin4
#define PINA5           PIN_A.pin5
#define PINA6           PIN_A.pin6
#define PINA7           PIN_A.pin7
//DDR
#define DDRA            DDR_A.Register
#define DDRA0           DDR_A.pin0
#define DDRA1           DDR_A.pin1
#define DDRA2           DDR_A.pin2
#define DDRA3           DDR_A.pin3
#define DDRA4           DDR_A.pin4
#define DDRA5           DDR_A.pin5
#define DDRA6           DDR_A.pin6
#define DDRA7           DDR_A.pin7
//PORT
#define PORTA           PORT_A.Register
#define PORTA0          PORT_A.pin0
#define PORTA1          PORT_A.pin1
#define PORTA2          PORT_A.pin2
#define PORTA3          PORT_A.pin3
#define PORTA4          PORT_A.pin4
#define PORTA5          PORT_A.pin5
#define PORTA6          PORT_A.pin6
#define PORTA7          PORT_A.pin7



#endif /* REGISTERS_H */