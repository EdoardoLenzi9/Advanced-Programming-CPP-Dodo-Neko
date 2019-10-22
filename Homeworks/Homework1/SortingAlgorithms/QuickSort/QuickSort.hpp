#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <vector>
#include <time.h>

#include "../SortingInterface.hpp"
#include "../SortingUtils.hpp"

using namespace std;

class QuickSort
{
public:
    void sort(vector<int> &values);

private:
    /**
     * @brief  Recursive implementation of the QuickSort algorithm
     * @param  &values: The vector containing the values
     * @param  low: lower bound of the current sub-list
     * @param  high: upper bound of the current sub-list
     * @retval None
     */
    void quicksort_recursive(vector<int> &values, int low, int high);

    /**
     * @brief  Partition the list based on the pivot element
     * @note   Pivot is naively assumed to be the rightmost element
     * @param  &values: The vector containing the values
     * @param  low: lower bound of the current sub-list
     * @param  high: upper bound of the current sub-list
     * @retval Index of the pivot element
     */
    int partition(vector<int> &values, int low, int high);
};

#endif