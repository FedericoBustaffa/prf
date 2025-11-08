#include <iostream>

#include "csv.hpp"

int main(int argc, const char** argv)
{
    if (argc != 2)
    {
        std::cout << "USAGE: " << argv[0] << " <filepath>" << std::endl;
        return 1;
    }

    csv::frame df = csv::read(argv[1]);
    std::cout << df[0] << std::endl;
    std::cout << df.col(0) << std::endl;
    std::cout << df << std::endl;

    return 0;
}
