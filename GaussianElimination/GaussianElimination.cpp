using namespace std;

#include <iostream> 
#include <vector>
#include <cmath>

#include "GaussianElimination.hpp"


GaussianElimination::GaussianElimination( int rows, int cols ) {
	this->rows = rows;
	this->cols = cols;
	for( int i = 0; i < this->rows; ++i ) {
		this->data.push_back( vector< int >( this->cols, 0 ) );
	}
}


GaussianElimination::GaussianElimination( vector< vector< int > > data ) {
	this->data = data;
    this->rows = data.size();
    this->cols = data[ 0 ].size();
}


vector<vector<int>> GaussianElimination::gaussianElimination( void ) {

    int m = this->rows; // number of rows
    int n = this->cols; // number of cols
    int r = 0;          // pivot row
    int c = 0;          // pivot col
    
    while( r < m && c < n ){

        int i_max = argmax( r, m, c );              // i_max is the max abs value in the c column
        if ( data[ i_max ][ c ] == 0 ){         
            c++;                                    // column c is made by 0s
        } else {
            swap( data[ r ], data[ i_max ] );       // swap pivor row with i_max row

            for( int i = r + 1; i < m; i++ ){         // foreach row below the pivot row
                double f = data[ i ][ c ] / data[ r ][ c ]; // divide by the i_max value which cannot be 0 

                data[ i ][ c ] = 0;                     // Fill with zeros the lower part of pivot column:
       
                for( int j = c + 1; j < n; j++ ) {    // foreach column under the pivot column
                    data[ i ][ j ] = int( data[ i ][ j ] - data[ r ][ j ] * f );
                }
            }
            r++; // change pivot
            c++;
        }
    }
    return this->data;
}


int GaussianElimination::argmax( int h, int m, int k ) {
    int argmax = h;
    int max = data[ h ][ k ];

    for( int i = h; i < m; i++ ){
        if( abs( data[ i ][ k ] ) > max ){
            max = data[ i ][ k ];
            argmax = i;
        }
    }
    return argmax;
}


void GaussianElimination::print( void ) {
	for ( vector< int > row: this->data ) {
	    for ( int col : row ) {
			cout << col << "\t";
	    }
	cout << endl;
	}
}