#include "utils.hpp"

#include <unordered_map>

std::vector<double> encode(const DataFrame* df, size_t col)
{
    const std::vector<std::string>& content = df->content();
    std::unordered_map<std::string, double> mappings;

    std::vector<double> encoded;
    encoded.reserve(content.size());

    std::string field;
    unsigned int nvalues = 0; // counter of possible values

    for (size_t i = 0; i < df->rows(); i++)
    {
        field = content[i * df->columns() + col];
        if (mappings.contains(field))
            encoded.push_back(mappings[field]);
        else
        {
            encoded.push_back(nvalues);
            mappings[field] = nvalues;
            nvalues++;
        }
    }

    return encoded;
}

std::vector<double> convert(const DataFrame* df, size_t col)
{
    const std::vector<std::string>& content = df->content();
    std::vector<double> converted;

    for (size_t i = 0; i < df->rows(); i++)
        converted.push_back(std::stod(content[i * df->columns() + col]));

    return converted;
}

double accuracy(std::vector<double>& guessed, std::vector<double>& correct)
{
    double acc = 0.0;
    for (size_t i = 0; i < guessed.size(); i++)
    {
        if (guessed[i] == correct[i])
            acc += 1;
    }

    return acc / correct.size();
}
