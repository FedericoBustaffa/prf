#ifndef CSV_HPP
#define CSV_HPP

#include "dataframe.hpp"

namespace csv
{

enum class field_type
{
    integer,
    floating_point,
    categorical,
};

dataframe read(const char* filepath, char separator = ',');

}; // namespace csv

#endif
