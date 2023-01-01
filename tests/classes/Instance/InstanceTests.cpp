#include "../../../src/classes/GreedySolver/GreedySolver.h"
#include "../../../src/classes/InstanceFileReader/InstanceFileReader.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>

TEST_CASE("addVertex", "[Instance]") {
    auto instance = new Instance();
    instance->addVertex(CoordinateWithVisitedState(0, 0));
    instance->addVertex(CoordinateWithVisitedState(1, 2));
    instance->addVertex(CoordinateWithVisitedState(3, 4));
    REQUIRE(instance->graph->getSize() == 3);
    REQUIRE(instance->graph->getVertex(2)->getValue() == CoordinateWithVisitedState(3, 4));
}

bool checkConnectionWithThree(AdjacencyList<CoordinateWithVisitedState> vertex0,
                              AdjacencyList<CoordinateWithVisitedState> vertex1,
                              AdjacencyList<CoordinateWithVisitedState> vertex2) {
    auto firstId = vertex0.getAdjacency(0);
    bool valid = false;
    if (firstId->getId() == vertex1.getId()) { valid = true; }
    if (firstId->getId() == vertex2.getId()) { valid = true; }
    return valid;
}

TEST_CASE("connectAllPoints", "[Instance]") {
    auto instance = new Instance();
    instance->addVertex(CoordinateWithVisitedState(0, 0));
    instance->addVertex(CoordinateWithVisitedState(1, 2));
    instance->addVertex(CoordinateWithVisitedState(3, 4));
    instance->connectAllPoints();
    auto vertex0 = instance->graph->getVertex(0);
    auto vertex1 = instance->graph->getVertex(1);
    auto vertex2 = instance->graph->getVertex(2);
    REQUIRE(vertex0->getSize() == 2);
    REQUIRE(vertex1->getSize() == 2);
    REQUIRE(vertex2->getSize() == 2);
    REQUIRE(checkConnectionWithThree(*vertex0, *vertex1, *vertex2));
    REQUIRE(checkConnectionWithThree(*vertex1, *vertex0, *vertex2));
    REQUIRE(checkConnectionWithThree(*vertex2, *vertex1, *vertex0));
}

TEST_CASE("writeToFile", "[Instance]") {
    auto instance = new Instance();
    instance->addVertex(CoordinateWithVisitedState(0, 0));
    instance->addVertex(CoordinateWithVisitedState(1, 2));
    instance->addVertex(CoordinateWithVisitedState(3, 4));
    instance->connectAllPoints();
    string filename = "resources/test.txt";
    instance->writeToFile(filename);
    auto instanceFromFIle = new InstanceFileReader(filename);
    REQUIRE(instance->graph->getVertex(0)->getValue() == instanceFromFIle->graph->getVertex(0)->getValue());
    REQUIRE(instance->graph->getVertex(1)->getValue() == instanceFromFIle->graph->getVertex(1)->getValue());
    REQUIRE(instance->graph->getVertex(2)->getValue() == instanceFromFIle->graph->getVertex(2)->getValue());
}