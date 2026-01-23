#include "pangram.h"

#include <set>
#include <cctype>

namespace pangram {

bool is_pangram(const std::string& s) {
    if (s.size() < 26) return false;

    std::set<char> letters;

    for (auto c : s) {
        c = std::tolower(c);
        if ( c < 'a' || c > 'z') continue;
        letters.emplace(c);
    }

    return letters.size() == 26;
}

}  // namespace pangram
