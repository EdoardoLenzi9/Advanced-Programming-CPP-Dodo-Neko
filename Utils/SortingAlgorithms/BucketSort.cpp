#include "BucketSort.hpp"
#include <iostream>

using namespace std;


void NumericVector::bucketsort ( void ){

    const int MAX = get_max();

    // fill the bucket with (max + 1) zeros
    vector<int> buckets(MAX + 1, 0);

    for (int i = 0; i < data.size(); i++) {
        buckets[data[i]]++; // counts the occurence of a number
    }

    for (int i = 0, j = 0; i <= MAX; i++) {
        while (buckets[i])
        {
            data[j++] = i; // add next sorted value
            buckets[i]--; // decrement the occurence of this value
        }
    }
}


template class Vector<int>;
template class Vector< vector< int > >;