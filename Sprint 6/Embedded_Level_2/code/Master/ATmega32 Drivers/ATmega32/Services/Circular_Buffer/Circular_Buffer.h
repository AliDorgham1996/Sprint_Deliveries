#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include "../Library/Types_Defs.h"
#include "../Library/Constants.h"

typedef struct 
{
	uint8_t* buffer;
	int8_t   front;
	int8_t   rear;
	int8_t  size;
}BQueue_t;

typedef enum
{
	Queue_EN_valid,
	Queue_EN_Full,
	Queue_EN_Empty,
	Queue_EN_InvalidPointer
}Queue_Error_t;

Queue_Error_t	Queue_Init		(BQueue_t* queue);
Queue_Error_t	EnQueue			(BQueue_t* queue, uint8_t  Data);
Queue_Error_t	DeQueue			(BQueue_t* queue, uint8_t* Data);



#endif /* CIRCULAR_BUFFER_H_ */