#ifndef TIMING_UTILS_HPP
#define TIMING_UTILS_HPP

#include <chrono> // execution time measurement
#include <limits> // used for double max value
#include <string>
#include <sstream> // std::stringstream

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::microseconds>(a).count()
#define time_now() std::chrono::high_resolution_clock::now()

using namespace std::chrono;

struct TimeUnits
{
    double min = __DBL_MAX__;
    double max = 0;
    double average = 0;
    int iterations = -1;
};

void update_time_units(TimeUnits &units, double duration_time)
{
    if (duration_time < units.min)
        units.min = duration_time;

    if (duration_time > units.max)
        units.max = duration_time;

    units.average += (duration_time / units.iterations);
}

void print_units(const TimeUnits &units, string message)
{
    cout << message
         << " MIN: " << units.min << " microseconds"
         << " MAX: " << units.max << " microseconds"
         << " AVERAGE: " << units.average << " microseconds"
         << endl;
}

string format_duration(std::chrono::milliseconds ms)
{
    using namespace std::chrono;
    auto secs = duration_cast<seconds>(ms);
    ms -= duration_cast<milliseconds>(secs);
    auto mins = duration_cast<minutes>(secs);
    secs -= duration_cast<seconds>(mins);

    std::stringstream ss;
    if (mins.count() > 0)
        ss << mins.count() << " minutes\t";
    ss << secs.count() << " seconds\t" << ms.count() << " milliseconds\t";
    return ss.str();
}

#endif