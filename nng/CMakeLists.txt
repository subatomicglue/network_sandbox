cmake_minimum_required(VERSION 3.15)
project(test CXX)

find_package(nng REQUIRED)

add_executable(test_nng main.cpp)
# Using the global target name
target_link_libraries(test_nng nng::nng)
