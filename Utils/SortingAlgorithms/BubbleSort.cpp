#include "BubbleSort.hpp"
#include <iostream>

using namespace std;


template<typename T>
void Vector<T>::bubblesort ( bool (*lt)(T, T) ){

    for ( int n = 0; n < data.size() - 1; n++ ) {
        for ( int k = 0; k < data.size() - n - 1; k++ ) {
            if ( !lt(data.at( k ), data.at( k + 1 ) )) {
                swap( data[ k ], data[ k + 1 ] );
            }
        }
    }
}


template class Vector<int>;
template class Vector< vector< int > >;