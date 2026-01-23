#include "matching_brackets.h"

#include <vector>

namespace matching_brackets {

bool check(const std::string& text)
{
    std::vector<char> pairs;
    pairs.reserve(text.size());
    for (auto c : text) {
        if (c == '[' || c == '(' || c == '{') {
            pairs.push_back(c);
        }

        if (c == ']') {
            if (pairs.empty()) return false;
            if (pairs.back() == '[') pairs.pop_back();
            else return false;
        }

        if (c == ')') {
            if (pairs.empty()) return false;
            if (pairs.back() == '(') pairs.pop_back();
            else return false;
        }

        if (c == '}') {
            if (pairs.empty()) return false;
            if (pairs.back() == '{') pairs.pop_back();
            else return false;
        }
    }
    return pairs.empty();
}

}  // namespace matching_brackets
