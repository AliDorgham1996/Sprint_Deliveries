#include "search.h"

int16_t B_Search(uint32_t arr[], uint8_t arr_size, uint32_t element)
{
    int16_t  left      = 0            ;
    int16_t  right     = arr_size - 1 ;
    int16_t  middle                   ;

    while(left <= right)
    {
        middle = left + (right - left )/2;
        if(arr[middle] == element)
        {
            return middle;
        }
        else if(arr[middle] < element)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return -1;
}
