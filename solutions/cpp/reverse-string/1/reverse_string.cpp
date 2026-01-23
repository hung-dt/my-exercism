#include "reverse_string.h"

namespace reverse_string {

std::string reverse_string(const std::string& s) {
    std::string r;
    for (auto i = s.rbegin(); i != s.rend(); ++i) {
        r += *i;
    }
    return r;
}

}  // namespace reverse_string
