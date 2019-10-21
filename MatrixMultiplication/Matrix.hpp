#ifndef MATRIX_H_
#define MATRIX_H_

class Matrix {
    private:
        int rows;
    	int cols;
	    vector<vector<int>> data;		//TODO generic datatype

    public:
        // Constructors        
        Matrix( int rows, int cols )

        // Adds another matrix to this one.
        void addMatrix( Matrix B );
        
        // Matrix multiplication
        Matrix multMatrix( Matrix B );
        
        // Output the whole matrix on the console
        void print(); 

        // Getters and setters
        int getRows() { return rows; }
        int getCols() { return cols; }
        void setValue( int row, int col, int value ) { data.at( row ).at( col ) = value; }
        
        // Helpers

        // Make Matrix::at() return a vector<int> for the row data if asked.
        vector<int> at( int row ) { return data.at( row ); }
};

#endif  // MATRIX_H_