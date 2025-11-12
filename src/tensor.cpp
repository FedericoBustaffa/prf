#include "tensor.hpp"

#include <cstring>

Tensor::Tensor(const std::vector<double>& data,
               const std::vector<size_t>& shape)
    : m_Shape(shape)
{
    m_Size = 1;
    for (const auto& d : shape)
        m_Size *= d;

    m_Stride = 1;
    for (size_t j = 1; j < m_Shape.size(); j++)
        m_Stride *= m_Shape[j];

    m_Data = new double[m_Size];
    std::memcpy(m_Data, data.data(), m_Size * sizeof(double));
}

Tensor Tensor::operator[](size_t i) const
{
    std::vector<size_t> shape(m_Shape.begin() + 1, m_Shape.end());

    std::vector<double> data;
    for (size_t j = 0; j < m_Shape[1]; j++)
        data.push_back(m_Data[i * m_Stride + j]);

    return Tensor(data, shape);
}

Tensor::~Tensor() { delete[] m_Data; }
