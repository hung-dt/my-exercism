#include "sum_of_multiples.h"

namespace sum_of_multiples {

unsigned to(const std::vector<unsigned>& items, const unsigned level) {
    unsigned sum{};
    for (auto n = 1u; n < level; ++n) {
        for (const auto item: items) {
            if (n % item == 0) {
                sum += n;
                break;
            }
        }    
    }
    return sum;
}

}  // namespace sum_of_multiples
