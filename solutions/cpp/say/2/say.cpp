#include "say.h"

#include <map>
#include <stdexcept>
#include <vector>

namespace say {

std::vector<std::string> NUMBERS = {
  "zero",    "one",     "two",       "three",    "four",
  "five",    "six",     "seven",     "eight",    "nine",
  "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

std::map<int, std::string> NUMBER_TENS = { { 20, "twenty" }, { 30, "thirty" },
                                           { 40, "forty" },  { 50, "fifty" },
                                           { 60, "sixty" },  { 70, "seventy" },
                                           { 80, "eighty" }, { 90, "ninety" } };

// say [0..99]
std::string say_0_99(long n)
{
  if ( n < 20 ) {
    return NUMBERS[n];
  }

  auto d = (n / 10) * 10;
  auto r = n % 10;
  auto res = NUMBER_TENS[d];
  if ( r > 0 ) {
    res += "-" + NUMBERS[r];
  }
  return res;
}

// say [100..999]
std::string say_100_999(long n)
{
  auto d = n / 100;
  auto r = n % 100;
  auto res = NUMBERS[d] + " hundred";
  if ( r > 0 ) {
    res += " " + say_0_99(r);
  }
  return res;
}

// say [0..999]
std::string say_less_than_thousand(long n)
{
  // say [0..99]
  if ( n < 100 ) {
    return say_0_99(n);
  }

  // say [100..999]
  if ( n < 1000 ) {
    return say_100_999(n);
  }

  return std::string{};
}

std::string in_english(long n) {
  long n_max = 1'000'000'000'000;
  if ( n < 0 || n >= n_max ) {
    throw std::domain_error("Number out of range.");
  }

  std::map<long, std::string> levels = { { 1000, "thousand" },
                                         { 1'000'000, "million" },
                                         { 1'000'000'000, "billion" } };

  std::string res;
  while ( n > 999 ) {
    auto d = n / n_max;
    if ( d == 0 ) {
      n_max /= 1000;
      continue;
    }
    res += say_less_than_thousand(d) + " " + levels[n_max] + " ";
    n %= n_max;
    if ( n == 0 ) return res.substr(0, res.length() - 1);
    n_max /= 1000;
  }

  res += say_less_than_thousand(n);
  return res;
}

}  // namespace say
