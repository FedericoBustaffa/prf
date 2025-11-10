#include "utils.hpp"

#include <algorithm>

std::vector<double> encode(const std::vector<std::string>& labels)
{
    std::vector<std::string_view> unique_values;
    std::vector<double> encoded;
    encoded.reserve(labels.size());

    for (const auto& l : labels)
    {
        auto it = std::find(unique_values.begin(), unique_values.end(), l);
        if (it == unique_values.end())
        {
            unique_values.push_back(l);
            encoded.push_back(unique_values.size() - 1);
        }
        else
            encoded.push_back(std::distance(unique_values.begin(), it));
    }

    return encoded;
}

std::vector<double> convert(const std::vector<std::string>& values)
{
    std::vector<double> converted;

    for (const auto& v : values)
        converted.push_back(std::stod(v));

    return converted;
}

std::pair<std::vector<std::vector<double>>, std::vector<double>> build_dataset(
    const dataframe& df, const std::string& target)
{
    std::vector<double> y = df[target].to_vec();

    std::vector<std::vector<double>> X;
    for (size_t i = 0; i < df.nrows(); i++)
    {
        std::vector<double> tmp;
        for (size_t j = 0; j < df.ncolumns(); j++)
        {
            if (df.headers()[j] != target)
                tmp.push_back(df[j].get(i));
        }
        X.push_back(tmp);
    }

    return {X, y};
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
