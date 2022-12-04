#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include "../../../src/classes/GraphAdjacencyLists/GraphAdjacencyLists.h"
#include "../../../src/classes/GraphAdjacencyLists/GraphAdjacencyLists.cpp"
#include "../../../src/classes/GraphAdjacencyLists/AdjacencyList/AdjacencyList.cpp"

TEST_CASE("constructor", "[GraphAdjacencyLists]") {
    GraphAdjacencyLists<int>();
}

TEST_CASE("addVertex", "[GraphAdjacencyLists]") {
    auto graph = new GraphAdjacencyLists<int>();
    graph->addVertex(1);
    AdjacencyList<int> list = graph->getVertex(0);
    REQUIRE(list.getId() == 0);
}

TEST_CASE("getVertex", "[GraphAdjacencyLists]") {
    auto graph = new GraphAdjacencyLists<int>();
    graph->addVertex(1);
    AdjacencyList<int> list = graph->getVertex(0);
    REQUIRE(list.getId() == 0);
}


TEST_CASE("removeVertex", "[GraphAdjacencyLists]") {
    auto graph = new GraphAdjacencyLists<int>();
    graph->addVertex(0);
    graph->addVertex(1);
    graph->removeVertex(1);
    auto vertex = graph->getVertex(0);
    REQUIRE(vertex.getId() == 0);
    REQUIRE(graph->getSize() == 1);
}

TEST_CASE("addAdjacencyToVertex", "[GraphAdjacencyLists]") {
    auto graph = new GraphAdjacencyLists<int>();
    graph->addVertex(0);
    graph->addVertex(1);
    graph->addAdjacencyToVertex(0, 1);
    REQUIRE(graph->getVertex(0).getAdjacencyId(0) == 1);
}

TEST_CASE("addAdjacencyToVertex not valid", "[GraphAdjacencyLists]") {
    auto graph = new GraphAdjacencyLists<int>();
    graph->addVertex(0);
    graph->addAdjacencyToVertex(0, 1);
    graph->getVertex(0).getAdjacencyId(0);
    REQUIRE(graph->getVertex(0).getAdjacencyId(0) == -1);
    graph->addAdjacencyToVertex(1, 0);
}

TEST_CASE("removeAdjacencyToVertex", "[GraphAdjacencyLists]") {
    auto graph = new GraphAdjacencyLists<int>();
    graph->addVertex(0);
    graph->addVertex(1);
    graph->addAdjacencyToVertex(0, 1);
    graph->removeAdjacencyToVertex(0, 1);
    graph->getVertex(0).getAdjacencyId(0);
    REQUIRE(graph->getVertex(0).getAdjacencyId(0) == -1);
}

TEST_CASE("removeAdjacencyToVertex not valid", "[GraphAdjacencyLists]") {
    auto graph = new GraphAdjacencyLists<int>();
    graph->removeAdjacencyToVertex(0, 1);
}


TEST_CASE("getSize", "[GraphAdjacencyLists]") {
    auto graph = new GraphAdjacencyLists<int>();
    graph->addVertex(0);
    graph->addVertex(1);
    REQUIRE(graph->getSize() == 2);
}

TEST_CASE("getIdByValue", "[GraphAdjacencyLists]") {
    auto graph = new GraphAdjacencyLists<int>();
    graph->addVertex(2);
    REQUIRE(graph->getIdByValue((int) 2) == 0);
}

TEST_CASE("getIdToIndex", "[GraphAdjacencyLists]") {
    auto graph = new GraphAdjacencyLists<int>();
    graph->addVertex(0);
    graph->addVertex(1);
    graph->addVertex(2);
    graph->addVertex(3);
    graph->removeVertex(2);
    graph->removeVertex(1);
    auto idToIndex = graph->getIdToIndex();
    for (int i = 0; i < graph->vertices.size(); i++) {
        REQUIRE(idToIndex[graph->vertices[i].getId()] == i);
    }
}