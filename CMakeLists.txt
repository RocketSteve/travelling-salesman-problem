cmake_minimum_required(VERSION 3.23)
project(po_projekt)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(po_projekt
        src/tsp.cpp)

find_package(Catch2 3 REQUIRED)

add_executable(tests tests/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_executable(custom-main-tests tests/test.cpp tests/test-main.cpp)
target_link_libraries(custom-main-tests PRIVATE Catch2::Catch2)