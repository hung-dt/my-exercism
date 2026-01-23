#include "allergies.h"

#include <map>

static std::map<unsigned, std::string> allergies_table = {
{1, "eggs"}, {2, "peanuts"}, {4, "shellfish"}, {8, "strawberries"},
{16, "tomatoes"}, {32, "chocolate"}, {64, "pollen"}, {128, "cats"}
};

namespace allergies {

allergy_test::allergy_test(const unsigned s)
    : score_(s)
    {}

bool allergy_test::is_allergic_to(const std::string& item) const {
    for (const auto& a : allergies_table) {
        if (score_ & a.first && a.second == item)
            return true;
    }
    return false;
}

std::unordered_set<std::string> allergy_test::get_allergies() const {
    std::unordered_set<std::string> s;
    for (const auto& a : allergies_table) {
        if (score_ & a.first) {
            s.emplace(a.second);
        }
    }
    return s;
}
}  // namespace allergies
