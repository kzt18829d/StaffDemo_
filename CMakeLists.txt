cmake_minimum_required(VERSION 3.30)
project(StaffDemo_refactor)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(execute)
add_subdirectory(source)
add_subdirectory(google-tests)

# add_executable(StaffDemo_refactor execute/main.cpp)
