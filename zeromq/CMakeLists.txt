cmake_minimum_required(VERSION 3.15)
project(test CXX)

find_package(ZeroMQ REQUIRED)

add_executable(test_zeromq main.cpp)
# Using the global target name
target_link_libraries(test_zeromq libzmq-static)
