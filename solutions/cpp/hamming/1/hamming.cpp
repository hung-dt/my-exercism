#include "hamming.h"

#include <stdexcept>

namespace hamming {

int compute(const std::string& s1, const std::string& s2) {
    if (s1.empty() && s2.empty()) return 0;

    if (s1.empty() || s2.empty()) {
        throw std::domain_error("empty strand");
    }

    if (s1.size() != s2.size()) {
        throw std::domain_error("different size strands");
    }

    int count{};
    for (auto i = 0U; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) count++;
    }

    return count;
}

}  // namespace hamming
