cmake_minimum_required(VERSION 3.15)
project(test CXX)

find_package(ZeroMQ REQUIRED)

add_executable(tcp_server_zeromq tcp_server.cpp)
target_link_libraries(tcp_server_zeromq libzmq-static)

add_executable(tcp_client_zeromq tcp_client.cpp)
target_link_libraries(tcp_client_zeromq libzmq-static)
