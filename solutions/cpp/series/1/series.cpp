#include "series.h"

#include <stdexcept>

namespace series {

std::vector<std::string> slice(const std::string& number, int count)
{
    if (number.empty() || count < 1 || count > (int)number.size()) {
        throw std::domain_error("");
    }

    std::vector<std::string> slices{};

    for (size_t i = 0; i <= number.size() - count; ++i) {
        slices.emplace_back(number.substr(i, count));
    }

    return slices;
}

}  // namespace series
