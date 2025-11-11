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

    dataframe df = read_csv(argv[1], {"sepal_length", "sepal_width",
                                      "petal_length", "petal_width", "class"});

    std::vector<double> v = df.to_vec();

    // decision_tree tree;
    // tree.fit(X, y);
    // std::vector<double> predictions = tree.predict(X);
    //
    // std::printf("accuracy: %.2f\n", accuracy(predictions, y));

    return 0;
}
