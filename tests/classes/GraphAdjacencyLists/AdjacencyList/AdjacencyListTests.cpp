#include "../../../../src/classes/GreedySolver/GreedySolver.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>

TEST_CASE("constructor", "[AdjacencyList]") {
    int number = 5;
    int id = 0;
    auto adjacencyList = new AdjacencyList<int>(id, number);
    REQUIRE(adjacencyList->getValue() == number);
    REQUIRE(adjacencyList->getId() == id);
}

TEST_CASE("getValue()", "[AdjacencyList]") {
    int number = 5;
    auto adjacencyList = new AdjacencyList<int>(0, number);
    REQUIRE(adjacencyList->getValue() == number);
}


TEST_CASE("getId()", "[AdjacencyList]") {
    int id = 0;
    auto adjacencyList = new AdjacencyList<int>(id, 5);
    REQUIRE(adjacencyList->getId() == id);
}

TEST_CASE("pushAdjacency()", "[AdjacencyList]") {
    int id = 0;
    auto adjacencyList = new AdjacencyList<int>(id, 5);
    auto adjacencyList2 = new AdjacencyList<int>(1, 3);
    adjacencyList->pushAdjacency(adjacencyList2);
    auto lastElementOfAdjacencyList = adjacencyList->getAdjacency(0);
    REQUIRE(adjacencyList2 == lastElementOfAdjacencyList);
}

TEST_CASE("getAdjacency(index)", "[AdjacencyList]") {
    auto adjacencyList = new AdjacencyList<int>(0, 5);
    auto adjacencyList2 = new AdjacencyList<int>(1, 3);
    adjacencyList->pushAdjacency(adjacencyList2);
    REQUIRE(adjacencyList2 == adjacencyList->getAdjacency(0));
}

TEST_CASE("removeAdjacency()", "[AdjacencyList]") {
    int id = 0;
    auto adjacencyList = new AdjacencyList<int>(id, 5);
    auto adjacencyList2 = new AdjacencyList<int>(1, 3);
    auto adjacencyList3 = new AdjacencyList<int>(1, 4);
    adjacencyList->pushAdjacency(adjacencyList2);
    adjacencyList->pushAdjacency(adjacencyList3);
    adjacencyList->removeAdjacency(adjacencyList2);
    REQUIRE(nullptr == adjacencyList->getAdjacency(1));
}

TEST_CASE("operator!=()", "[AdjacencyList]") {
    auto adjacencyList = new AdjacencyList<int>(1, 5);
    auto adjacencyList2 = new AdjacencyList<int>(1, 5);
    adjacencyList->pushAdjacency(adjacencyList2);
    adjacencyList2->pushAdjacency(adjacencyList);
    REQUIRE(adjacencyList != adjacencyList2);
}

TEST_CASE("operator==()", "[AdjacencyList]") {
    auto adjacencyList = new AdjacencyList<int>(1, 5);
    auto adjacencyList2 = &adjacencyList;
    REQUIRE(&adjacencyList == adjacencyList2);
}

TEST_CASE("size()", "[AdjacencyList]") {
    auto adjacencyList = new AdjacencyList<int>(1, 5);
    auto adjacencyList2 = new AdjacencyList<int>(2, 3);
    auto adjacencyList3 = new AdjacencyList<int>(3, 4);
    auto adjacencyList4 = new AdjacencyList<int>(4, 5);
    adjacencyList->pushAdjacency(adjacencyList2);
    adjacencyList->pushAdjacency(adjacencyList3);
    adjacencyList->pushAdjacency(adjacencyList4);
    REQUIRE(adjacencyList->getSize() == 3);
}
