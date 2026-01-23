#pragma once

#include <string>
#include <unordered_set>

namespace allergies {

class allergy_test {
public:
    allergy_test(const unsigned);

    bool is_allergic_to(const std::string&) const;

    std::unordered_set<std::string> get_allergies() const;

private:
    unsigned score_;
};

}  // namespace allergies
