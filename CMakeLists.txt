cmake_minimum_required(VERSION 3.10)
project(benchmark)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-deprecated-copy -Ofast -march=native -funroll-loops")
include_directories(eigen)

add_executable(main main.cpp)
#target_link_libraries(sin_test timing.hpp)
