#include "space_age.h"

const unsigned long earth_year{ 31557600 };

namespace space_age {

double space_age::on_earth() const {
    return 1.0 * seconds_ / earth_year;
}
double space_age::on_mercury() const {
    return seconds_ / 0.2408467 / earth_year;
}
double space_age::on_venus() const {
    return seconds_ / 0.61519726 / earth_year;
}
double space_age::on_mars() const {
    return seconds_ / 1.8808158 / earth_year;
}
double space_age::on_jupiter() const {
    return seconds_ / 11.862615 / earth_year;
}
double space_age::on_saturn() const {
    return seconds_ / 29.447498 / earth_year;
}
double space_age::on_uranus() const {
    return seconds_ / 84.016846 / earth_year;
}
double space_age::on_neptune() const {
    return seconds_ / 164.79132 / earth_year;
}

}  // namespace space_age
