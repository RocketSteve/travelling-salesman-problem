cmake_minimum_required(VERSION 3.23)
project(travelling-salesman-problem )

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB_RECURSE classes src/classes/*.h src/classes/*.cpp)

add_executable(main src/main.cpp)

find_package(Catch2 3 REQUIRED)

enable_testing()

function(add_test_and_executable src name)
    add_executable(${name} ${src})
    target_link_libraries(${name} PRIVATE Catch2::Catch2WithMain)
    add_test(NAME ${name} COMMAND ${name})
endfunction()

include(CTest)
include(Catch)

add_test_and_executable(tests/classes/Coordinate/CoordinateTest.cpp coordinate-tests)
add_test_and_executable(tests/classes/GraphAdjacencyLists/AdjacencyList/AdjacencyListTests.cpp adjacency-list-tests)
add_test_and_executable(tests/classes/GraphAdjacencyLists/GraphAdjacencyListsTests.cpp graph-adjacency-lists-tests)