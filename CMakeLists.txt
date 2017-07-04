cmake_minimum_required(VERSION 3.7)
project(EBFI)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Interpreter.cpp src/Interpreter.hpp)
add_executable(ebfi ${SOURCE_FILES})
