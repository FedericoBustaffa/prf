#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>

class matrix
{
public:
    matrix(const double* data);

    ~matrix();

private:
    size_t m_rows, m_cols;
    double* m_data;
};

#endif
