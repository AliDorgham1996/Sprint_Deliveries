#ifndef PRIVATEMACROS_H_
#define PRIVATEMACROS_H_


#include "../Library/Bit_Math.h"
#include "../Library/Constants.h"

/*****************************
* STATUS REG
*****************************/
#ifndef sreg_
#define _Base_SREG        0x5FU
#define sreg_(TYPE)       (*( _V TYPE _C)(_Base_SREG))
#endif

/*****************************
* IO
*****************************/
#ifndef IO_
#define _Base_IO                0x30U
#define IO_(TYPE,address)       (*( _V TYPE _C)((address)+_Base_IO))
#endif

/*****************************
* DIO
*****************************/
#ifndef dio_
#define _Base_DIO               0x30U
#define dio_(TYPE)              (*( _V TYPE _C)(_Base_DIO))
#endif

/*****************************
* Timer
*****************************/
#ifndef tio_
#define _Base_Timer             0x42U
#define tio_(TYPE)			    (*( _V TYPE _C)(_Base_Timer))
#endif

/*****************************
* ADC
*****************************/
#ifndef adc_
#define _Base_ADC              0x24U
#define adc_(TYPE)			   (*( _V TYPE _C)(_Base_ADC))
#endif

/*****************************
* EXTI
*****************************/
#ifndef exti_
#define _Base_ExtI             0x54U
#define exti_(TYPE)			   (*( _V TYPE _C)(_Base_ExtI))
#endif

/*****************************
* SPI
*****************************/
#ifndef spi_
#define _Base_SPI              0x2DU
#define spi_(TYPE)			   (*( _V TYPE)(_Base_SPI))
#endif

/*****************************
* I2C
*****************************/
#ifndef i2c_
#define _Base_I2C              0x20U
#define i2c_(TYPE)			   (*( _V TYPE _C)(_Base_I2C))
#endif

/*****************************
* UART
*****************************/
#ifndef uart_
#define _Base_UART              0x29U
#define uart_(TYPE)			   (*( _V TYPE _C)(_Base_UART))
#endif

/*****************************
* EEPROM
*****************************/
#ifndef eeprom_
#define _Base_EEPROM            0x3CU
#define eeprom_(TYPE)			(*( _V TYPE _C)(_Base_EEPROM))
#endif

#endif /* PRIVATEMACROS_H_ */