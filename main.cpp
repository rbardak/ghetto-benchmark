#include <iostream>
#include <iomanip>

#include "matrix_test.hpp"
#include "memcpy_test.hpp"
#include "sin_test.hpp"
#include "util.hpp"

void doMemcpyTestAndReport(size_t memSize, size_t memPasses);

int main()
{
    std::cout << "Sine wave benchmark. This tests maximum performance for single core CPU calculations.\n";
    std::cout << "evaluating sine function 500,000,000 times.\n";
    //printSeconds(sinusTest(500'000'000));
    std::cout << std::endl;

    std::cout << "Least squares matrix benchmark. Testing random access timing speed of RAM.\n";
    std::cout << "This is a general purpose performance test that focuses on memory access delays for calculations that are too large for L1-3 Cache.\n";
    std::cout << "QR solving a matrix with 60,000 polynomial expansions of order 1800.\n";
    printSeconds(MatrixBenchmarks::leastSquaresPolynomial<1800>(60000));
    std::cout << std::endl;
    
    
    std::cout << "Memcpy test. Sequential RAM writing speed. Testing maximum data throughput on RAM for small, medium and large sized arrays." << std::endl;
    doMemcpyTestAndReport(1000l * 1000l, 32*64*64);
    doMemcpyTestAndReport(512l * 1000l * 1000l, 4*64);
    doMemcpyTestAndReport(4096l * 1000l * 1000l, 32);

   return 0;
}

void doMemcpyTestAndReport(size_t memSize, size_t memPasses) {
    std::cout << "Copying " << memSize / (1000l * 1000l) << "MB in RAM " << memPasses << "x times." << std::endl;
    double memcpySeconds = memcpy_test(memSize, memPasses);

    printSeconds(memcpySeconds);
    double GBPerSecond = static_cast<double>(memSize * memPasses) / memcpySeconds / (1000l * 1000l*  1000l);
    std::cout << std::setprecision(4) << "Measured " << GBPerSecond << " GB/s on RAM\n";
    std::cout << std::endl;
}
