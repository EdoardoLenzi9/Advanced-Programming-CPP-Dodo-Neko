#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> *A){
//	for (int i = 0; i < (*A).size(); i++){
//		for (int j = 0; j < (*A)[i].size(); j++){
//			cout<<(*A)[i].at(j)<<"\t";
//		}
//		cout<<endl;
//	}	

	//in this version, iterators are used instead of for loops. this provides a much nicer solution and makes everything more readable.
	for (vector<int> row: (*A)) {
		for (int col: row) {
			cout<<col<<"\t";
		}
		cout<<endl;
	}
}

vector<vector<int>> addMatrix(vector<vector<int>> *A, vector<vector<int>> *B) {

	//this expects the matrices to be of rectangular size.
	//TODO: maybe make this function more robust to misuse by checking the full dimensions of a matrix 
	//i'm not entirely sure if there's a simple way to do this other than just brutally iterating over every row's column amount
	if ( ((*A).size() != (*B).size()) || (*A)[0].size() != (*B)[0].size() ) {
		throw invalid_argument("matrixes must be of the same dimensions");
	}

//	vector<vector<int>> C((*A).size());
//
//      for (int i = 0; i < (*A).size(); i++){
//              C[i].resize((*A)[i].size()); // initiates every vector in the vector
//      }

	//in this version, vector of vectors C is initialised by supplying an underlying vector that gets created first.
	//i'm not entirely sure, but i think this means more memory usage but less runtime because the iteration isnt done (TODO: prove)
	vector<int> col((*A)[0].size());
	vector<vector<int>> C((*A).size(), col);


	//the iterator solution might not be applicable here due to the need of the col and row number to determine the specific
	//element to put the result in in the C matrix.
	//TODO: create a custom "matrix" class that allows filling from the first element to the last independent of columns and rows
	for (int i = 0; i < (*A).size(); i++){

		for (int j = 0; j < (*A)[i].size(); j++){
			
			C[i].at(j) = (*A)[i].at(j)+(*B)[i].at(j);
		}
	}


	return C;
}

int main(){

	const int A_cols = 4;
	const int A_rows = 5;
	vector<vector<int>> A(A_rows);

	for (int i = 0; i < A_rows; i++){
		A[i].resize(A_cols); // initiates every vector in the vector
	}

	int k = 0;

	for (int i = 0; i < A.size(); i++){

		for (int j = 0; j < A[i].size(); j++){
			
			A[i].at(j) = k++;
		}
	}

//	this makes the matrices incompatible for addition.
//	const int B_cols = 5;
//	const int B_rows = 5;

	const int B_cols = 4;
	const int B_rows = 5;

	vector<vector<int>> B(B_rows);

	for (int i = 0; i < B_rows; i++){
		B[i].resize(B_cols); // initiates every vector in the vector
	}

	k = 0;

	for (int i = 0; i < B.size(); i++){

		for (int j = 0; j < B[i].size(); j++){
			
			B[i].at(j) = k++;
		}
	}
	
	try{
		cout<<"Matrix A:"<<endl;
		printMatrix(&A);
		cout<<"Matrix B:"<<endl;
		printMatrix(&B);
		vector<vector<int>> C = addMatrix(&A, &B);
		cout<<"Matrix C (A+B):"<<endl;
		printMatrix(&C);
	}
	catch (const std::invalid_argument& e) {
		std::cerr<<"Invalid argument: "<<e.what()<<endl;
	}
}
