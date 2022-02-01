#ifndef DIO_H
#define DIO_H

			
#include "../MCAL/DIO/Dio_Cfg.h"				



typedef enum
{
	DIO_EN_valid_inti,
	DIO_EN_invalidPort,
	DIO_EN_invalidChannel,
	DIO_EN_invalidMode,
	DIO_EN_invalidState,
	DIO_EN_invalidPointer
}DioError_t;





//Channel
DioError_t			Dio_ChannelPullUp		(DioChannel_t Channel);
DioError_t			Dio_ChannelMode			(DioChannel_t Channel, DioMode_t  Mode);
DioError_t			Dio_ChannelWrite		(DioChannel_t Channel, DioWrite_t Output);
DioError_t			Dio_ChannelRead			(DioChannel_t Channel, DioState_t * State);
//port
DioError_t			Dio_PortPullUp			(DioPort_t Port);
DioError_t			Dio_PortMode			(DioPort_t Port, DioMode_t  Mode);
DioError_t			Dio_PortWrite			(DioPort_t Port, DioWrite_t Output);
DioError_t			Dio_PortRead			(DioPort_t Port, DioPortValue_t * State);
//group												   
DioError_t			Dio_GroupPullUp			(DioPort_t Port, DioGroupBits_t Group);
DioError_t			Dio_GroupMode			(DioPort_t Port, DioGroupBits_t Group, DioMode_t  Mode);
DioError_t			Dio_GroupWrite			(DioPort_t Port, DioGroupBits_t Group, DioWrite_t Output);
DioError_t			Dio_GroupRead			(DioPort_t Port, DioGroupBits_t Group, DioGroupValue_t * State);


#endif /* DIO_H */
