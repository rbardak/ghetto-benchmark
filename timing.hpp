#pragma once
#include <ctime>
#include <chrono>
#include <iostream>

namespace timing {

long seconds_since_epoch()
{
    return std::time(nullptr);
}

class Measurement {
public:
    void start()
    { start_time = clock.now(); }
    void end()
    { end_time = clock.now(); }

    double elapsed_time()
    {
        if (end_time > start_time)
        {
            auto difference = end_time - start_time;
            auto seconds = std::chrono::duration_cast<duration_type>(difference);
            return seconds.count();
        }
        else
        {
            std::cout << "[ERROR] Time measurement start occured after end."
            << std::endl;
            return 0;
        }
    }

public:
    using clock_type = std::chrono::steady_clock;
    using time_type = std::chrono::time_point<clock_type>;
    using duration_type = std::chrono::duration<double>;

private:
    time_type start_time;
    time_type end_time;
    clock_type clock;
};

}