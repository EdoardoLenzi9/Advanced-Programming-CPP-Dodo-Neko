#include <iostream> 
#include <vector>
#include "Generics.hpp"
using namespace std; 
  
template <typename T> 
Vector<T>::Vector(int s) 
{ 
    size = s; 
	for( int i = 0; i < 5; ++i ) {
		this->data.push_back( i );
	}
} 
  
template <typename T> 
void Vector<T>::print() 
{ 
    cout << "CASDFDSAF" << endl; 
} 
  

template class Vector<int>;