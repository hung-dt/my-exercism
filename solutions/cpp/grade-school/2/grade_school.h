#pragma once

#include <string>
#include <map>
#include <vector>

using roster_t = std::map<int, std::vector<std::string>>;

namespace grade_school {

class school {

public:
    void add(const std::string&, const int);

    roster_t roster() const;

    std::vector<std::string> grade(const int) const;

private:
    roster_t roster_;
};

}  // namespace grade_school
