#include "say.h"

#include <map>
#include <stdexcept>
#include <vector>

namespace say {

std::vector<std::string> NUMBERS = {
  "zero",     "one",      "two",      "three",   "four",    "five",
  "six",      "seven",    "eight",    "nine",    "ten",     "eleven",
  "twelve",   "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
  "eighteen", "nineteen", "twenty"
};

std::map<int, std::string> NUMBER_TENS = { { 20, "twenty" }, { 30, "thirty" },
                                           { 40, "forty" },  { 50, "fifty" },
                                           { 60, "sixty" },  { 70, "seventy" },
                                           { 80, "eighty" }, { 90, "ninety" } };

// say [0..99]
std::string say_0_99(long n)
{
  if ( n < 21 ) {
    return NUMBERS[n];
  }

  auto d = (n / 10) * 10;
  auto r = n % 10;
  auto word = NUMBER_TENS[d];
  if ( r > 0 ) {
    word += "-" + NUMBERS[r];
  }
  return word;
}

// say [100..999]
std::string say_100_999(long n)
{
  auto d = n / 100;
  auto r = n % 100;
  auto word = NUMBERS[d] + " hundred";
  if ( r > 0 ) {
    word += " " + say_0_99(r);
  }
  return word;
}

// say [0..999]
std::string say_less_than_thousand(long n) {
    // say [0..99]
    if (n < 100) {
        return say_0_99(n);
    }

    // say [100..999]
    if (n < 1000) {
        return say_100_999(n);
    }

    return std::string{};
}

std::string in_english(long n) {
  long n_max = 1'000'000'000'000;
  if ( n < 0 || n >= n_max ) {
    throw std::domain_error("Number out of range.");
  }

  std::vector<std::string> levels = { "thousand", "million", "billion" };
  int idx = levels.size() + 1;

  std::string word;
  while ( n > 999 ) {
    auto d = n / n_max;
    idx--;
    if ( d == 0 ) {
      n_max /= 1000;
      continue;
    }
    word += say_less_than_thousand(d) + " " + levels[idx] + " ";
    n %= n_max;
    if ( n == 0 ) return word.substr(0, word.size() - 1);
    n_max /= 1000;
  }

  word += say_less_than_thousand(n);
  return word;
}

}  // namespace say
