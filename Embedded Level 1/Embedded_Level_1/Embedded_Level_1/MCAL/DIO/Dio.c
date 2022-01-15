#include "../MCAL/DIO/Dio.h"				
#include "../MCAL/DIO/Dio_Private.h"			
#include "../Library/Bit_Math.h"			

DioError_t			Dio_ChannelPullUp		(DioChannel_t Channel)
{
	DioError_t return_value = DIO_EN_valid_inti;
	if((Channel >= DIO_EN_MIN_Channel) && (Channel <= DIO_EN_MAX_Channel))
	{		
		SetBit(DIO[Channel/DIO_CHANNELS_PER_PORT].PORT.Register,(Channel % DIO_CHANNELS_PER_PORT));
	}
	else
	{
		return_value = DIO_EN_invalidChannel;
	}
	return return_value;
}


DioError_t			Dio_ChannelMode			(DioChannel_t Channel, DioMode_t  Mode)
{
	DioError_t return_value = DIO_EN_valid_inti;
	if((Channel >= DIO_EN_MIN_Channel) && (Channel <= DIO_EN_MAX_Channel))
	{
		if(DIO_EN_M_Input == Mode)
		{
			ClearBit(DIO[Channel/DIO_CHANNELS_PER_PORT].DDR.Register,(Channel % DIO_CHANNELS_PER_PORT));
		}
		else if(DIO_EN_M_Output == Mode)
		{
			SetBit(DIO[Channel/DIO_CHANNELS_PER_PORT].DDR.Register,(Channel % DIO_CHANNELS_PER_PORT));
		}
		else
		{
			return_value = DIO_EN_invalidMode;
		}	
	}
	else
	{
		return_value = DIO_EN_invalidChannel;
	}
	return return_value;		
}



DioError_t			Dio_ChannelWrite		(DioChannel_t Channel, DioWrite_t Output)
{
	DioError_t return_value = DIO_EN_valid_inti;
	if((Channel >= DIO_EN_MIN_Channel) && (Channel <= DIO_EN_MAX_Channel))
	{
		if(DIO_EN_W_Low == Output)
		{
			ClearBit(DIO[Channel/DIO_CHANNELS_PER_PORT].PORT.Register,(Channel % DIO_CHANNELS_PER_PORT));
		}
		else if(DIO_EN_W_High == Output)
		{
			SetBit(DIO[Channel/DIO_CHANNELS_PER_PORT].PORT.Register,(Channel % DIO_CHANNELS_PER_PORT));
		}
		else if(DIO_EN_W_Toggle == Output)
		{
			ToggleBit(DIO[Channel/DIO_CHANNELS_PER_PORT].PORT.Register,(Channel % DIO_CHANNELS_PER_PORT));
		}
		else
		{
			return_value = DIO_EN_invalidState;
		}
	}
	else
	{
		return_value = DIO_EN_invalidChannel;
	}
	return return_value;
}


DioError_t			Dio_ChannelRead			(DioChannel_t Channel, DioState_t * State)
{
	DioError_t return_value = DIO_EN_valid_inti;
	if((Channel >= DIO_EN_MIN_Channel) && (Channel <= DIO_EN_MAX_Channel))
	{
		if(NULL != State)
		{
			*State = GetBit(DIO[Channel/DIO_CHANNELS_PER_PORT].PIN.Register,(Channel % DIO_CHANNELS_PER_PORT));
		}		
		else
		{
			return_value = DIO_EN_invalidPointer;
		}
	}
	else
	{
		return_value = DIO_EN_invalidChannel;
	}
	return return_value;
}


DioError_t			Dio_PortPullUp			(DioPort_t Port)
{
	DioError_t return_value = DIO_EN_valid_inti;
	if((Port >= DIO_EN_MIN_PORT) && (Port < DIO_EN_MAX_PORT))
	{
		SetReg_8_Bits(DIO[Port].PORT.Register);
	}
	else
	{
		return_value = DIO_EN_invalidChannel;
	}
	return return_value;
}

DioError_t			Dio_PortMode			(DioPort_t Port, DioMode_t  Mode)
{
	DioError_t return_value = DIO_EN_valid_inti;
	if((Port >= DIO_EN_MIN_PORT) && (Port < DIO_EN_MAX_PORT))
	{
		if(DIO_EN_M_Input == Mode)
		{
			ClearReg_8_Bits(DIO[Port].DDR.Register);
		}
		else if(DIO_EN_M_Output == Mode)
		{
			SetReg_8_Bits(DIO[Port].DDR.Register);
		}
		else
		{
			return_value = DIO_EN_invalidMode;
		}
	}
	else
	{
		return_value = DIO_EN_invalidChannel;
	}
	return return_value;
}


DioError_t			Dio_PortWrite			(DioPort_t Port, DioWrite_t Output)
{
	DioError_t return_value = DIO_EN_valid_inti;
	if((Port >= DIO_EN_MIN_PORT) && (Port < DIO_EN_MAX_PORT))
	{
		if(DIO_EN_W_Low == Output)
		{
			ClearReg_8_Bits(DIO[Port].PORT.Register);
		}
		else if(DIO_EN_W_High == Output)
		{
			SetReg_8_Bits(DIO[Port].PORT.Register);
		}
		else if(DIO_EN_W_Toggle == Output)
		{
			ToggleReg_8_Bits(DIO[Port].PORT.Register);
		}
		else
		{
			return_value = DIO_EN_invalidState;
		}
	}
	else
	{
		return_value = DIO_EN_invalidChannel;
	}
	return return_value;
}


DioError_t			Dio_PortRead			(DioPort_t Port, DioPortValue_t * State)
{
	DioError_t return_value = DIO_EN_valid_inti;
	if((Port >= DIO_EN_MIN_PORT) && (Port < DIO_EN_MAX_PORT))
	{
		if(NULL != State)
		{
			*State = DIO[Port].PIN.Register;
		}
		else
		{
			return_value = DIO_EN_invalidPointer;
		}
	}
	else
	{
		return_value = DIO_EN_invalidChannel;
	}
	return return_value;
}


DioError_t			Dio_GroupPullUp			(DioPort_t Port, DioGroupBits_t Group)
{
	DioError_t return_value = DIO_EN_valid_inti;
	if((Port >= DIO_EN_MIN_PORT) && (Port < DIO_EN_MAX_PORT))
	{
		SetMaskBits(DIO[Port].PORT.Register, Group);
	}
	else
	{
		return_value = DIO_EN_invalidChannel;
	}
	return return_value;
}

DioError_t			Dio_GroupMode			(DioPort_t Port, DioGroupBits_t Group, DioMode_t  Mode)
{
	DioError_t return_value = DIO_EN_valid_inti;
	if((Port >= DIO_EN_MIN_PORT) && (Port < DIO_EN_MAX_PORT))
	{
		if(DIO_EN_M_Input == Mode)
		{
			ClearMaskBits(DIO[Port].DDR.Register, Group);
		}
		else if(DIO_EN_M_Output == Mode)
		{
			SetMaskBits(DIO[Port].DDR.Register, Group);
		}
		else
		{
			return_value = DIO_EN_invalidMode;
		}
	}
	else
	{
		return_value = DIO_EN_invalidChannel;
	}
	return return_value;
}



DioError_t			Dio_GroupWrite			(DioPort_t Port, DioGroupBits_t Group, DioWrite_t Output)
{
	DioError_t return_value = DIO_EN_valid_inti;
	if((Port >= DIO_EN_MIN_PORT) && (Port < DIO_EN_MAX_PORT))
	{
		if(DIO_EN_W_Low == Output)
		{
			ClearMaskBits(DIO[Port].PORT.Register, Group);
		}
		else if(DIO_EN_W_High == Output)
		{
			SetMaskBits(DIO[Port].PORT.Register, Group);
		}
		else if(DIO_EN_W_Toggle == Output)
		{
			ToggleMaskBits(DIO[Port].PORT.Register, Group);
		}
		else
		{
			return_value = DIO_EN_invalidState;
		}
	}
	else
	{
		return_value = DIO_EN_invalidChannel;
	}
	return return_value;
}


DioError_t			Dio_GroupRead			(DioPort_t Port, DioGroupBits_t Group, DioGroupValue_t * State)
{
	DioError_t return_value = DIO_EN_valid_inti;
	if((Port >= DIO_EN_MIN_PORT) && (Port < DIO_EN_MAX_PORT))
	{
		if(NULL != State)
		{
			*State = GetMaskBits(DIO[Port].PIN.Register, Group);
		}
		else
		{
			return_value = DIO_EN_invalidPointer;
		}
	}
	else
	{
		return_value = DIO_EN_invalidChannel;
	}
	return return_value;
}
