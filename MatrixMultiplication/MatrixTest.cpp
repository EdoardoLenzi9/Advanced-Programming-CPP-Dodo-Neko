#include <vector>

#include "Matrix.hpp"
#include "Utils.hpp"

int main(void)
{
    Matrix<int> A(5, 6);
    // fill_matrix(A, 0, 100);
    A.fill_matrix(0, 100);
    A.print();
    cout << endl;

    Matrix<int> B(5,6);
    fill_matrix(B, 0, 100);
    B.print();
    cout << endl;

    Matrix<int> C = A * B;
    C.print();

    return 0;
}