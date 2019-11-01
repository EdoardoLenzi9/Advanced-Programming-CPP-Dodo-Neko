/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#include "GaussianElimination.hpp"
#include <iostream>
#include "Utils.hpp"


#define NEWLINE cout << endl;


int main(int argc, char const *argv[])
{
    int size = 100;

    vector<int> row1;
    vector<int> row2;
    vector<int> row3;
    vector<int> row4;
    vector<int> row5;
    vector<int> row6;

    row1.reserve(size);
    row2.reserve(size);
    row3.reserve(size);
    row4.reserve(size);
    row5.reserve(size);
    row6.reserve(size);

    fill_vector(row1, 0, 100);
    fill_vector(row2, 0, 100);
    fill_vector(row3, 0, 100);
    fill_vector(row4, 0, 100);
    fill_vector(row5, 0, 100);
    fill_vector(row6, 0, 100);

    vector<vector<int>> data {row1, row2, row3, row4, row5, row6};

    GaussianElimination test ( data );

	test.print();
	NEWLINE
    test.gaussianElimination();
    test.print();
	NEWLINE
    return 0;
}
