#include <iostream>
#include <iomanip>
#include <functional>

#include "matrix_test.hpp"
#include "memcpy_test.hpp"
#include "sin_test.hpp"
#include "util.hpp"

int main()
{
    std::cout << "Sine wave benchmark. Single core CPU performance test.\n";
    printSeconds(sinusTest(100000000));

    std::cout << "Least squares benchmark. Mostly RAM performance & timings.\n";
    printSeconds(MatrixBenchmarks::leastSquaresPolynomial<100>(500000));

    std::cout << "Memcpy test. Sequential RAM writing speed." << std::endl;
    size_t memSize = 512l * 1000l * 1000l;
    size_t memPasses = 100;
    double memcpySeconds = memcpy_test(memSize, memPasses);
    printSeconds(memcpySeconds);
    double GBPerSecond = static_cast<double>(memSize * memPasses) / memcpySeconds / 1000000000;
    std::cout << std::setprecision(4) << "Copied " << GBPerSecond << " GB/s.\n";
    return 0;
}
