#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

#include "dataframe.hpp"
#include "matrix.hpp"

std::vector<double> encode(const std::vector<std::string>& labels);

std::vector<double> convert(const std::vector<std::string>& values);

std::pair<matrix, matrix> build_dataset(const dataframe& df,
                                        const std::string_view& target);

double accuracy(matrix predicted, matrix target);

#endif
