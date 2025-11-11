#ifndef DATAFRAME_HPP
#define DATAFRAME_HPP

#include <ostream>
#include <string>
#include <vector>

class dataframe
{
public:
    enum class datatype
    {
        numerical,
        categorical
    };

public:
    dataframe(const std::vector<std::string>& content,
              const std::vector<std::string>& headers);

    inline size_t nrows() const { return m_nrows; }

    inline size_t ncolumns() const { return m_ncols; }

    inline const std::vector<std::string>& headers() const { return m_headers; }

    inline const std::vector<datatype>& datatypes() const
    {
        return m_datatypes;
    }

    inline const std::vector<std::string>& content() const { return m_content; }

    std::vector<double> to_vec() const;

    ~dataframe();

private:
    size_t m_nrows, m_ncols;
    std::vector<std::string> m_headers;
    std::vector<datatype> m_datatypes;
    std::vector<std::string> m_content;
};

inline std::ostream& operator<<(std::ostream& os, dataframe::datatype dt)
{
    if (dt == dataframe::datatype::numerical)
        os << "numerical";
    else
        os << "categorical";

    return os;
}

#endif
