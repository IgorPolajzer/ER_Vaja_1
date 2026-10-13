cmake_minimum_required(VERSION 4.2)
project(ER_Vaja_1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library setup.
add_library(er_core
        src/misc/Bound.cpp
        src/problems/Problem.cpp
        src/problems/Ackley.cpp
        src/problems/Griewank.cpp
        src/problems/Levy.cpp
        src/problems/Michalewicz.cpp
        src/problems/Rastrigin.cpp
        src/problems/Rosenbrock.cpp
        src/problems/Schwefel26.cpp
        src/problems/Sphere.cpp
        src/problems/StyblinskiTang.cpp
        src/problems/Trid.cpp
        src/problems/Bukin.cpp
        src/problems/CarromTable.cpp
)
target_include_directories(er_core PUBLIC src)

# Main exe.
add_executable(ER_Vaja_1 main.cpp)
target_link_libraries(ER_Vaja_1 PRIVATE er_core)

# Test setup.
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(ProblemTest tests/ProblemTests.cpp)
target_link_libraries(ProblemTest PRIVATE er_core GTest::gtest_main) # Adds a main which runs all registerd tests.

include(GoogleTest)
gtest_discover_tests(ProblemTest)
