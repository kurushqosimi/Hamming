cmake_minimum_required(VERSION 3.28)

project(Hamming)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

add_library(evenbit evenbit.cpp)
add_library(hamming hamming.cpp)

add_executable(Hamming main.cpp)

target_link_libraries(Hamming PRIVATE evenbit hamming)