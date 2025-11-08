#include "csv.hpp"

#include <fstream>
#include <iostream> // to remove
#include <regex>
#include <sstream>
#include <vector>

namespace csv
{

field_type infer_type(const std::string& s)
{
    std::regex integer(R"(^[+-]?[0-9]+$)");
    std::regex floating_point(
        R"(^[+-]?([0-9]+\.?[0-9]*|\.[0-9]+)([eE][+-]?[0-9]+)?$)");

    if (std::regex_search(s, integer))
        return field_type::integer;

    if (std::regex_search(s, floating_point))
        return field_type::floating_point;

    return field_type::categorical;
}

dataframe read(const char* filepath, char separator)
{
    std::ifstream file(filepath);
    std::string line;
    std::stringstream ss;
    std::string word;

    std::vector<std::string> row;
    std::vector<field_type> types;
    std::vector<std::vector<std::string>> table;

    // read the first line and infer types
    std::getline(file, line);
    ss << line;
    while (std::getline(ss, word))
    {
        types.push_back(infer_type(word));
        row.push_back(word);
    }

    while (std::getline(file, line))
    {
        ss << line;
        row.clear();
        while (std::getline(ss, word, separator))
        {
            row.push_back(word);
        }

        table.push_back(row);
        ss.clear();
    }

    for (const auto& r : table)
    {
        for (const auto& c : r)
            std::cout << c << ", " << std::flush;
        std::cout << std::endl;
    }

    return {};
}

}; // namespace csv
