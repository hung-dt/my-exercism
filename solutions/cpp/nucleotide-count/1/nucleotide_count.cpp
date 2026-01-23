#include "nucleotide_count.h"

#include <stdexcept>

namespace nucleotide_count {

std::map<char, int> count(const std::string& strand) {
    std::map<char, int> ret{{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

    for (const auto c : strand) {
        auto found = ret.find(c);
        if (found != ret.end()) {
            found->second++;
        } else {
            throw std::invalid_argument("strand contains invalid nucleotides");
        }
    }

    return ret;
}

}  // namespace nucleotide_count
