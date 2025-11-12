#ifndef CSV_HPP
#define CSV_HPP

#include <string>
#include <vector>

#include "dataframe.hpp"

DataFrame read_csv(const std::string& filepath);

DataFrame read_csv(const std::string& filepath,
                   const std::vector<std::string>& headers);

#endif
