#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>

namespace bg = boost::gregorian;

namespace meetup {

class scheduler {
public:
    scheduler(const bg::greg_month, const bg::greg_year);

    bg::date monteenth() const;
    bg::date tuesteenth() const;
    bg::date wednesteenth() const;
    bg::date thursteenth() const;
    bg::date friteenth() const;
    bg::date saturteenth() const;
    bg::date sunteenth() const;

    bg::date first_monday() const;
    bg::date first_tuesday() const;
    bg::date first_wednesday() const;
    bg::date first_thursday() const;
    bg::date first_friday() const;
    bg::date first_saturday() const;
    bg::date first_sunday() const;

    bg::date second_monday() const;
    bg::date second_tuesday() const;
    bg::date second_wednesday() const;
    bg::date second_thursday() const;
    bg::date second_friday() const;
    bg::date second_saturday() const;
    bg::date second_sunday() const;

    bg::date third_monday() const;
    bg::date third_tuesday() const;
    bg::date third_wednesday() const;
    bg::date third_thursday() const;
    bg::date third_friday() const;
    bg::date third_saturday() const;
    bg::date third_sunday() const;

    bg::date fourth_monday() const;
    bg::date fourth_tuesday() const;
    bg::date fourth_wednesday() const;
    bg::date fourth_thursday() const;
    bg::date fourth_friday() const;
    bg::date fourth_saturday() const;
    bg::date fourth_sunday() const;

    bg::date last_monday() const;
    bg::date last_tuesday() const;
    bg::date last_wednesday() const;
    bg::date last_thursday() const;
    bg::date last_friday() const;
    bg::date last_saturday() const;
    bg::date last_sunday() const;

private:
    bg::greg_month month_;
    bg::greg_year year_;
};

}  // namespace meetup
