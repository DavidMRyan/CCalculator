cmake_minimum_required(VERSION 3.25)
project(CCalculator C)

set(CMAKE_C_STANDARD 23)

add_executable(CCalculator main.c cmake-build-debug/main.h src/math.c src/math.h)
