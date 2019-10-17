#include "InsertionSort.hpp"
#include <iostream>

using namespace std;


template<typename T>
void Vector<T>::insertionsort ( bool (*lt)(T, T) ){
    T x; // used for swapping elements
    int i = 1;
    int k; // used to iterate 'backwards' to find position
    while (i < data.size()) {
        x = data[i];
        k = i - 1;
        while (k >= 0 && !lt(data[k], x)) {
            data[k + 1] = data[k]; // just swapping around
            --k;
        }
        data[k + 1] = x;
        ++i;
    }
}


template class Vector<int>;
template class Vector< vector< int > >;