#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>

class Matrix
{
public:
    Matrix(const double* data, size_t rows, size_t cols);

    Matrix(const Matrix& other);

    Matrix(Matrix&& other);

    inline size_t rows() const { return m_Rows; }

    inline size_t cols() const { return m_Cols; }

    ~Matrix();

private:
    size_t m_Rows, m_Cols;
    double* m_Data;
};

#endif
