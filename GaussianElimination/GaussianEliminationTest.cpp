#include "GaussianElimination.hpp"
#include <iostream>

#define NEWLINE cout << endl;

int main(int argc, char const *argv[])
{
    vector<int> row1{ 1, 3, 1, 9 };
    vector<int> row2{ 1, 1, -1, 1 };
    vector<int> row3{ 3, 11, 5, 35 }; 
    vector<vector<int>> data {row1, row2, row3};

	GaussianElimination test ( data );

	test.print();
	NEWLINE
    test.gaussianElimination();
    test.print();
	NEWLINE
    return 0;
}
