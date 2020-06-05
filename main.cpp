#include <iostream>
#include <iomanip>
#include <functional>

#include "sin_test.hpp"

int main()
{
    std::cout << std::setprecision(3)
              << sinus_test(100000000)
              << " seconds have elapsed."
              << std::endl;
    return 0;
}
