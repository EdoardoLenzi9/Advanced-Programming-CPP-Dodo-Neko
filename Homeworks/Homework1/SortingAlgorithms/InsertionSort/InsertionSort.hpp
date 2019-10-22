#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include "../SortingUtils.hpp"

class InsertionSort
{
public:
    /**
     * insertion sort algorithm for statically created vectors
     */
    template <typename T>
    void sort(vector<T> &vec)
    {
        T x; // used for swapping elements
        int i = 1;
        int k; // used to iterate 'backwards' to find position
        while (i < vec.size())
        {
            x = vec[i];
            k = i - 1;
            while (k >= 0 && vec[k] > x)
            {
                vec[k + 1] = vec[k]; // just swapping around
                --k;
            }
            vec[k + 1] = x;
            ++i;
        }
    }

    /**
     * insertion sort algorithm for dynamically created vectors
     */
    template <typename T>
    void sort(vector<T> *vec)
    {
        T x; // used for swapping elements
        int i = 1;
        int k; // used to iterate 'backwards' to find position

        while (i < vec->size())
        {
            x = vec->at(i);
            k = i - 1;
            while (k >= 0 && vec->at(k) > x)
            {
                vec[k + 1] = vec[k]; // just swapping around
                --k;
            }
            vec->at(k + 1) = x;
            ++i;
        }
    }
};

#endif