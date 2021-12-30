#include "stack.h"
#include <stdio.h>

stack_t Stack = {.top = 0 , {0}};


void push(uint8_t data)
{
    if(Stack.top >= STACKSIZE )
    {
      printf("Stack is Full\n");
      return;
    }
    Stack.arr[Stack.top++]= data;
}

uint8_t pull(void)
{
    if(Stack.top <= 0)
    {
        printf("Stack is Empty\n");
        return;
    }
    return(Stack.arr[--Stack.top]);
}

void printStack(void)
{
    int16_t i;
    if(Stack.top == 0)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        for(i = Stack.top -1 ;i >= 0 ; )//use array index
        {
            printf("element #%*i%*c %c\n",3,Stack.top-i-1,3,'=',Stack.arr[i--]);
        }
    }
}
