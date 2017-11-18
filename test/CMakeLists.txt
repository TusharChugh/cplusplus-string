cmake_minimum_required(VERSION 3.2.2)
project(tstring_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

set(SOURCE_FILES unit_tests.cpp tstring/create_string.cpp tstring/copy_swap.cpp tstring/comparion_operators.cpp tstring/utlilities_string.cpp)

add_executable(unittest_string ${SOURCE_FILES})
target_link_libraries(unittest_string ${GTEST_LIBRARIES} tstring pthread)