cmake_minimum_required(VERSION 3.15)
project(boringssl CXX)




add_library(boringssl src/boringssl.cpp)
target_include_directories(boringssl PUBLIC include)



set_target_properties(boringssl PROPERTIES PUBLIC_HEADER "include/boringssl.h")
install(TARGETS boringssl)
