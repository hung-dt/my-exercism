#include "trinary.h"

namespace trinary {

long to_decimal(const std::string& tri)
{
    long value{};
    for (auto c : tri) {
        auto n = int(c) - int('0');
        if (n < 0 || n > 2) {
            // invalid digit
            return 0;
        }
        value = value * 3 + n;
    }
    return value;
}

}  // namespace trinary
