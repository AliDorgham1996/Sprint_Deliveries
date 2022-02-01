#ifndef INTERNAL_EEPROM_PRIVATEH_H_
#define INTERNAL_EEPROM_PRIVATEH_H_

#include "../Library/Types_Defs.h"
#include "../Library/PrivateMacros.h"

typedef struct
{
	uint8_t  ReadEnable           :1;
	uint8_t  WriteEnable          :1;
	uint8_t  MasterWriteEnable    :1;
	uint8_t  ReadyInterruptEnable :1;
	uint8_t  :4;
}_V EECR_t;

typedef struct
{
	uint16_t Address              :10;
}_V EEAR_t;

typedef struct
{
	EECR_t   Control;
	uint8_t  Data;
	EEAR_t   Address_10Bit;	
}_V INT_EEPROM_t;

typedef INT_EEPROM_t*  INT_EEPROMPTR_t;

#define INT_EEPROM    eeprom_(INT_EEPROMPTR_t)

#endif /* INTERNAL_EEPROM_PRIVATEH_H_ */