#pragma once

namespace triangle {

enum class flavor {
    equilateral,
    isosceles,
    scalene
};

flavor kind(double, double, double);

}  // namespace triangle
