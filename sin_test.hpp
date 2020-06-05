#include <cmath>
#include <random>

#include "timing.hpp"

double sinus_test(const long loops)
{
    // This function loops over the sinus function in a way that is not
    // easily optimizable to test CPU performance.
    // Returns elapsed seconds as double.

    auto distribution = std::uniform_real_distribution<double>(0, M_PI);
    auto generator = std::default_random_engine(timing::seconds_since_epoch());
    auto rand = std::bind(distribution, generator);
    
    // draw a random number based on external parameters to avoid compile-time execution.
    volatile double x = rand();

    timing::Measurement timer;
    timer.start();
    for (long i = 0; i<loops; ++i)
        x = std::sin(3*x);
    timer.end();

    return timer.elapsed_time();
}
