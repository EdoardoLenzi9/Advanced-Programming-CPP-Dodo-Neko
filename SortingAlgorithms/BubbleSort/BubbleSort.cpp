#include "BubbleSort.h"
#include "SortingUtils.h"

void BubbleSort::sort(int *array) {
    int length = sizeof(array) / sizeof(*array);
    for (int n = 0; n < length - 1; n++) {
        for (int k = 0; k < length - n - 1; k++)
            if (array[k] > array[k + 1])
                swap(&array[k], &array[k+1]);
    }
}

void BubbleSort::sort(vector<int> v) {
    for (int n = 0; n < v.size - 1; n++) {
        for (int k = 0; k < v.size - n - 1; k++)
            if (v.at(k) > v.at(k + 1))
                swap(&v.at(k), &v.at(k + 1));            
    }
}