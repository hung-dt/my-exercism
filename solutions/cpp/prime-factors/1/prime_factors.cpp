#include "prime_factors.h"

namespace prime_factors {

std::vector<long long> of(long long n)
{
    std::vector<long long> v;
    for (long long d = 2; d * d <= n; ++d ) {
        while (n % d == 0) {
            v.emplace_back(d);
            n /= d;
        }
    }
    if (n > 1) v.emplace_back(n);
    return v;    
}

}  // namespace prime_factors
