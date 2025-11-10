#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <utility>
#include <vector>

#include "dataframe.hpp"

std::vector<double> encode(const std::vector<std::string>& labels);

std::vector<double> convert(const std::vector<std::string>& values);

std::pair<std::vector<std::vector<double>>, std::vector<double>> build_dataset(
    const dataframe& df, const std::string& target);

double accuracy(std::vector<double>& guessed, std::vector<double>& correct);

#endif
