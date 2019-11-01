/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#include <vector>

#include "Matrix.hpp"
#include "Utils.hpp"


int main(void)
{
    Matrix<int> A(500, 500);
    A.fill_matrix(0, 1000);
    A.print();
    cout << endl;

    Matrix<int> B(500, 500);
    fill_matrix(B, 0, 1000);
    B.print();
    cout << endl;

    Matrix<int> C = A * B;
    C.print();

    return 0;
}
