#include <iostream>
#include <vector>

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

    std::vector<std::string> headers = {"sepal_length", "sepal_width",
                                        "petal_length", "petal_width", "label"};
    dataframe df = read_csv(argv[1], headers);

    auto [X, y] = build_dataset(df, "label");

    decision_tree dt("entropy");
    dt.fit(X, y);
    matrix y_pred = dt.predict(X);

    std::cout << "accuracy: " << accuracy(y_pred, y) << std::endl;

    return 0;
}
