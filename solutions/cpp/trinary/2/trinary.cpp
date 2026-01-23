#include "trinary.h"

namespace trinary {

long to_decimal(const std::string& tri)
{
    if (tri.empty()) return 0;

    long value{};
    long power{1};
    for (auto it = tri.rbegin(); it != tri.rend(); ++it) {
        auto n = int(*it) - int('0');
        if (n < 0 || n > 2) {
            // invalid digit
            return 0;
        }
        value += n * power;
        power *= 3;
    }
    return value;
}

}  // namespace trinary
