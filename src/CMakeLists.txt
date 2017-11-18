cmake_minimum_required(VERSION 3.2.2)
project(tstring)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES tstring/tstring.cpp)
add_library(tstring STATIC ${SOURCE_FILES})
#add_executable(tstring ${SOURCE_FILES})

