#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "dataframe.hpp"

class matrix
{
public:
    matrix(const dataframe& df) {}

    ~matrix() {}

private:
    size_t m_rows, m_cols;
    double* m_data;
};

#endif
