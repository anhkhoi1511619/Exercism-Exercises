#include "binary_search.h"

int *binary_search(int value, int *arr, size_t length)
{
    if (length == 0) return NULL;
    for (size_t i = 0; i <= length; i++)
    {
        if (arr[i] == value)
        {
            return arr + i;
        }
    }
    return NULL;
}
