#include "difference_of_squares.h"

namespace difference_of_squares {

unsigned long square_of_sum(const unsigned n) {
    const auto sum = (n+1)*n / 2;
    return sum * sum;
}

unsigned long sum_of_squares(const unsigned n) {
    return n*(n+1)*(2*n+1)/6;
}

unsigned long difference(const unsigned n) {
    return square_of_sum(n) - sum_of_squares(n);
}

}  // namespace difference_of_squares
