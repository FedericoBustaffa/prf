#include <cstdio>
#include <vector>

#include "csv.hpp"
#include "decision_tree.hpp"

int main(int argc, const char** argv)
{
    if (argc != 2)
    {
        std::printf("USAGE: %s <dataset>\n", argv[0]);
        return 1;
    }

    // auto df = read_csv(argv[1]);
    // std::vector<std::vector<double>> X = df.get_features();
    // std::vector<uint64_t> y = df.get_targets();
    //
    // decision_tree tree;
    // tree.fit(X, y);
    // std::vector<uint64_t> p = tree.predict(X);

    return 0;
}
