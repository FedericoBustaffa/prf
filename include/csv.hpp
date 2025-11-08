#ifndef CSV_HPP
#define CSV_HPP

#include <iostream>
#include <string>
#include <vector>

namespace csv
{

class frame
{
public:
    frame(const std::vector<std::string>& content, size_t ncols);

    size_t rows() const { return m_rows; }

    size_t cols() const { return m_cols; }

    std::vector<std::string_view> operator[](size_t i) const;

    std::vector<std::string_view> col(size_t i) const;

    ~frame();

private:
    std::vector<std::string> m_content;
    size_t m_rows, m_cols;
};

frame read(const char* filepath);

}; // namespace csv

inline std::ostream& operator<<(std::ostream& os,
                                const std::vector<std::string_view>& v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (i != v.size() - 1)
            os << v[i] << std::endl;
        else
            os << v[i];
    }

    return os;
}

inline std::ostream& operator<<(std::ostream& os, const csv::frame& df)
{
    for (size_t i = 0; i < df.rows(); i++)
    {
        for (size_t j = 0; j < df.cols(); j++)
            os << df[i][j] << " " << std::flush;

        if (i != df.rows() - 1)
            os << std::endl;
    }

    return os;
}

#endif
