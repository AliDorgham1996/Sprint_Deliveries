#include "sort.h"
#include "search.h"
#include "Task_3.h"

typedef enum
{
    False,
    True
}Bool_t;

static Bool_t check_Is_sorted (uint32_t arr[], uint8_t arr_size);

int16_t Task3(uint32_t arr[], uint8_t arr_size, uint32_t number)
{
    int16_t result_value = -1 ; // initial as not found
    if (check_Is_sorted (arr, arr_size) == False )
    {
        InsertionSort(arr, arr_size);
    }else{/* MISRA C */}
    result_value = B_Search(arr,arr_size, number);
    return result_value;
}


static Bool_t check_Is_sorted (uint32_t arr[], uint8_t arr_size)
{
    Bool_t result_value = True;
    uint8_t arr_index ;
    for(arr_index = 0; arr_index < arr_size - 1 ;arr_index ++ )
    {
        if( arr[arr_index+1] < arr[arr_index] )
        {
            result_value = False;
            break;
        }else{/* MISRA C */}
    }
    return result_value;
}
