#ifndef GAUSSIAN_ELIMINATION_HPP
#define GAUSSIAN_ELIMINATION_HPP

using namespace std;

#include <vector>


class GaussianElimination
{
    protected:
        int rows;
    	int cols;
	    vector< vector< int > > data;	

    public:
        GaussianElimination( int rows, int cols );
        GaussianElimination( vector<vector<int>> data );

        vector<vector<int>> gaussianElimination( void );
        void print ( void );

        // Getters and setters
        int getRows() { return rows; }
        int getCols() { return cols; }
        void setValue( int row, int col, int value ) { data.at( row ).at( col ) = value; }
    
    private:    
        int argmax( int h, int m, int k );
};
#endif