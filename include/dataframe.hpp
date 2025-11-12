#ifndef DATAFRAME_HPP
#define DATAFRAME_HPP

#include <ostream>
#include <string>
#include <vector>

enum class DataType
{
    numerical,
    categorical
};

class DataView
{
public:
    DataView();

    ~DataView();

private:
    size_t m_RowBegin, m_ColumnBegin;
    size_t m_RowEnd, m_ColumnEnd;

    std::vector<std::string>* m_Headers;
    std::vector<DataType>* m_DataTypes;
    std::vector<std::string>* m_View;
};

class DataFrame
{
public:
    DataFrame(const std::vector<std::string>& content,
              const std::vector<std::string>& headers);

    inline size_t rows() const { return m_Rows; }

    inline size_t columns() const { return m_Columns; }

    inline const std::vector<std::string>& headers() const { return m_Headers; }

    inline const std::vector<DataType>& datatypes() const
    {
        return m_DataTypes;
    }

    inline const std::vector<std::string>& content() const { return m_Content; }

    std::vector<double> toTensor() const;

    ~DataFrame();

private:
    size_t m_Rows, m_Columns;
    std::vector<std::string> m_Headers;
    std::vector<DataType> m_DataTypes;
    std::vector<std::string> m_Content;
};

inline std::ostream& operator<<(std::ostream& os, DataType dt)
{
    if (dt == DataType::numerical)
        os << "numerical";
    else
        os << "categorical";

    return os;
}

#endif
