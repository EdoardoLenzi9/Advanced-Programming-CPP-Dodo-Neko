#include "MatrixMultiplication/Matrix.hpp       "

int main() {

	int rows = 3;
	int cols = 3;
	Matrix A ( rows, cols );
	Matrix B ( rows, cols );
	
	int k = 0;
	for ( int i = 0; i < rows; ++i ) {
		for ( int j = 0; j < cols; ++j ) {
			A.setValue( i, j, k++ );
			B.setValue( i, j, k++ );
		}
	}	

	A.print();
	NEWLINE
	B.print();
	NEWLINE
	Matrix C = A.multMatrix( B );
	C.print();

	//TODO: check if this actually works with matrices that aren't square
}
