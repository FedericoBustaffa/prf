#include "csv.hpp"

#include <fstream>
#include <sstream>
#include <vector>

namespace csv
{

frame::frame(const std::vector<std::string>& content, size_t ncols)
    : m_content(content), m_rows(content.size() / ncols), m_cols(ncols)
{
}

std::vector<std::string_view> frame::operator[](size_t i) const
{
    std::vector<std::string_view> r;
    for (size_t j = 0; j < m_cols; j++)
        r.push_back(m_content[i * m_cols + j]);

    return r;
}

std::vector<std::string_view> frame::col(size_t i) const
{
    std::vector<std::string_view> c;
    for (size_t j = 0; j < m_rows; j++)
        c.push_back(m_content[j * m_cols + i]);

    return c;
}

frame::~frame() {}

frame read(const char* filepath)
{
    std::ifstream file(filepath);
    std::string line;
    std::stringstream ss;
    std::string word;

    // one dimensional array to save all content
    std::vector<std::string> content;

    // do a first line read to know num of columns
    std::getline(file, line);
    ss << line;
    while (std::getline(ss, word, ','))
        content.emplace_back(word);

    // save number of columns
    size_t ncols = content.size();

    // read the rest of the file
    while (std::getline(file, line))
    {
        ss.clear();
        ss << line;
        while (std::getline(ss, word, ','))
            content.push_back(word);
    }

    return frame(content, ncols);
}

}; // namespace csv
