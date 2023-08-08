cmake_minimum_required(VERSION 3.15)
project(test CXX)

find_package(asio REQUIRED)

add_executable(test_asio main.cpp)
# Using the global target name
target_link_libraries(test_asio asio::asio)
