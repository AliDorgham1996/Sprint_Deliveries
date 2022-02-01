#include "../Services/Circular_Buffer/Circular_Buffer.h"
#include <stdlib.h>

Queue_Error_t	Queue_Init		(Queue_t* queue)
{
	Queue_Error_t return_value = Queue_EN_valid;
	if(queue != NULL)
	{
		queue->buffer = (uint8_t*)calloc(queue->size, sizeof(uint8_t));
		queue->front  = -1;
		queue->rear   = -1;
	}
	else
	{
		return_value = Queue_EN_InvalidPointer;
	}
	return return_value;
}
Queue_Error_t	EnQueue			(Queue_t* queue, uint8_t  Data)
{
	Queue_Error_t return_value = Queue_EN_valid;
	
	if (((queue->front==0)&&(queue->rear==queue->size-1))||(queue->rear==((queue->front-1)%(queue->size-1))))
	{
		return Queue_EN_Full;
	}
	else
	{
		if(queue->front == -1)
		{
			queue->front = 0;
			queue->rear  = 0;
		}
		else if (queue->rear == queue->size-1 && queue->front != 0)
		{
			queue->rear = 0;
		}
		else
		{
			queue->rear++;
		}
		queue->buffer[queue->rear] = Data;
	} 	
	return return_value;
}
Queue_Error_t	DeQueue			(Queue_t* queue, uint8_t* Data)
{
	Queue_Error_t return_value = Queue_EN_valid;
	
	if (queue->front == -1)
	{
		return_value = Queue_EN_Empty;
	}
	else
	{
		*Data = queue->buffer[queue->front];
		if (queue->front == queue->rear)
		{
			queue->front = -1;
			queue->rear  = -1;
		}
		else if (queue->front == queue->size-1)
		{
			queue->front = 0;
		}
		else
		{
			queue->front++;	
		}
	}
	return return_value;
}