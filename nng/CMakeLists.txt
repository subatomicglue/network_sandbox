cmake_minimum_required(VERSION 3.15)
project(test CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(nng REQUIRED)

add_executable(client_nng client.cpp)
target_link_libraries(client_nng nng::nng)

add_executable(server_nng server.cpp)
target_link_libraries(server_nng nng::nng)

add_executable(http_client_nng http_client.cpp)
target_link_libraries(http_client_nng nng::nng)

add_executable(rest_server_nng rest_server.cpp)
target_link_libraries(rest_server_nng nng::nng)
