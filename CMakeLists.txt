cmake_minimum_required(VERSION 3.2.2)
project(tstring)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/.travis/cmake)

include_directories(include)
add_subdirectory(src)
target_link_libraries(tstring)

add_subdirectory(test)
