cmake_minimum_required(VERSION 3.6)
project(Stepik_tasks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp 14.cpp 12.cpp 31.cpp 32.cpp 33.cpp 11.cpp 13.cpp 15.cpp 21.cpp 22.cpp 23.cpp 24.cpp 34.cpp 35.cpp 23.cpp)
add_executable(Stepik_tasks ${SOURCE_FILES})