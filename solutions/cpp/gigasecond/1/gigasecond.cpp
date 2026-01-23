#include "gigasecond.h"

const auto GS = 1'000'000'000;

time_duration gigasecond_to_time_duration() {
    const auto h = GS / 3600;
    const auto m = (GS % 3600) / 60;
    const auto s = GS % 60;
    return time_duration{h, m, s, 0};
    
}
namespace gigasecond {

ptime advance(const ptime& t) {
    return t + gigasecond_to_time_duration();
}

}  // namespace gigasecond
