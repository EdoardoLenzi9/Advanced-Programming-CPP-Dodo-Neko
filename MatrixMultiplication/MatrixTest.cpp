#include <vector>

#include "Matrix.hpp"
#include "Utils.hpp"

int main(void)
{
    Matrix<int> A(50, 50);
    // fill_matrix(A, 0, 100);
    A.fill_matrix(0, 1000);
    A.print();
    cout << endl;

    Matrix<int> B(50, 50);
    fill_matrix(B, 0, 1000);
    B.print();
    cout << endl;

    Matrix<int> C = A * B;
    C.print();

    return 0;
}
