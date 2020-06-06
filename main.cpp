#include <iostream>
#include <iomanip>
#include <functional>

#include "sin_test.hpp"
#include "util.hpp"

int main()
{
    std::cout << "Performing sine wave benchmark...\n";
    printSeconds(sinusTest(100000000));
    return 0;
}
