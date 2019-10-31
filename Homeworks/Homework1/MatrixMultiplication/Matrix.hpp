#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <iostream>
#include <random>

using namespace std;

template <typename T>
class Matrix
{
private:
    unsigned int rows;
    unsigned int cols;
    vector<vector<T>> data;

public:
    /**
     * @brief  creates a matrix object with given dimension size arguments
     * @note   fills every value with 0
     * @param  num_row: number of matrix rows
     * @param  num_col: number of matrix columns
     * @retval none
     */
    Matrix(unsigned int r, unsigned int c) : rows(r), cols(c),
                                             data(vector<vector<T>>(r, vector<T>(c))){};

    // Output the whole matrix on the console
    void print()
    {
        for (vector<int> row : this->data)
            for (int value : row)
                cout << value << "\t";

        cout << endl;
    }

    // Getters and setters
    unsigned int getRows() { return rows; }
    unsigned int getCols() { return cols; }

    /**
     * @brief  overloading of [] operator to enable the direkt access of matrix elements, e.g., A[0][0]
     * @note   because it made sense to use it
     * @param  i: the row index
     * @retval returns the vector<T> at index i
     */
    vector<T> &operator[](const int i)
    {
        return data[i];
    }

    /**
     * @brief  overloading of * operator to enable matrix multiplication 
     * @note   it was a nice way to implement the matrix multiplication
     * @param  &B: the second matrix
     * @retval a matrix, which is the product of this_matrix * B
     */
    Matrix operator*(Matrix &B)
    {
        Matrix C(this->data.size(), B[0].size());

        for (int i = 0; i < this->data.size(); i++)
            for (int k = 0; k < B[0].size(); k++)
                for (int v = 0; v < this->data.size(); v++)
                    C[i][k] += this->data[i][v] * B[v][k];
        return C;
    }

    /**
     * @brief  overloading of + operator to enable matrix addition
     * @note   
     * @param  &B: 
     * @retval a matrix, which is the addition of this_matrix + B
     */
    Matrix operator+(Matrix &B)
    {
        if (B.getRows() != this->rows || B.getCols() != this->cols)
            throw invalid_argument("matrixes must be of the same dimensions to add");

        Matrix C(this->data.size(), B[0].size());

        for (int row = 0; row < this->rows; ++row)
            for (int col = 0; col < this->cols; ++col)
                C[row][col] = this->data[row][col] + B[row][col];

        return C;
    };

    /**
 * @brief  fills the given matrix with randomized integer/real values (uniformly distributed)
 * @note   uses real numbers as random values, which get pruned in case of integer values
 * @param  &matrix: the address reference of the matrix
 * @param  rand_from: the starting range of randomized ints
 * @param  rand_to: the ending range of randomized ints
 * @retval None
 */
    void fill_matrix(int rand_from, int rand_to)
    {
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(rand_from, rand_to);

        for (int i = 0; i < this->getRows(); i++)
            for (int k = 0; k < this->getCols(); k++)
                data[i][k] = (T)dis(gen);
    }
};

#endif // MATRIX_H_