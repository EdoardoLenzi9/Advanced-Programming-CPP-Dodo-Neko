using namespace std;

#include <gtest/gtest.h>
#include<iostream>

#include "../Matrix.hpp"

#define NEWLINE cout << endl;


TEST(matrix_multiplication, base_test) {
	// Arrange

	int rows = 3;
	int cols = 3;
	Matrix<int> A ( rows, cols );
	Matrix<int> B ( rows, cols );

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
	

	// Act

	Matrix<int> C = A.multMatrix( B );
	C.print();


	// Assert

 	ASSERT_EQ( 1+1, 2 );
	//TODO: check if this actually works with matrices that aren't square
}


TEST( matrix_multiplication, another_todo_test ) {
	// Arrange

	Matrix< int > A ( 3, 3 );
	

	// Act


	// Assert

 	ASSERT_TRUE( true );
}