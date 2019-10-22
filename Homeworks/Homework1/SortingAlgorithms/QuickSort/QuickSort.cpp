#include "QuickSort.hpp"

void QuickSort::sort(vector<int> &values)
{
    quicksort_recursive(values, 0, values.size() - 1);
}

void QuickSort::quicksort_recursive(vector<int> &values, int low, int high)
{
    if (low < high)
    {
        // Partition the current list based on the pivot element
        int pivotIndex = partition(values, low, high);

        // Recursive call on each sub-list around the pivot
        // Divide & Conquer!
        quicksort_recursive(values, low, pivotIndex - 1);
        quicksort_recursive(values, pivotIndex + 1, high);
    }
}

int QuickSort::partition(vector<int> &values, int low, int high)
{
    int pivot = high; // pivot is the rightmost element
    int index = low;

    for (int i = low; i < high; i++)
    {
        if (values[i] < values[pivot])
        {
            swap(values[i], values[index]);
            index++;
        }
    }
    swap(values[pivot], values[index]);

    return index;
}