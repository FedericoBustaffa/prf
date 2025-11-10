#ifndef DECISION_TREE_HPP
#define DECISION_TREE_HPP

#include <string>

#include "matrix.hpp"

class decision_tree
{
public:
    decision_tree(const std::string& impurity = "entropy");

    void fit(matrix X, matrix y);

    matrix predict(matrix X) const;

    ~decision_tree();

private:
};

#endif
