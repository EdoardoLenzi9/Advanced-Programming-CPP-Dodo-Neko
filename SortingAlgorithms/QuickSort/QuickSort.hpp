#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <vector>

using namespace std;

class QuickSort
{
public:
    template <typename T>
    void sort(vector<T> &values)
    {
        quicksort_recursive(values, 0, values.size() - 1);
    }

private:
    /**
     * @brief  Recursive implementation of the QuickSort algorithm
     * @param  &values: The vector containing the values
     * @param  low: lower bound of the current sub-list
     * @param  high: upper bound of the current sub-list
     * @retval None
     */
    template <typename T>
    void quicksort_recursive(vector<T> &values, int low, int high)
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

    /**
     * @brief  Partition the list based on the pivot element
     * @note   Pivot is naively assumed to be the rightmost element
     * @param  &values: The vector containing the values
     * @param  low: lower bound of the current sub-list
     * @param  high: upper bound of the current sub-list
     * @retval Index of the pivot element
     */
    template <typename T>
    int partition(vector<T> &values, int low, int high)
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
};

#endif