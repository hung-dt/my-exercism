#include "sieve.h"

namespace sieve {

std::vector<int> primes(const unsigned n) {
    std::vector<int> p;

    if (n < 2) return p;

    std::vector<bool> numbers(n+1, true);

    for (auto i = 2u; i < numbers.size(); ++i) {
        if (!numbers[i]) continue;

        for (auto j = i*2; j < n+1; j += i) {
            numbers[j] = false;
        }
        p.push_back(i);
    }

    return p;
}

}  // namespace sieve
