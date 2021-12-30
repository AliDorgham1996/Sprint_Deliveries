#include "Compiler.h"
#include <stdio.h>
#include <string.h>

const answers_t Answers =
{
    (string_t)"Not Balanced",
    (string_t)"Balanced",
    (string_t)"There were not any parentheses!!"
};

extern stack_t Stack ;


#define PARANTGESES     expression[index] == '{' \
                    ||  expression[index] == '}' \
                    ||  expression[index] == '(' \
                    ||  expression[index] == ')' \
                    ||  expression[index] == '[' \
                    ||  expression[index] == ']'

string_t balancedParentheses(uint8_t * expression)
{
    Stack.top = 0;
    int16_t index;
    uint8_t last_parenthes;
    int16_t count1 = 0 ;
    int16_t count2 = 0 ;
    int16_t count3 = 0 ;
    uint8_t IsthereParentheses = 0;
    Balance_t flag = Balanced ;
    uint8_t string_size = strlen((const char *)expression);
    for(index = 0; index <string_size ; index++)
    {
        if(PARANTGESES)
        {
            IsthereParentheses = 1;
            push(expression[index]);
        }
    }
    if(IsthereParentheses != 0)
    {
        printf("Now your stack contains\n");
        printStack();
        for(index = Stack.top ; index > 0; index--)//use top = array index + 1 , so must pull until 1 not 0 .
        {
            last_parenthes = pull();
            if(last_parenthes == ')')
            {
                count1 ++;
            }
            else if(last_parenthes == '(')
            {
                count1 --;
                if(count1 < 0)
                {
                    break;
                }
            }
            else if(last_parenthes == '}')
            {
                count2 ++;
            }
            else if(last_parenthes == '{')
            {
                count2 --;
                if(count2 < 0)
                {
                    break;
                }
            }
            else if(last_parenthes == ']')
            {
                count3 ++;
            }
            else if(last_parenthes == '[')
            {
                count3 --;
                if(count3 < 0)
                {
                    break;
                }
            }
            else
            {
                /* MISRA C */
            }
        }
    }
    else{/* MISRA C */}
    flag = ((count1 == count2) && (count2 == count3) && (count1 == 0))? (Balanced):(NotBalanced);
    flag = (IsthereParentheses == 0)?(NoParentheses):(flag);
    return Answers[flag];
}
