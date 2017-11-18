cmake_minimum_required(VERSION 3.2.2)
project(tstring_test)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

file(GLOB TEST_FILES ${PROJECT_SOURCE_DIR}/test/tstring/*.cpp)

add_executable(unittest_string  unit_tests.cpp ${TEST_FILES})
target_link_libraries(unittest_string ${GTEST_LIBRARIES} tstring pthread)

include(CodeCoverage)
setup_target_for_coverage(tstring_coverage unittest_string coverage)


