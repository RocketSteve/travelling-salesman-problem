cmake_minimum_required(VERSION 3.23)
project(po_projekt)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(po_projekt
        src/tsp.cpp)
