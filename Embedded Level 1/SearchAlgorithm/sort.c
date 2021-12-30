#include "sort.h"

void InsertionSort(uint32_t arr[], uint8_t arr_size)
{
    int arr_index, minimum, temp;
    for (arr_index = 1; arr_index < arr_size; arr_index++)
    {
        minimum = arr[arr_index];
        temp = arr_index - 1;

        while ((temp >= 0) && (arr[temp] > minimum))
        {
            arr[temp + 1] = arr[temp];
            temp -= 1;
        }

        arr[temp + 1] = minimum;
    }
}
