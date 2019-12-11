cmake_minimum_required(VERSION 3.15)
project(lab3)

set(CMAKE_CXX_STANDARD 14)

#add_library(windows.h)
include_directories(${WINDOWS_INCLUDE_DIRS})
#target_link_libraries(lab3 ${WINDOWS_LIBRARIES})
add_executable(lab3 main.cpp)