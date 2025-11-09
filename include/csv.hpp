#ifndef CSV_HPP
#define CSV_HPP

#include <fstream>
#include <string>
#include <vector>

#include "dataframe.hpp"

namespace csv
{

std::vector<std::string> readline(std::ifstream& file);

std::vector<std::string> readline(const std::string& filepath);

dataframe read(const std::string& filepath);

dataframe read(const std::string& filepath,
               const std::vector<std::string>& headers);

}; // namespace csv

#endif
