cmake_minimum_required(VERSION 3.15)
project(test CXX)

find_package(cppzmq REQUIRED)

add_executable(test_cppzmq main.cpp)
# Using the global target name
target_link_libraries(test_cppzmq cppzmq)
