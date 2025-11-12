#include <iostream>

#include "csv.hpp"

int main(int argc, const char** argv)
{
    if (argc != 2)
    {
        std::printf("USAGE: %s <filepath>\n", argv[0]);
        return 1;
    }

    DataFrame df = read_csv(argv[1], {"sepal_length", "sepal_width",
                                      "petal_length", "petal_width", "class"});

    std::printf("--- info ---\n");
    std::printf("shape: (%lu, %lu)\n", df.rows(), df.columns());

    for (size_t i = 0; i < df.columns(); i++)
        std::cout << df.headers()[i] << ": " << df.datatypes()[i] << std::endl;

    return 0;
}
