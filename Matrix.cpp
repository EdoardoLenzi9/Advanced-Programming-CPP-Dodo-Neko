#include <iostream>
#include <vector>
#include "Matrix.hpp"

using namespace std;

template <typename T> 
Matrix<T>::Matrix( int rows, int cols ) : Vector<T> ( cols ) {
	this->rows = rows;
	this->cols = cols;

	//turns out, push_back doesnt actually insert elements at the back end of a vector, but instead
	//adds new elements at the back, increasing the size of the vector.
	for( int i = 0; i < this->rows; ++i ) {
		this->data.push_back( vector< T >( this->cols, 0 ) );
	}
}


template <typename T> 
void Matrix<T>::print( void ) {
	for ( vector< int > row: this->data ) {
	    for ( int col: row ) {
			cout << col << "\t";
	    }
	cout << endl;
	}
}

	
	
template <typename T> 
void Matrix<T>::addMatrix( Matrix<T> B ) {
	if ( B.getRows() != this->rows || B.getCols() != this->cols ) {
		throw invalid_argument( "matrixes must be of the same dimensions to add" );
	}
		
	for ( int row = 0; row < this->rows; ++row ) {
		for ( int col = 0; col < this->cols; ++col ) {
			this->data.at( row ).at( col ) += B.at( row ).at( col );
		}
	}
}

template class Matrix<int>;