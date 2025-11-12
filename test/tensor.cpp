#include <cstdio>
#include <random>

#include "tensor.hpp"

int main(int argc, const char** argv)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> dist(0, 1);

    std::vector<double> data;
    for (size_t i = 0; i < 16; i++)
        data.push_back(dist(rng));

    Tensor m(data, {4, 4});
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
            std::printf("%.2f ", m[i].get(j));
        std::printf("\n");
    }

    Tensor v = m[0];
    for (size_t i = 0; i < 4; i++)
        std::printf("%.2f\n", v.get(i));

    return 0;
}
