#pragma once

#include <string>
#include <unordered_set>
#include <random>

namespace robot_name {

class robot
{
public:
    robot() { makeName(); }

    void reset()
    {
        makeName();
    }

    const std::string& name() const { return name_; }

private:
    static std::unordered_set<std::string> allNames_;
    std::string name_{};
    std::random_device rd{};

    void makeName();
};

}  // namespace robot_name
