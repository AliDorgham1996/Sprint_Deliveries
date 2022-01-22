 /******************************************************************************
 *
 * [MODULE]: Registers of ATMEGA32 Micro-controller
 *
 * [FILE NAME]: atmega32.h
 *
 * [DESCRIPTION]: Registers for AVR
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/
 
#ifndef ATMEGA32_H_
#define ATMEGA32_H_

/*****************************************************************************
 *							DIO registers (PORTA)
 *****************************************************************************/

#define PORTA_DATA_R     	*((volatile uint8_t*)0x3B)
#define DDRA_DIR_R        	*((volatile uint8_t*)0x3A)
#define PINA_INPUT_R      	*((volatile uint8_t*)0x39)

/*****************************************************************************
 * 							DIO registers (PORTB)
 *****************************************************************************/

#define PORTB_DATA_R       	*((volatile uint8_t*)0x38)
#define DDRB_DIR_R       	*((volatile uint8_t*)0x37)
#define PINB_INPUT_R      	*((volatile uint8_t*)0x36)

/*****************************************************************************
 *							DIO registers (PORTC)
 *****************************************************************************/

#define PORTC_DATA_R       	*((volatile uint8_t*)0x35)
#define DDRC_DIR_R        	*((volatile uint8_t*)0x34)
#define PINC_INPUT_R      	*((volatile uint8_t*)0x33)

/*****************************************************************************
 *							DIO registers (PORTD)
 *****************************************************************************/
 
#define PORTD_DATA_R       	*((volatile uint8_t*)0x32)
#define DDRD_DIR_R        	*((volatile uint8_t*)0x31)
#define PIND_INPUT_R		*((volatile uint8_t*)0x30)


/*****************************************************************************
 *							TIMER registers (TIMER0)
 *****************************************************************************/

#define TCCR0_R      		*((volatile uint8_t*)0x53)
#define TCNT0_R       		*((volatile uint8_t*)0x52)
#define OCR0_R     			*((volatile uint8_t*)0x5C)

#define MCUCR_R       		*((volatile uint8_t*)0x55)
#define MCUCSR_R      		*((volatile uint8_t*)0x54)

#define TWCR_R      		*((volatile uint8_t*)0x56)

#define SPMCR_R      		*((volatile uint8_t*)0x57)

#define TIFR_R       		*((volatile uint8_t*)0x58)
#define TIMSK_R      		*((volatile uint8_t*)0x59)

#define GIFR_R      		*((volatile uint8_t*)0x5A)
#define GICR_R       		*((volatile uint8_t*)0x5B)

/* TCCR0 */
#define FOC0_BIT     7
#define WGM00_BIT    6
#define COM01_BIT    5
#define COM00_BIT    4
#define WGM01_BIT    3
#define CS02_BIT     2
#define CS01_BIT     1
#define CS00_BIT     0

/* TIMSK */
#define OCIE2_BIT    7
#define TOIE2_BIT    6
#define TICIE1_BIT   5
#define OCIE1A_BIT   4
#define OCIE1B_BIT   3
#define TOIE1_BIT    2
#define OCIE0_BIT    1
#define TOIE0_BIT    0

/* TIFR */
#define OCF2_BIT     7
#define TOV2_BIT     6
#define ICF1_BIT     5
#define OCF1A_BIT    4
#define OCF1B_BIT    3
#define TOV1_BIT     2
#define OCF0_BIT     1
#define TOV0_BIT     0

/*****************************************************************************
 *							TIMER registers (TIMER1)
 *****************************************************************************/
 
#define ICR1L_R      		*((volatile uint8_t*)0x46)
#define ICR1H_R      		*((volatile uint8_t*)0x47)
#define OCR1BL_R        	*((volatile uint8_t*)0x48)
#define OCR1BH_R        	*((volatile uint8_t*)0x49)
#define OCR1AL_R        	*((volatile uint8_t*)0x4A)
#define OCR1AH_R        	*((volatile uint8_t*)0x4B)
#define TCNT1L_R        	*((volatile uint8_t*)0x4C)
#define TCNT1H_R        	*((volatile uint8_t*)0x4D)
#define TCCR1B_R        	*((volatile uint8_t*)0x4E)
#define TCCR1A_R        	*((volatile uint8_t*)0x4F)

#define ICR1_R      		*((volatile uint16_t*)0x46)
#define OCR1B_R         	*((volatile uint16_t*)0x48)
#define OCR1A_R         	*((volatile uint16_t*)0x4A)
#define TCNT1_R         	*((volatile uint16_t*)0x4C)

#define SFIOR_R      		*((volatile uint8_t*)0x50)

/* TCCR1A */
#define COM1A1_BIT  7
#define COM1A0_BIT  6
#define COM1B1_BIT  5
#define COM1B0_BIT  4
#define FOC1A_BIT   3
#define FOC1B_BIT   2
#define WGM11_BIT   1
#define WGM10_BIT   0

/* TCCR1B */
#define ICNC1_BIT   7
#define ICES1_BIT   6
/* bit 5 reserved */
#define WGM13_BIT   4
#define WGM12_BIT   3
#define CS12_BIT    2
#define CS11_BIT    1
#define CS10_BIT    0

/*****************************************************************************
 *							TIMER registers (TIMER2)
 *****************************************************************************/

#define TCCR2_R       		*((volatile uint8_t*)0x45)
#define TCNT2_R       		*((volatile uint8_t*)0x44)
#define OCR2_R     	  		*((volatile uint8_t*)0x43)

/* TCCR2 */
#define FOC2_BIT    7
#define WGM20_BIT   6
#define COM21_BIT   5
#define COM20_BIT   4
#define WGM21_BIT   3
#define CS22_BIT    2
#define CS21_BIT    1
#define CS20_BIT    0

/*
*****************************************************************************
 *								TWI registers 
 *****************************************************************************
 
#define TWDR      		*((volatile uint8_t*)0x23)
#define TWAR       		*((volatile uint8_t*)0x22)
#define TWSR      		*((volatile uint8_t*)0x21)
#define TWBR      		*((volatile uint8_t*)0x20)

*****************************************************************************
 *								ADC registers 
 *****************************************************************************

#define ADMUX      		*((volatile uint8_t*)0x27)
#define ADCSRA     		*((volatile uint8_t*)0x26)
#define ADCH       		*((volatile uint8_t*)0x25)
#define ADCL      		*((volatile uint8_t*)0x24)

*****************************************************************************
 *							Analog Comparator registers 
 *****************************************************************************

#define ACSR       		*((volatile uint8_t*)0x28)

*****************************************************************************
 *								USART registers 
 *****************************************************************************
 
#define UDR      		*((volatile uint8_t*)0x2C)
#define UCSRA       	*((volatile uint8_t*)0x2B)
#define UCSRB      		*((volatile uint8_t*)0x2A)
#define UBRRL      		*((volatile uint8_t*)0x29)

*****************************************************************************
 *								SPI registers 
 *****************************************************************************

#define SPDR    		*((volatile uint8_t*)0x2F)
#define SPSR       		*((volatile uint8_t*)0x2E)
#define SPCR      		*((volatile uint8_t*)0x2D)

*****************************************************************************
 *								EEPROM registers 
 *****************************************************************************

#define EEARH      		*((volatile uint8_t*)0x3F)
#define EEARL      		*((volatile uint8_t*)0x3E)
#define EEDR       		*((volatile uint8_t*)0x3D)
#define EECR      		*((volatile uint8_t*)0x3C)

#define UBRRH      		*((volatile uint8_t*)0x32)
#define UCSRC       	*((volatile uint8_t*)0x31)

#define ASSR       		*((volatile uint8_t*)0x42)

#define WDTCR      		*((volatile uint8_t*)0x41)

*/
/*****************************************************************************
 *								Additional registers
 *****************************************************************************/
 
#define SREG_R     		*((volatile uint8_t*)0x5F)
#define SPH_R      		*((volatile uint8_t*)0x5E)
#define SPL_R      		*((volatile uint8_t*)0x5D)


#endif /* ATMEGA32_H_ */
