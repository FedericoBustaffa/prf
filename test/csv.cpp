#include <iostream>
#include <vector>

#include "csv.hpp"

int main(int argc, const char** argv)
{
    if (argc != 2)
    {
        std::cout << "USAGE: " << argv[0] << " <filepath>" << std::endl;
        return 1;
    }

    std::vector<std::string> headers = {"sepal_length", "sepal_width",
                                        "petal_length", "petal_width", "label"};
    dataframe df = csv::read(argv[1], headers);

    std::cout << "rows: " << df.rows() << std::endl;
    std::cout << "columns: " << df.columns() << std::endl;

    for (const auto& h : df.headers())
        std::cout << "header: " << h << std::endl;

    for (const auto& v : df["sepal_length"])
        std::cout << v << std::endl;

    return 0;
}
