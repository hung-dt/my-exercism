#include "raindrops.h"

namespace raindrops {

std::string convert(const unsigned n) {
    std::string ret{};

    if (n % 3 == 0) {
        ret += "Pling";
    }

    if (n % 5 == 0) {
        ret += "Plang";
    }

    if (n % 7 == 0) {
        ret += "Plong";
    }

    if (ret.empty()) {
        ret = std::to_string(n);
    }

    return ret;
}

}  // namespace raindrops
