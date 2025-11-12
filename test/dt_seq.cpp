#include <cstdio>

#include "csv.hpp"
#include "decision_tree.hpp"

int main(int argc, const char** argv)
{
    if (argc != 2)
    {
        std::printf("USAGE: %s <filepath>\n", argv[0]);
        return 1;
    }

    std::vector<std::string> headers = {"sepal_length", "sepal_width",
                                        "petal_length", "petal_width", "class"};

    std::string filepath(argv[1]);
    DataFrame df = read_csv(filepath, headers);

    // DataView features = df.slice(0, 4);
    // DataView targets = df.slice(4);

    // decision_tree tree;
    // tree.fit(X, y);
    // std::vector<double> predictions = tree.predict(X);
    //
    // std::printf("accuracy: %.2f\n", accuracy(predictions, y));

    return 0;
}
