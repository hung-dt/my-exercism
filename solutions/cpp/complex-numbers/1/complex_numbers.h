#pragma once

namespace complex_numbers {

class Complex
{
public:
    Complex(const double real, const double img)
        : real_( real ), img_( img )
    {}

    Complex(const double real) : real_(real) {}

    double real() const { return real_; }

    double imag() const { return img_; }

    double abs() const;

    Complex conj() const;

    Complex exp() const;

private:
    double real_{};
    double img_{};
};

Complex operator+(const Complex&, const Complex&);

Complex operator-(const Complex&, const Complex&);

Complex operator*(const Complex&, const Complex&);

Complex operator/(const Complex&, const Complex&);    

}  // namespace complex_numbers
