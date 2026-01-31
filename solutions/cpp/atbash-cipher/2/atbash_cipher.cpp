#include "atbash_cipher.h"

#include <cctype>

namespace atbash_cipher {

const char* PLAIN = "abcdefghijklmnopqrstuvwxyz";

const char* CIPHER = "zyxwvutsrqponmlkjihgfedcba";

std::string encode(const std::string& text)
{
    std::string res;
    int count = 0;
    for (size_t i = 0; i < text.size(); ++i) {
        auto e = std::tolower(text[i]);
        if (std::isalpha(e)) {
            res += CIPHER[e - 'a'];
            count++;
        } else if (std::isdigit(e)) {
            res += e;
            count++;
        }
        if (count == 5) {
            res += ' ';
            count = 0;
        }
    }
    if (res.back() == ' ') {
        res.pop_back();
    }
    return res;
}

std::string decode(const std::string& text)
{
    std::string res;
    for (const auto c : text) {
        if (std::isalpha(c)) {
            res += PLAIN['z' - c];
        } else if (std::isdigit(c)) {
            res += c;
        }
    }
    return res;
}

}  // namespace atbash_cipher
