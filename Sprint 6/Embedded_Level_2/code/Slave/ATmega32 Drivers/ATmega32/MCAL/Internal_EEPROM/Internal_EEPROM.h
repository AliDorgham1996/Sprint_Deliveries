#ifndef INTERNAL_EEPROM_H_
#define INTERNAL_EEPROM_H_

#include "../Library/Types_Defs.h"

#define INT_EEPROM_SIZE    4095

Bool_t	Int_EEPROM_Update	(uint16_t Address, uint8_t  Data);
Bool_t	Int_EEPROM_Read		(uint16_t Address, uint8_t* Data);


#endif /* INTERNAL_EEPROM_H_ */