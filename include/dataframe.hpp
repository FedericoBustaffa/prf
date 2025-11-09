#ifndef DATAFRAME_HPP
#define DATAFRAME_HPP

#include <string>
#include <vector>

class dataframe
{
public:
    dataframe(const std::vector<std::string>& content,
              const std::vector<std::string>& headers);

    inline size_t rows() const { return m_rows; }

    inline size_t columns() const { return m_cols; }

    inline bool empty() const { return m_content.empty(); }

    inline const std::vector<std::string>& headers() const { return m_headers; }

    std::vector<std::string> operator[](const std::string& header) const;

    ~dataframe();

private:
    size_t m_rows, m_cols;
    std::vector<std::string> m_headers;
    std::vector<std::string> m_content;
};

#endif
