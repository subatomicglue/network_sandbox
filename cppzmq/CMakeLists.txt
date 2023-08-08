cmake_minimum_required(VERSION 3.15)
project(test CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(cppzmq REQUIRED)

add_executable(tcp_server_cppzmq tcp_server.cpp)
target_link_libraries(tcp_server_cppzmq cppzmq)

add_executable(tcp_client_cppzmq tcp_client.cpp)
target_link_libraries(tcp_client_cppzmq cppzmq)
