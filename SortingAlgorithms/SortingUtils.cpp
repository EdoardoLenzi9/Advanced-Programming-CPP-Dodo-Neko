#include <iostream>

#include "SortingUtils.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *array)
{
    int length = sizeof(array) / sizeof(*array);
}