#include "two_fer.h"

namespace two_fer {

std::string two_fer(const std::string& n) {
    auto name = n.empty() ? "you" : n;
    return "One for " + name + ", one for me.";
}

}  // namespace two_fer
