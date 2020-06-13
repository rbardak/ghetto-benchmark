#pragma once
#include <ctime>
#include <chrono>
#include <iostream>

namespace timing {

long long secondsSinceEpoch()
{
    return std::time(nullptr);
}

class Measurement {
public:
    void start()
    { startTime = clock.now(); }
    void end()
    { endTime = clock.now(); }

    double elapsedTime()
    {
        if (endTime > startTime)
        {
            auto difference = endTime - startTime;
            auto seconds = std::chrono::duration_cast<Duration>(difference);
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
    using Clock = std::chrono::steady_clock;
    using Time = std::chrono::time_point<Clock>;
    using Duration = std::chrono::duration<double>;

private:
    Time startTime;
    Time endTime;
    Clock clock;
};

}