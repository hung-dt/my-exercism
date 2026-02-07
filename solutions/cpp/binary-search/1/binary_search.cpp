#include "binary_search.h"

#include <stdexcept>

namespace binary_search {

// Assume that data is sorted
std::size_t find(const std::vector<int> data, const int n)
{
    if (data.empty()) {
        throw std::domain_error("empty list");
    }

    size_t start = 0;
    size_t last = data.size() - 1;
    if (n < data[start] || n > data[last]) {
        throw std::domain_error("Item not in list!");
    }

    while (start <= last) {
        auto mid = (start + last)/2;
        if (data[mid] == n) return mid;
        if (data[mid] > n) {
            last = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    throw std::domain_error("Item not found!");
}

}  // namespace binary_search
