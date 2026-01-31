#include "complex_numbers.h"

#include <cmath>

namespace complex_numbers {

double Complex::abs() const
{
    return std::sqrt(real_ * real_ + img_ * img_);
}

Complex Complex::conj() const
{
    return Complex{ real_, -img_};
}

Complex Complex::exp() const
{
    return Complex{std::exp(real_) * std::cos(img_), std::exp(real_) * std::sin(img_)};
}

Complex operator+(const Complex& left, const Complex& right)
{
    return Complex{ left.real() + right.real(), left.imag() + right.imag() };
}

Complex operator-(const Complex& left, const Complex& right)
{
    return Complex{ left.real() - right.real(), left.imag() - right.imag() };
}

Complex operator*(const Complex& left, const Complex& right)
{
    return Complex{ left.real() * right.real() - left.imag() * right.imag(),
                    left.imag() * right.real() + left.real() * right.imag() };
}

Complex operator/(const Complex& left, const Complex& right)
{
    const auto deno = right.real() * right.real() + right.imag() * right.imag();
    const auto real = (left.real() * right.real() + left.imag() * right.imag()) / deno;
    const auto img = (left.imag() * right.real() - left.real() * right.imag()) / deno;
    return Complex{ real, img };
}

}  // namespace complex_numbers
