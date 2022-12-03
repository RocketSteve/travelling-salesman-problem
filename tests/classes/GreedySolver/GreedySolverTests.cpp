#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include "../../../src/classes/GreedySolver/GreedySolver.h"
#include "../../../src/classes/GreedySolver/GreedySolver.cpp"
#include "../../../src/classes/InstanceFileReader/InstanceFileReader.cpp"

TEST_CASE("findFirstVertex", "[GreedySolver]") {
    Instance instance = InstanceFileReader("resources/instance.txt");
    auto greedySolver = new GreedySolver(instance);
    int id = greedySolver->findFirstVertex();
    REQUIRE(id == 0);
}


TEST_CASE("findFirstVertex first id 1", "[GreedySolver]") {
    Instance instance = InstanceFileReader("resources/instance.txt");
    instance.graph->removeVertex(0);
    auto greedySolver = new GreedySolver(instance);
    int id = greedySolver->findFirstVertex();
    REQUIRE(id == 1);
}