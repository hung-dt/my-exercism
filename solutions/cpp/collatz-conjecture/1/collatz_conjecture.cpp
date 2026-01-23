#include "collatz_conjecture.h"

#include <stdexcept>

namespace collatz_conjecture {

int steps(int n) {
    if (n < 1) {
        throw std::domain_error("invalid number");
    }

    int count{};

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        count++;
    }

    return count;
}

}  // namespace collatz_conjecture
