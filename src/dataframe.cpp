#include "dataframe.hpp"

#include <algorithm>

dataframe::dataframe(const std::vector<std::string>& content,
                     const std::vector<std::string>& headers)
    : m_rows(content.size() / headers.size()), m_cols(headers.size()),
      m_headers(headers), m_content(content)
{
}

std::vector<std::string> dataframe::operator[](const std::string& header) const
{
    auto h = std::find(m_headers.begin(), m_headers.end(), header);
    if (h == m_headers.end())
        return {};

    size_t idx = std::distance(m_headers.begin(), h);
    std::vector<std::string> column;
    column.reserve(m_cols);

    for (size_t i = 0; i < m_rows; i++)
        column.push_back(m_content[i * m_cols + idx]);

    return column;
}

dataframe::~dataframe() {}
