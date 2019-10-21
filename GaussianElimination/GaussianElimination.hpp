#ifndef GAUSSIAN_ELIMINATION_HPP
#define GAUSSIAN_ELIMINATION_HPP

using namespace std;

#include <vector>


class GaussianElimination {

    protected:
        int rows;
    	int cols;
	    vector<vector<int>> data;	

    public:
        GaussianElimination( int rows, int cols ) : rows(rows), cols(cols), data(vector<vector<int>>(rows, vector<int>(cols))) { }
        GaussianElimination( vector<vector<int>> data ) : data(data), rows(data.size()), cols(data[ 0 ].size()) { }


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