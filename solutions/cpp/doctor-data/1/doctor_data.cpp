#include "doctor_data.h"

namespace heaven {

Vessel::Vessel(const std::string& n, int g, star_map::System s)
    : name{n}, generation{g}, current_system{s}
    {}

Vessel Vessel::replicate(const std::string& n){
    return Vessel{n, generation + 1, current_system};
}

void Vessel::make_buster() {
    busters++;
}

bool Vessel::shoot_buster() {
    if (busters > 0) {
        busters--;
        return true;
    }
    return false;
}

std::string get_older_bob(const Vessel& l, const Vessel& r) {
    if (l.generation < r.generation) {
        return l.name;
    }
    return r.name;
}

bool in_the_same_system(const Vessel& l, const Vessel& r) {
    return l.current_system == r.current_system;
}

}