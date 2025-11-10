#include "dataframe.hpp"

#include <algorithm>
#include <stdexcept>

dataframe::dataframe(const std::vector<std::vector<std::string>>& content,
                     const std::vector<std::string>& headers)
{
    for (size_t i = 0; i < content.size(); i++)
    {
        m_fields.emplace_back(headers[i], content[i]);
        m_headers.push_back(headers[i]);
    }
}

field dataframe::operator[](const std::string_view& header) const
{
    auto h = std::find(m_headers.begin(), m_headers.end(), header);
    if (h == m_headers.end())
        throw std::runtime_error("no such header");

    size_t idx = std::distance(m_headers.begin(), h);
    return m_fields[idx];
}

std::vector<double> dataframe::columns() const
{
    std::vector<double> values;
    values.reserve(nrows() * ncolumns());

    for (const auto& f : m_fields)
        for (const auto& v : f.as_double())
            values.push_back(v);

    return values;
}

std::vector<double> dataframe::rows() const
{
    std::vector<double> values;
    values.reserve(nrows() * ncolumns());

    for (size_t i = 0; i < nrows(); i++)
    {
        for (const auto& f : m_fields)
            values.push_back(f.as_double()[i]);
    }

    return values;
}

dataframe::~dataframe() {}
