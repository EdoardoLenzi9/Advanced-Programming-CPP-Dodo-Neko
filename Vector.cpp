#include <iostream>
#include <vector>
#include <random>
#include "Vector.hpp"

using namespace std;

random_device rd;  //Will be used to obtain a seed for the random number engine
mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()


template <typename T> 
Vector<T>::Vector( int size ) {
	this->size = size;
}


template <typename T> 
Vector<T>::Vector( vector<T> &data ) {
	this->data = data;
}


template<typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> t) { 
    s << "[";
    for (std::size_t i = 0; i < t.size(); i++) {
        s << t[i] << (i == t.size() - 1 ? "" : ",");
    }
    return s << "]" << std::endl;
}


template<typename T>
void Vector<T>::print( void ) {
    cout << endl << data << endl;
}


template<typename T>
bool Vector<T>::isSorted ( bool (*lt)(T, T) ){
    for (int i = 0; i < data.size() - 1; i++){
        if (!lt(data[i], data[i + 1])){ // unsorted elements found
            return false;
        }
    }
    return true; // vector is sorted
}


int NumericVector::get_max( void )
{
    int max = 0;
    for (int i = 0; i < data.size(); i++)
        if (data[i] > max)
            max = data[i];

    return max;
}


template class Vector<int>;
template class Vector< vector< int > >;