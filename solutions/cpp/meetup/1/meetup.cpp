#include "meetup.h"

static bg::date teenthdate(const bg::greg_year y, const bg::greg_month m, const bg::greg_weekday d)
{
    // first d of the month
    auto fd = bg::first_day_of_the_week_in_month( d, m ).get_date(y);
    if (fd.day() < 6) {
        return fd + bg::date_duration(14);
    }
    if (fd.day() < 13) {
        return fd + bg::date_duration(7);
    }
    return fd;
}

namespace meetup {

scheduler::scheduler(const bg::greg_month month, const bg::greg_year year)
: month_{month}, year_{year}
{}

// return the teenth Monday of the month
bg::date scheduler::monteenth() const
{
    return teenthdate(year_, month_, bg::Monday);
}

bg::date scheduler::tuesteenth() const
{
    return teenthdate(year_, month_, bg::Tuesday);
}

bg::date scheduler::wednesteenth() const
{
    return teenthdate(year_, month_, bg::Wednesday);
}

bg::date scheduler::thursteenth() const
{
    return teenthdate(year_, month_, bg::Thursday);
}

bg::date scheduler::friteenth() const
{
    return teenthdate(year_, month_, bg::Friday);
}
bg::date scheduler::saturteenth() const
{
    return teenthdate(year_, month_, bg::Saturday);
}

bg::date scheduler::sunteenth() const
{
    return teenthdate(year_, month_, bg::Sunday);
}

bg::date scheduler::first_monday() const
{
    return bg::first_day_of_the_week_in_month(bg::Monday, month_).get_date(year_);
}

bg::date scheduler::first_tuesday() const
{
    return bg::first_day_of_the_week_in_month(bg::Tuesday, month_).get_date(year_);
}

bg::date scheduler::first_wednesday() const
{
    return bg::first_day_of_the_week_in_month(bg::Wednesday, month_).get_date(year_);
}

bg::date scheduler::first_thursday() const
{
    return bg::first_day_of_the_week_in_month(bg::Thursday, month_).get_date(year_);
}

bg::date scheduler::first_friday() const
{
    return bg::first_day_of_the_week_in_month(bg::Friday, month_).get_date(year_);
}

bg::date scheduler::first_saturday() const
{
    return bg::first_day_of_the_week_in_month(bg::Saturday, month_).get_date(year_);
}

bg::date scheduler::first_sunday() const
{
    return bg::first_day_of_the_week_in_month(bg::Sunday, month_).get_date(year_);
}

bg::date scheduler::second_monday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::second,
        bg::Monday,
        month_).get_date(year_);
}

bg::date scheduler::second_tuesday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::second,
        bg::Tuesday,
        month_).get_date(year_);
}

bg::date scheduler::second_wednesday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::second,
        bg::Wednesday,
        month_).get_date(year_);
}

bg::date scheduler::second_thursday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::second,
        bg::Thursday,
        month_).get_date(year_);
}

bg::date scheduler::second_friday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::second,
        bg::Friday,
        month_).get_date(year_);
}

bg::date scheduler::second_saturday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::second,
        bg::Saturday,
        month_).get_date(year_);
}

bg::date scheduler::second_sunday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::second,
        bg::Sunday,
        month_).get_date(year_);
}

bg::date scheduler::third_monday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::third,
        bg::Monday,
        month_).get_date(year_);
}

bg::date scheduler::third_tuesday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::third,
        bg::Tuesday,
        month_).get_date(year_);
}

bg::date scheduler::third_wednesday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::third,
        bg::Wednesday,
        month_).get_date(year_);
}

bg::date scheduler::third_thursday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::third,
        bg::Thursday,
        month_).get_date(year_);
}

bg::date scheduler::third_friday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::third,
        bg::Friday,
        month_).get_date(year_);
}

bg::date scheduler::third_saturday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::third,
        bg::Saturday,
        month_).get_date(year_);
}

bg::date scheduler::third_sunday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::third,
        bg::Sunday,
        month_).get_date(year_);
}

bg::date scheduler::fourth_monday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::fourth,
        bg::Monday,
        month_).get_date(year_);
}
bg::date scheduler::fourth_tuesday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::fourth,
        bg::Tuesday,
        month_).get_date(year_);
}
bg::date scheduler::fourth_wednesday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::fourth,
        bg::Wednesday,
        month_).get_date(year_);
}
bg::date scheduler::fourth_thursday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::fourth,
        bg::Thursday,
        month_).get_date(year_);
}
bg::date scheduler::fourth_friday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::fourth,
        bg::Friday,
        month_).get_date(year_);
}
bg::date scheduler::fourth_saturday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::fourth,
        bg::Saturday,
        month_).get_date(year_);
}
bg::date scheduler::fourth_sunday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::fourth,
        bg::Sunday,
        month_).get_date(year_);
}

bg::date scheduler::last_monday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::fifth,
        bg::Monday,
        month_).get_date(year_);
}
bg::date scheduler::last_tuesday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::fifth,
        bg::Tuesday,
        month_).get_date(year_);
}
bg::date scheduler::last_wednesday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::fifth,
        bg::Wednesday,
        month_).get_date(year_);
}
bg::date scheduler::last_thursday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::fifth,
        bg::Thursday,
        month_).get_date(year_);
}
bg::date scheduler::last_friday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::fifth,
        bg::Friday,
        month_).get_date(year_);
}
bg::date scheduler::last_saturday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::fifth,
        bg::Saturday,
        month_).get_date(year_);
}
bg::date scheduler::last_sunday() const
{
    return bg::nth_day_of_the_week_in_month(
        bg::nth_day_of_the_week_in_month::fifth,
        bg::Sunday,
        month_).get_date(year_);
}

}  // namespace meetup
