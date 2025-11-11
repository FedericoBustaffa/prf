#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>

#include "dataframe.hpp"

std::vector<double> encode(const dataframe* df, size_t col);

std::vector<double> convert(const dataframe* df, size_t col);

double accuracy(std::vector<double>& guessed, std::vector<double>& correct);

#endif
