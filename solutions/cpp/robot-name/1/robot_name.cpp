#include "robot_name.h"
#include <iostream>

namespace robot_name {

    std::unordered_set<std::string> robot::allNames_ = {};

    void robot::makeName()
    {
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> alphaDist((int)'A', (int)'Z');
        std::uniform_int_distribution<int> digitDist((int)'0', (int)'9');

        bool inserted = false;
        do {
            name_.clear();
            name_ += (char)alphaDist(gen);
            name_ += (char)alphaDist(gen);
            name_ += (char)digitDist(gen);
            name_ += (char)digitDist(gen);
            name_ += (char)digitDist(gen);
    
            auto res = allNames_.insert(name_);
            inserted = res.second;
        } while (!inserted);
    }
}  // namespace robot_name
