#ifndef VECTOR_HPP
#define VECTOR_HPP

using namespace std;
#include <vector>


template <typename T> 
class Vector {
    protected:
        int size;
	    vector< T > data;		

    public:
        // Constructors     

        Vector( int size );
        Vector( vector<T> &data );
        
        // Prints the given vector on the console
        void print( void ); 


        // Getters and setters
        //int getSize() { return size; }
        //void setValue( int index, int value ) { data.at( row ) = value; }
        
        // Helpers

        /*
        * Checks if given vector is sorted
        * @return true, if sorted, else false
        */
        bool isSorted( bool (*lessThanCriterion)(T, T) );

        void bubblesort ( bool (*lessThanCriterion)(T, T) );
        void insertionsort ( bool (*lessThanCriterion)(T, T) );
};


class NumericVector : public Vector<int>{

    public:
        // Constructors     

        NumericVector( int size ) : Vector(size) {};
        NumericVector( vector<int> &data ) : Vector(data) {};
        
        int get_max( void );
        void bucketsort ( void );
};

#endif  // VECTOR_HPP