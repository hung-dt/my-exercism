#pragma once

#include <string>

namespace star_map {

enum class System {
    Sol,
    BetaHydri,
    EpsilonEridani,
    AlphaCentauri,
    DeltaEridani,
    Omicron2Eridani
};

}

namespace heaven {

class Vessel {

public:
    Vessel(const std::string&, int, star_map::System = star_map::System::Sol);

    Vessel replicate(const std::string&);

    void make_buster();
    bool shoot_buster();

    std::string name;
    int generation{};
    star_map::System current_system;
    int busters{};
};

std::string get_older_bob(const Vessel&, const Vessel&);

bool in_the_same_system(const Vessel&, const Vessel&);
}
