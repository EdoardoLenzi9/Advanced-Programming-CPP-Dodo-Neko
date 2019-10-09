#include <iostream>
#include <vector>

#define NEWLINE std::cout<<std::endl;

class Matrix{

	int rows;
	int cols;
	std::vector<std::vector<int>> data;

	public:  
	Matrix(int rows, int cols){
		this->rows = rows;
		this->cols = cols;

		//turns out, push_back doesnt actually insert elements at the back end of a vector, but instead
		//adds new elements at the back, increasing the size of the vector.
		for(int i=0; i<this->rows; i++){
			this->data.push_back(std::vector<int>(this->cols, 0));
		}

	}

	int getRows(){
		return this->rows;
	}

	int getCols(){
		return this->cols;
	}

	//output the whole matrix on the console
	void print(){

	        for (std::vector<int> row: this->data) {
	                for (int col: row) {
				std::cout<<col<<"\t";
	                }
		std::cout<<std::endl;
		}
	}

	//allow setting a specific value
	void setValue(int row, int col, int value){
		this->data.at(row).at(col) = value;
	}

	//make Matrix::at() return a vector<int> for the row data if asked.
	std::vector<int> at(int row){
		return this->data.at(row);
	}

	//standard matrix multiplication that adds another matrix to this one.
	void addMatrix(Matrix B){
		if ( B.getRows() != this->rows || B.getCols() != this->cols ){
			throw std::invalid_argument("matrixes must be of the same dimensions to add");
		}
		
		for (int row=0; row<this->rows;row++){
			for (int col=0; col<this->cols;col++){
				this->data.at(row).at(col) += B.at(row).at(col);
			}
		}
	}	
};



int main(){

	int rows = 3;
	int cols = 3;
	Matrix A (rows, cols);
	Matrix B (rows, cols);
	
	int k = 0;
	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++){
			A.setValue(i,j,k++);
			B.setValue(i,j,k++);
		}
	}	

	A.print();
	NEWLINE
	B.print();
	NEWLINE
	A.addMatrix(B);
	A.print();
}
