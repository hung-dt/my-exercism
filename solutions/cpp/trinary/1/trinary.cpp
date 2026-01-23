#include "trinary.h"

namespace trinary {

long to_decimal(const std::string& tri)
{
    if (tri.empty()) return 0;

    long value{};
    long power{1};
    for (size_t i = 0; i < tri.size(); ++i) {
        auto n = int(tri[tri.size() - i - 1]) - int('0');
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
