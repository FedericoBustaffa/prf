#ifndef DECISION_TREE_HPP
#define DECISION_TREE_HPP

#include <vector>

class DecisionTree
{
public:
    DecisionTree();

    void fit(const std::vector<std::vector<double>>& X,
             const std::vector<double>& y);

    std::vector<double> predict(const std::vector<std::vector<double>>& X);

    ~DecisionTree();

private:
    double entropy(const std::vector<double>& y);

private:
};

#endif
