#include "power_of_troy.h"

namespace troy {

void give_new_artifact(human& h, const std::string& name) {
    h.possession = std::make_unique<artifact>(name);
}

void exchange_artifacts(std::unique_ptr<artifact>& l, std::unique_ptr<artifact>& r) {
    if (!l && !r) return;
    if (l && r) {
        auto name = l->name;
        l->name = r->name;
        r->name = name;        
    } else if (!l) {
        l = std::move(r);
    } else {
        r = std::move(l);
    }
}

void manifest_power(human& h, const std::string& effect) {
    h.own_power = std::make_shared<power>(effect);
}

void use_power(human& caster, human& target) {
    target.influenced_by = caster.own_power;
}

int power_intensity(human& h) {
    return h.own_power.use_count();
}
}  // namespace troy
