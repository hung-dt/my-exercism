#include "grains.h"

namespace grains {

unsigned long long square(const unsigned n) {
    return 1ULL << (n-1);
}

unsigned long long total() {
    // total = 2^64 - 1
    unsigned long long total{};
    for (auto i = 1; i <= 64; ++i) {
        total += square(i);
    }
    return total;
}
}  // namespace grains
