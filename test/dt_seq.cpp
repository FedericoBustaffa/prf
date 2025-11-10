#include <iostream>

#include "csv.hpp"
#include "decision_tree.hpp"
#include "utils.hpp"

int main(int argc, const char** argv)
{
    if (argc != 2)
    {
        std::cout << "USAGE: " << argv[0] << " <filepath>" << std::endl;
        return 1;
    }

    dataframe df = read_csv(argv[1], {"sepal_length", "sepal_width",
                                      "petal_length", "petal_width", "class"});

    auto [X, y] = build_dataset(df, "class");

    decision_tree tree;
    tree.fit(X, y);
    std::vector<double> predictions = tree.predict(X);

    std::printf("accuracy: %.2f\n", accuracy(predictions, y));

    return 0;
}
