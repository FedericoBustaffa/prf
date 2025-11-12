#include "dataframe.hpp"

#include <regex>

#include "utils.hpp"

// ---------------------------------------
// -------------- DataFrame --------------
// ---------------------------------------

DataFrame::DataFrame(const std::vector<std::string>& content,
                     const std::vector<std::string>& headers)
    : m_Rows(content.size() / headers.size()), m_Columns(headers.size()),
      m_Headers(std::move(headers)), m_Content(std::move(content))
{
    // numerical fields regex
    std::regex numerical(
        R"(^[+-]?([0-9]+\.?[0-9]*|\.[0-9]+)([eE][+-]?[0-9]+)?$)");

    for (size_t i = 0; i < m_Columns; i++)
    {
        // infer columns types
        if (std::regex_search(content[i], numerical))
            m_DataTypes.push_back(DataType::numerical);
        else
            m_DataTypes.push_back(DataType::categorical);
    }
}

std::vector<double> DataFrame::toTensor() const
{
    std::vector<double> v(m_Content.size());
    std::vector<double> tmp;
    for (size_t i = 0; i < m_Columns; i++)
    {
        if (m_DataTypes[i] == DataType::categorical)
            tmp = encode(this, i);
        else if (m_DataTypes[i] == DataType::numerical)
            tmp = convert(this, i);

        for (size_t j = 0; j < m_Rows; j++)
            v[j * m_Columns + i] = tmp[j];
    }

    return v;
}

DataFrame::~DataFrame() {}
