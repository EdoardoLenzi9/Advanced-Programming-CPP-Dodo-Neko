#include "MatrixMultiplication.hpp"
#include "../../Matrix.hpp"


template <typename T> 
Matrix<T> Matrix<T>::multMatrix( Matrix<T> B ) {
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


template class Matrix<int>;