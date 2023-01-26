#include "../../../src/classes/GreedySolver/GreedySolver.h"
#include "../../../src/classes/InstanceFileReader/InstanceFileReader.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

using Catch::Matchers::WithinRel;
using std::vector;

TEST_CASE("findFirstVertex", "[GreedySolver]") {
    Instance instance = InstanceFileReader("resources/instance.txt");
    auto greedySolver = new GreedySolver(instance);
    auto vertex = greedySolver->findFirstVertex();
    REQUIRE(vertex->getId() == 0);
}


TEST_CASE("findFirstVertex first id 1", "[GreedySolver]") {
    Instance instance = InstanceFileReader("resources/instance.txt");
    instance.graph->removeVertex(0);
    auto greedySolver = new GreedySolver(instance);
    auto vertex = greedySolver->findFirstVertex();
    REQUIRE(vertex->getId() == 1);
}

TEST_CASE("nextVertex", "[GreedySolver]") {
    Instance instance = InstanceFileReader("resources/instance.txt");
    auto greedySolver = new GreedySolver(instance);
    auto first = greedySolver->findFirstVertex();
    first->getValue().visitCoordinate();
    auto next = GreedySolver::nextVertex(first).first;
    REQUIRE(next->getId() == 27);
}

TEST_CASE("addVertexToAnswer", "[GreedySolver]") {
    Instance instance = InstanceFileReader("resources/instance.txt");
    auto greedySolver = new GreedySolver(instance);
    auto first = greedySolver->findFirstVertex();
    greedySolver->addVertexToAnswer(first);
    REQUIRE(greedySolver->answer[0] == first);
    REQUIRE(first->getValue().getVisited());
}

TEST_CASE("solve", "[GreedySolver]") {
    Instance instance = InstanceFileReader("resources/instance.txt");
    auto greedySolver = new GreedySolver(instance);
    greedySolver->solve();
    vector<int> validAnswer = {0,  27, 5,  11, 8, 4,  20, 1, 19, 9,  3,  14, 17, 13, 21,
                               16, 10, 18, 24, 6, 22, 26, 7, 23, 15, 12, 28, 25, 2,  0};
    vector<int> answerFromGreedy = {};
    for (auto i: greedySolver->answer) { answerFromGreedy.push_back(i->getId()); }
    REQUIRE(answerFromGreedy == validAnswer);
    REQUIRE_THAT(greedySolver->getDistance(), WithinRel(10211.18, 0.1));
}
