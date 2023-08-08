cmake_minimum_required(VERSION 3.15)
project(test CXX)

find_package(ZeroMQ REQUIRED)

add_executable(tcp_server tcp_server.cpp)
target_link_libraries(tcp_server libzmq-static)

add_executable(tcp_client tcp_client.cpp)
target_link_libraries(tcp_client libzmq-static)
