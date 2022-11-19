cmake_minimum_required(VERSION 3.23)
project(travelling-salesman-problem )

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB classes src/classes/*.h src/classes/*.cpp)

add_executable(main
        src/main.cpp
        ${classes}
        )

find_package(Catch2 3 REQUIRED)

add_executable(tests tests/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_executable(coordinate-tests tests/test.cpp tests/classes/CoordinateTest.cpp)
target_link_libraries(coordinate-tests PRIVATE Catch2::Catch2WithMain)