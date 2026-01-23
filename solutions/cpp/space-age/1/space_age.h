#pragma once

namespace space_age {

class space_age {
public:
    space_age(const unsigned long sec)
        : seconds_{ sec }
    {}

    unsigned long seconds() const {
        return seconds_;
    }

    double on_earth() const;
    double on_mercury() const;
    double on_venus() const;
    double on_mars() const;
    double on_jupiter() const;
    double on_saturn() const;
    double on_uranus() const;
    double on_neptune() const;

private:
    unsigned long seconds_;
};

}  // namespace space_age
