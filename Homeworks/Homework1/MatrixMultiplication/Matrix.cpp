#include <iostream>
#include <vector>
#include "Matrix.hpp"

using namespace std;

#define NEWLINE cout << endl;


Matrix::Matrix( int rows, int cols ) {
	this->rows = rows;
	this->cols = cols;

	//turns out, push_back doesnt actually insert elements at the back end of a vector, but instead
	//adds new elements at the back, increasing the size of the vector.
	for( int i = 0; i < this->rows; ++i ) {
		this->data.push_back( vector<int>( this->cols, 0 ) );
	}

}


Matrix::print() {
	for ( vector<int> row: this->data ) {
	    for ( int col: row ) {
			cout << col << "\t";
	    }
	cout << endl;
	}
}

	
	
Matrix::addMatrix( Matrix B ) {
	if ( B.getRows() != this->rows || B.getCols() != this->cols ) {
		throw invalid_argument( "matrixes must be of the same dimensions to add" );
	}
		
	for ( int row = 0; row < this->rows; ++row ) {
		for ( int col = 0; col < this->cols; ++col ) {
			this->data.at( row ).at( col ) += B.at( row ).at( col );
		}
	}
}


Matrix::multMatrix( Matrix B ) {
	if ( B.getRows() != this->cols ) {
		throw invalid_argument( "matrix dimensions incompatible." );
	}
	Matrix C ( this->rows, B.getCols() );

	int result = 0;

	for ( int rowA = 0; rowA < this->rows; ++rowA ) {
		for ( int colB = 0; colB < B.getCols(); ++colB ) {
			for ( int colA = 0; colA < this->cols; ++colA ) {
				result += this->data.at( rowA ).at( colA ) * B.at( colA ).at( colB );
			}
			
			C.setValue( rowA, colB, result );
			result = 0;
		}
	}

	return C;
}
