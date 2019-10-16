#ifndef BUCKETSORT_HPP
#define BUCKETSORT_HPP

#include <vector>

#include "../SortingUtils.hpp"

using namespace std;

class BucketSort
{
public:
    /**
     * Sorts the statically created vector with the bucket sort algorithm
     */
    void sort(vector<int> &vec);

    /**
     * Sorts the dynamically created vector with the bucket sort algorithm
     */
    void sort(vector<int> *vec);
};

#endif