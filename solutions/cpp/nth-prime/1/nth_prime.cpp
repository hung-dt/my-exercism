#include "nth_prime.h"

#include <cmath>
#include <stdexcept>

bool is_prime(const unsigned long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (auto i = 2; i < std::sqrt(n) + 1; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
namespace nth_prime {

unsigned long nth(const unsigned n) {
    if (n < 1) {
        throw std::domain_error("weird case");
    }

    unsigned count{};

    unsigned long prime{1};
    while (count < n) {
        while (!is_prime(prime)) prime++;
        if (++count == n) {
            break;
        }
        prime++;
    }

    return prime;
}

}  // namespace nth_prime
