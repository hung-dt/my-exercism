#include "sum_of_multiples.h"

#include <unordered_set>

static std::vector<unsigned> multiplesOf(const unsigned base, const unsigned level) {
    std::vector<unsigned> m;
    auto i = base;
    while (i < level) {
        m.push_back(i);
        i += base;
    }
    return m;
}

namespace sum_of_multiples {

unsigned to(const std::vector<unsigned>& items, const unsigned level) {
    std::unordered_set<unsigned> multiples;

    unsigned sum{};
    for (const auto i : items) {
        auto m = multiplesOf(i, level);

        for (const auto n : m) {
            auto ok = multiples.emplace(n);
            if (ok.second) {
                sum += n;
            }
        }
    }
    return sum;
}

}  // namespace sum_of_multiples
