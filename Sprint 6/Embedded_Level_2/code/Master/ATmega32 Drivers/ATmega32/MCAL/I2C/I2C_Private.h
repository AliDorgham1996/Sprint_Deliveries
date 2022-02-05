#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#include "../Library/PrivateMacros.h"
#include "../Library/Types_Defs.h"


typedef union
{
	struct
	{
		uint8_t interrupt_enable   :1;
		uint8_t                    :1;
		uint8_t i2c_enable         :1;
		uint8_t write_collision    :1;
		uint8_t stop_condition     :1;
		uint8_t start_condition    :1;
		uint8_t acknowledge        :1;
		uint8_t interrupt_flag     :1;
	}TWCR_Bits;
	uint8_t TWCR_Reg;
}_V TWCR_t;

/* TWCR */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
#define TWIE    0

typedef struct
{
	uint8_t prescaler          :2;
	uint8_t                    :1;
	uint8_t status_code        :5;
}_V TWSR_t;

typedef struct
{
	uint8_t slave_address          :7;
	uint8_t gnrl_call_recog_enble  :1;
}_V TWAR_t;

typedef struct
{
	uint8_t    BitRate;
	TWSR_t     Status;
	TWAR_t     Address;
	uint8_t    Data;
	//50 empty
	uint8_t    :8;//1
	uint8_t    :8;//2
	uint8_t    :8;//3
	uint8_t    :8;//4
	uint8_t    :8;//5
	uint8_t    :8;//6
	uint8_t    :8;//7
	uint8_t    :8;//8
	uint8_t    :8;//9
	uint8_t    :8;//10
	uint8_t    :8;//1
	uint8_t    :8;//2
	uint8_t    :8;//3
	uint8_t    :8;//4
	uint8_t    :8;//5
	uint8_t    :8;//6
	uint8_t    :8;//7
	uint8_t    :8;//8
	uint8_t    :8;//9
	uint8_t    :8;//20
	uint8_t    :8;//1
	uint8_t    :8;//2
	uint8_t    :8;//3
	uint8_t    :8;//4
	uint8_t    :8;//5
	uint8_t    :8;//6
	uint8_t    :8;//7
	uint8_t    :8;//8
	uint8_t    :8;//9
	uint8_t    :8;//30
	uint8_t    :8;//1
	uint8_t    :8;//2
	uint8_t    :8;//3
	uint8_t    :8;//4
	uint8_t    :8;//5
	uint8_t    :8;//6
	uint8_t    :8;//7
	uint8_t    :8;//8
	uint8_t    :8;//9
	uint8_t    :8;//40
	uint8_t    :8;//1
	uint8_t    :8;//2
	uint8_t    :8;//3
	uint8_t    :8;//4
	uint8_t    :8;//5
	uint8_t    :8;//6
	uint8_t    :8;//7
	uint8_t    :8;//8
	uint8_t    :8;//9
	uint8_t    :8;//50
	TWCR_t     Control;
}I2C_CFG_t;

typedef I2C_CFG_t* I2C_CFGPTR_t;

#define I2C    i2c_(I2C_CFGPTR_t)

#endif /* I2C_PRIVATE_H_ */