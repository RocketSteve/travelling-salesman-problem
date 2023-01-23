cmake_minimum_required(VERSION 3.23)
project(travelling-salesman-problem)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(include)

file(GLOB_RECURSE classes src/classes/*.cpp)
file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_BINARY_DIR}/resources DESTINATION ..)

add_executable(main src/main.cpp ${classes})


Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.0.1
)

FetchContent_MakeAvailable(Catch2)


find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(BOOST_ALL_DYN_LINK ON)

find_path(WEBSOCKETPP_INCLUDE_DIR lib/websocketpp/)
target_link_libraries(main PUBLIC websocketpp)

enable_testing()

function(add_test_and_executable src name)
    add_executable(${name} ${src} ${classes})
    target_link_libraries(${name} PRIVATE Catch2::Catch2WithMain)
    target_include_directories(${name} PRIVATE ..)
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
add_test_and_executable(tests/classes/RandomInstanceGenerator/RandomInstanceGeneratorTests.cpp random-instance-generator-tests)
add_test_and_executable(tests/classes/GreedySolver/GreedySolverTests.cpp greedy-solver-tests)
add_test_and_executable(tests/classes/SimulatedAnnealingSolver/SimulatedAnnealingSolverTests.cpp simulated-annealing-solver-tests)
add_test_and_executable(tests/classes/RandomNumberGenerator/RandomNumberGeneratorTests.cpp random-number-generator-tests)

add_executable(benchmark-tests tests/BenchmarkTests.cpp ${classes})
target_link_libraries(benchmark-tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(benchmark-tests PRIVATE ..)