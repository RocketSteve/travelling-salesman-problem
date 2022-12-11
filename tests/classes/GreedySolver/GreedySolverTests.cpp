#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "../../../src/classes/GreedySolver/GreedySolver.h"
#include "../../../src/classes/GreedySolver/GreedySolver.cpp"
#include "../../../src/classes/InstanceFileReader/InstanceFileReader.cpp"

using namespace Catch::Matchers;

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

TEST_CASE("nextVertex", "[GreedySolver]") {
    Instance instance = InstanceFileReader("resources/instance.txt");
    auto greedySolver = new GreedySolver(instance);
    int firstId = greedySolver->findFirstVertex();
    instance.graph->getVertex(firstId)->getValue().visitCoordinate();
    int id = greedySolver->nextVertex(firstId).first;
    REQUIRE(id == 27);
}

TEST_CASE("addVertexToAnswer", "[GreedySolver]") {
    Instance instance = InstanceFileReader("resources/instance.txt");
    auto greedySolver = new GreedySolver(instance);
    int firstId = greedySolver->findFirstVertex();
    greedySolver->addVertexToAnswer(firstId);
    REQUIRE(greedySolver->answer[0] == firstId);
    REQUIRE(instance.graph->getVertex(firstId)->getValue().getVisited());
}

TEST_CASE("solve", "[GreedySolver]") {
    Instance instance = InstanceFileReader("resources/instance.txt");
    auto greedySolver = new GreedySolver(instance);
    greedySolver->solve();
    vector<int> answer = {0, 27, 5, 11, 8, 4, 20, 1, 19, 9, 3, 14, 17, 13, 21, 16, 10, 18, 24, 6, 22, 26, 7, 23, 15, 12,
                          28, 25, 2, 0};
    REQUIRE(greedySolver->answer == answer);
    REQUIRE_THAT(greedySolver->getDistance(), WithinRel(10211.18, 0.1));
}