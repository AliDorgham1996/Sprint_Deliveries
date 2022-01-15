#include "../APP/APP.h"


#define Task1 1
#define Task2 2
#define Task3 3
#define Task  Task3

int main(void)
{
#if(Task == Task1)
	Task_1();		//Toggle Led 2 with Button 1
#elif(Task == Task2)
	Task_2();		//Toggle led 1 (500 ms on, 300 ms off) using timer "polling" 
#elif(Task == Task3)
	Task_3();		//Toggle led 0 (500 ms on, 300 ms off) using timer "Interrupt"
#endif /* Task */
}