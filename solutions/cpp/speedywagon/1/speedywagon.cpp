#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

// Task 1
bool connection_check(pillar_men_sensor* sensor) {
    return sensor != nullptr;
}

// Task 2
int activity_counter(pillar_men_sensor* sensors, int n) {
    int total{};
    for (auto i = 0; i < n; ++i) {
        total += sensors[i].activity;
    }
    return total;
}

// Task 3
bool alarm_control(pillar_men_sensor* sensor) {
    if (sensor) {
        return sensor->activity > 0;
    }
    return false;
}

// Task 4
bool uv_alarm(pillar_men_sensor* sensor) {
    if (sensor) {
        auto threshold = uv_light_heuristic(&(sensor->data));
        return threshold > sensor->activity;
    }
    return false;
}
}  // namespace speedywagon
