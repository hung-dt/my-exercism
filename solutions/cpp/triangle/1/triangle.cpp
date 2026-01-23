#include "triangle.h"

#include <stdexcept>

namespace triangle {

flavor kind(double a, double b, double c) {
    if ( a + b < c || a + c < b || b + c < a) {
        throw std::domain_error("not a triangle");
    }

    if ( a == 0 && b == 0 && c == 0) {
        throw std::domain_error("all zero sides is not a triangle");
    }

    if (a < 0 || b < 0 || c < 0) {
        throw std::domain_error("triangle with negative side");
    }

    if ( a == b && b == c) {
        return flavor::equilateral;
    }

    if ( a == b || b == c || c == a) {
        return flavor::isosceles;
    }

    return flavor::scalene;
}

}  // namespace triangle
