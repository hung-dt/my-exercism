#include "grade_school.h"

#include <algorithm>

namespace grade_school {

void school::add(const std::string& name, const int grade) {
    if (name.empty()) return;
    auto found_grade = roster_.find(grade);
    if ( found_grade != roster_.end() ) {
        if (std::find(found_grade->second.begin(), found_grade->second.end(), name) == found_grade->second.end()) {
            found_grade->second.emplace_back(name);
            std::sort(found_grade->second.begin(), found_grade->second.end());
        }
    } else {
        roster_.emplace(grade, std::vector<std::string>{name});
    }
}

roster_t school::roster() const {
    return roster_;
}

std::vector<std::string> school::grade(const int g) const {
    auto found_grade = roster_.find(g);

    if ( found_grade != roster_.end()) {
        return found_grade->second;
    }
    return std::vector<std::string>{};
}
    
}  // namespace grade_school
