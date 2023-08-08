cmake_minimum_required(VERSION 3.15)
project(test CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(asio REQUIRED)
find_package(openssl REQUIRED)

add_executable(multicast_receiver multicast_receiver.cpp)
target_link_libraries(multicast_receiver asio::asio openssl::openssl)

add_executable(multicast_sender multicast_sender.cpp)
target_link_libraries(multicast_sender asio::asio openssl::openssl)

add_executable(async_tcp_echo_server async_tcp_echo_server.cpp)
target_link_libraries(async_tcp_echo_server asio::asio openssl::openssl)

add_executable(blocking_tcp_echo_client blocking_tcp_echo_client.cpp)
target_link_libraries(blocking_tcp_echo_client asio::asio openssl::openssl)

add_executable(blocking_tcp_echo_server blocking_tcp_echo_server.cpp)
target_link_libraries(blocking_tcp_echo_server asio::asio openssl::openssl)



add_executable(blocking_udp_echo_server blocking_udp_echo_server.cpp)
target_link_libraries(blocking_udp_echo_server asio::asio openssl::openssl)

add_executable(blocking_udp_echo_client blocking_udp_echo_client.cpp)
target_link_libraries(blocking_udp_echo_client asio::asio openssl::openssl)

add_executable(async_udp_echo_server async_udp_echo_server.cpp)
target_link_libraries(async_udp_echo_server asio::asio openssl::openssl)
