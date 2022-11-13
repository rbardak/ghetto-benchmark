#include <random>

#include "timing.hpp"

inline constexpr double logisticMap(const double x) {
    return 3.56999 * x * (1 - x); // this should produce very chaotic trajectories
}

double logisticMapTest(const long long loops)
{
    // This function loops over the logistic map in a way that is not
    // easily optimizable to test CPU performance.
    // Returns elapsed seconds as double.
    // This is more reliable than the sine test, because it does not rely on the cmath-implementation

    auto distribution = std::uniform_real_distribution<double>(0.01, 0.99);
    auto generator = std::default_random_engine(timing::secondsSinceEpoch());
    auto rand = std::bind(distribution, generator);
    
    // draw a random number based on external parameters to avoid compile-time execution.
    // We use volatile here to ensure that the benchmark is actually compiled
    // into the program and performed.
    volatile double x = rand();

    timing::Measurement timer;
    timer.start();
    for (long long i = 0; i<loops; ++i)
        x = logisticMap(x);
    timer.end();

    return timer.elapsedTime();
}
