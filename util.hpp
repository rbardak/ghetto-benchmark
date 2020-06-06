#include <iostream>
#include <iomanip>

void printSeconds(double seconds)
{
    std::cout << std::setprecision(3)
              << seconds
              << " seconds have elapsed."
              << std::endl;
}