#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include "../../../src/classes/InstanceFileReader/InstanceFileReader.h"
#include "../../../src/classes/InstanceFileReader/InstanceFileReader.cpp"

TEST_CASE("constructor", "[InstanceFileReaderTests]") {
    auto instance = new InstanceFileReader("resources/test_instance.txt");
    instance->graph->getSize();
    CoordinateWithVisitedState coordinates[4];
    coordinates[0] = CoordinateWithVisitedState(3, 2);
    coordinates[1] = CoordinateWithVisitedState(2, 9);
    coordinates[2] = CoordinateWithVisitedState(7, 5);
    coordinates[3] = CoordinateWithVisitedState(5, 4);
    for (AdjacencyList<CoordinateWithVisitedState> &i: instance->graph->vertices) {
        REQUIRE(i.getSize() == 3);
        REQUIRE(i.getValue() == coordinates[i.getId()]);
    }
}