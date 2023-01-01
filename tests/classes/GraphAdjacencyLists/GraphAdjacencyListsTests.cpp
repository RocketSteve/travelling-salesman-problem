#include "../../../src/classes/GreedySolver/GreedySolver.h"
#include <catch2/catch_test_macros.hpp>


GraphAdjacencyLists<int> *initialGraph();

TEST_CASE("constructor", "[GraphAdjacencyLists]") { GraphAdjacencyLists<int>(); }

TEST_CASE("addVertex", "[GraphAdjacencyLists]") {
    auto graph = initialGraph();
    AdjacencyList<int> *list = graph->getVertex(0);
    REQUIRE(list->getId() == 0);
}

TEST_CASE("getVertex", "[GraphAdjacencyLists]") {
    auto graph = initialGraph();
    AdjacencyList<int> *list = graph->getVertex(0);
    REQUIRE(list->getId() == 0);
}

TEST_CASE("getVertexByIndex", "[GraphAdjacencyLists]") {
    auto graph = initialGraph();
    graph->removeVertex(0);
    auto list = graph->getVertexByIndex(0);
    REQUIRE(list->getValue() == 2);
}

TEST_CASE("removeVertex", "[GraphAdjacencyLists]") {
    auto graph = initialGraph();
    graph->removeVertex(1);
    auto vertex = graph->getVertex(0);
    REQUIRE(vertex->getId() == 0);
    REQUIRE(graph->getSize() == 1);
}

TEST_CASE("addAdjacencyToVertex", "[GraphAdjacencyLists]") {
    auto graph = initialGraph();
    graph->addAdjacencyToVertex(0, 1);
    auto vertex = graph->getVertex(1);
    REQUIRE(graph->getVertex(0)->getAdjacency(0) == vertex);
}

TEST_CASE("addAdjacencyToVertex not valid", "[GraphAdjacencyLists]") {
    auto graph = new GraphAdjacencyLists<int>();
    graph->addVertex(0);
    graph->addAdjacencyToVertex(0, 1);
    graph->getVertex(0)->getAdjacency(0);
    REQUIRE(graph->getVertex(0)->getAdjacency(0) == nullptr);
    graph->addAdjacencyToVertex(1, 0);
}

TEST_CASE("removeAdjacencyFromVertex", "[GraphAdjacencyLists]") {
    auto graph = initialGraph();
    graph->addAdjacencyToVertex(0, 1);
    graph->removeAdjacencyFromVertex(0, 1);
    graph->getVertex(0)->getAdjacency(0);
    REQUIRE(graph->getVertex(0)->getAdjacency(0) == nullptr);
}

TEST_CASE("removeAdjacencyFromVertex not valid", "[GraphAdjacencyLists]") {
    auto graph = new GraphAdjacencyLists<int>();
    graph->removeAdjacencyFromVertex(0, 1);
}


TEST_CASE("getSize", "[GraphAdjacencyLists]") {
    auto graph = initialGraph();
    REQUIRE(graph->getSize() == 2);
}

TEST_CASE("getIdByValue", "[GraphAdjacencyLists]") {
    auto graph = new GraphAdjacencyLists<int>();
    graph->addVertex(2);
    REQUIRE(graph->getIdByValue(2) == 0);
}

GraphAdjacencyLists<int> *initialGraph() {
    auto graph = new GraphAdjacencyLists<int>();
    graph->addVertex(1);
    graph->addVertex(2);
    return graph;
}
