cmake_minimum_required(VERSION 3.2.2)
project(tstring)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
add_subdirectory(src)
target_link_libraries(tstring)

add_subdirectory(test)