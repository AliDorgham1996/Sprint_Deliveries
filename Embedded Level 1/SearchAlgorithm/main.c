#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Task_3.h"
#include <windows.h>

int main()
{
    uint8_t     arr_size        = 0 ;
    uint8_t     arr_index       = 0 ;
    uint32_t    element         = 0 ;
    int16_t     searchresult    = -1;
    uint8_t value;
    do
    {
        arr_size        = 0 ;
        arr_index       = 0 ;
        element         = 0 ;

        do{
        printf("Enter the size of array   >   ");
        fflush(stdin);
        scanf("%d",&element);
        element = (element > 0 && element <= 255) ? (element) : (0) ;
        }while(element == 0);

        arr_size = element;
        uint32_t * arr = (uint32_t*)malloc(arr_size*sizeof(uint32_t));

        for(arr_index = 0 ; arr_index < arr_size ; arr_index++)
        {
            printf("#%d >   ",arr_index+1);
            fflush(stdin);
            scanf("%d",&arr[arr_index]);
        }

        printf("Enter the number for search...\n    >   ");
        scanf("%d",&element);

        searchresult = Task3(arr,arr_size,element);

        if( searchresult != -1 )
        {
            printf("Number is found and the index is : %d",searchresult+1);
        }
        else
        {
            printf("Number is not found !!");
        }
        printf("\n\n\n\n\n\n");

        printf("Again.................(y/n)?\n");
        fflush(stdin);
        scanf("%c",&value);

        system("cls");

    }while((value == 'Y') || (value == 'y'));

    return 0;
}
