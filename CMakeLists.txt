cmake_minimum_required(VERSION 3.15)
project(test CXX)

find_package(cppzmq REQUIRED)
find_package(nng REQUIRED)

add_executable(ad main.cpp)
# Using the global target name
target_link_libraries(ad cppzmq nng::nng)
