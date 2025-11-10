#include <iostream>

#include "csv.hpp"
#include "utils.hpp"

int main(int argc, const char** argv)
{
    if (argc != 2)
    {
        std::cout << "USAGE: " << argv[0] << " <filepath>" << std::endl;
        return 1;
    }

    dataframe df = read_csv(argv[1]);

    std::cout << "--- info ---" << std::endl;
    std::cout << "shape: (" << df.nrows() << ", " << df.ncolumns() << ")"
              << std::endl;

    for (const auto& h : df.headers())
        std::cout << h << ": " << df[h].type() << std::endl;

    auto [X, y] = build_dataset(df, "class");
    for (size_t i = 0; i < X.size(); i++)
    {
        for (size_t j = 0; j < X[i].size(); j++)
            std::cout << X[i][j] << std::flush;
        std::cout << std::endl;
    }

    return 0;
}
