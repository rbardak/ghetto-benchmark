#include <iostream>
#include <iomanip>
#include <functional>

#include "matrix_test.hpp"
#include "sin_test.hpp"
#include "util.hpp"

int main()
{
    std::cout << "Performing sine wave benchmark. Pure CPU performance.\n";
    printSeconds(sinusTest(100000000));
    std::cout << "Performing least squares benchmark. Mostly RAM performance.\n";
    printSeconds(MatrixBenchmarks::leastSquaresPolynomial<100>(500000));

    return 0;
}
