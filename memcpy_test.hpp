#include <algorithm>
#include <functional>
#include <random>
#include <vector>

#include "timing.hpp"

double memcpy_test(size_t size, size_t passes)
{
    std::vector<char> memoryArray(size, '0');

    auto distribution = std::uniform_int_distribution<char>(0, 255);
    auto generator = std::default_random_engine(timing::secondsSinceEpoch());
    auto randomChar = std::bind(distribution, generator);

    timing::Measurement timer;
    timer.start();

    for(size_t i = 0; i < passes; ++i)
        std::fill(memoryArray.begin(), memoryArray.end(), randomChar());
    
    timer.end();
    return timer.elapsedTime();
}