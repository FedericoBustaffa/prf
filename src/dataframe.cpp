#include "dataframe.hpp"

#include <regex>

#include "utils.hpp"

dataframe::dataframe(const std::vector<std::string>& content,
                     const std::vector<std::string>& headers)
    : m_nrows(content.size() / headers.size()), m_ncols(headers.size()),
      m_headers(headers), m_content(content)
{
    // numerical fields regex
    std::regex numerical(
        R"(^[+-]?([0-9]+\.?[0-9]*|\.[0-9]+)([eE][+-]?[0-9]+)?$)");

    for (size_t i = 0; i < m_ncols; i++)
    {
        // infer columns types
        if (std::regex_search(content[i], numerical))
            m_datatypes.push_back(datatype::numerical);
        else
            m_datatypes.push_back(datatype::categorical);
    }
}

std::vector<double> dataframe::to_vec() const
{
    std::vector<double> v(m_content.size());
    std::vector<double> tmp;
    for (size_t i = 0; i < m_ncols; i++)
    {
        if (m_datatypes[i] == datatype::categorical)
            tmp = encode(this, i);
        else if (m_datatypes[i] == datatype::numerical)
            tmp = convert(this, i);

        for (size_t j = 0; j < m_nrows; j++)
            v[j * m_ncols + i] = tmp[j];
    }

    return v;
}

dataframe::~dataframe() {}
