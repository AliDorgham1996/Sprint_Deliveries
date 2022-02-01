#include "Internal_EEPROM.h"
#include "../MCAL/Internal_EEPROM/Internal_EEPROM_Privateh.h"
#include "../Library/Registers.h"
#include "../Library/Constants.h"

Bool_t		Int_EEPROM_Update		(uint16_t Address, uint8_t Data)
{
	Bool_t return_value = False;
	uint8_t LocalData ;
	Int_EEPROM_Read(Address , &LocalData);
	if(LocalData != Data)
	{
		if(Address <= INT_EEPROM_SIZE)
		{
			while(INT_EEPROM.Control.WriteEnable);
			INT_EEPROM.Address_10Bit.Address      = Address;
			INT_EEPROM.Data                       = Data;
			INT_EEPROM.Control.MasterWriteEnable  = ENABLE;
			INT_EEPROM.Control.WriteEnable        = ENABLE;
			return_value                          = True;
		}
		else{/*MISRA C*/}
	}
	return return_value;
}
Bool_t		Int_EEPROM_Read		(uint16_t Address , uint8_t* Data)
{
	Bool_t return_value = False;
	if(Address <= INT_EEPROM_SIZE)
	{
		while(INT_EEPROM.Control.WriteEnable);
		INT_EEPROM.Address_10Bit.Address = Address;
		INT_EEPROM.Control.ReadEnable = ENABLE;
		*Data = INT_EEPROM.Data;
		return_value = True;
	}
	else{/*MISRA C*/}
	return return_value;
}