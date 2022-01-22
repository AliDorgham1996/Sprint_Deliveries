#include "../APP/APP.h"

#define Task1 1
#define Task2 2
#define Task3 3
#define Task  Task1

int main(void)
{
#if(Task == Task1)
	Task_1();		//LCD -> "Welcome Sprints"
#elif(Task == Task2)
	Task_2();		//print LM35 values on LCD
#elif(Task == Task3)
	Task_3();		//use keypad with LCD
#endif /* Task */
}