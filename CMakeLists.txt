cmake_minimum_required(VERSION 3.23)
project(travelling-salesman-problem )

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB_RECURSE classes src/classes/*.h src/classes/*.cpp)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_BINARY_DIR}/resources DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main src/main.cpp)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)
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
add_test_and_executable(tests/classes/CoordinateWithVisitedState/CoordinateWithVisitedState.cpp coordinate-with-visited-state-tests)
add_test_and_executable(tests/classes/GraphAdjacencyLists/AdjacencyList/AdjacencyListTests.cpp adjacency-list-tests)
add_test_and_executable(tests/classes/GraphAdjacencyLists/GraphAdjacencyListsTests.cpp graph-adjacency-lists-tests)
add_test_and_executable(tests/classes/Instance/InstanceTests.cpp instance-tests)
add_test_and_executable(tests/classes/InstanceFileReader/InstanceFileReaderTests.cpp instance-file-reader-tests)
add_test_and_executable(tests/classes/RandomInstanceGenerator/RandomInstanceGenerator.cpp random-instance-generator-tests)
add_test_and_executable(tests/classes/GreedySolver/GreedySolverTests.cpp greedy-solver-tests)