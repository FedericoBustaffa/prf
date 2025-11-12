#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <vector>

class Tensor
{
public:
    Tensor(const std::vector<double>& data, const std::vector<size_t>& shape);

    inline double get(size_t i) const { return m_Data[i]; }

    Tensor operator[](size_t i) const;

    ~Tensor();

private:
    std::vector<size_t> m_Shape;
    size_t m_Stride;
    size_t m_Size;
    double* m_Data;
};

#endif
