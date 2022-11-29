#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include "../../../../src/classes/GraphAdjacencyLists/AdjacencyList/AdjacencyList.h"
#include "../../../../src/classes/GraphAdjacencyLists/AdjacencyList/AdjacencyList.cpp"

using namespace Catch::Matchers;

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
    auto adjacencyList = new AdjacencyList<int>(id, (int) 5);
    REQUIRE(adjacencyList->getId() == id);
}

TEST_CASE("pushAdjacency()", "[AdjacencyList]") {
    int id = 0;
    int addedIdToAdjacencyList = 4;
    auto adjacencyList = new AdjacencyList<int>(id, (int) 5);
    adjacencyList->pushAdjacency(3);
    adjacencyList->pushAdjacency(addedIdToAdjacencyList);
    auto lastElementOfAdjacencyList = adjacencyList->getAdjacencyId(1);
    REQUIRE(addedIdToAdjacencyList == lastElementOfAdjacencyList);
}

TEST_CASE("getAdjacencyId(index)", "[AdjacencyList]") {
    int addedIdToAdjacencyList = 4;
    auto adjacencyList = new AdjacencyList<int>(0, (int) 5);
    adjacencyList->pushAdjacency(3);
    adjacencyList->pushAdjacency(addedIdToAdjacencyList);
    REQUIRE(addedIdToAdjacencyList == adjacencyList->getAdjacencyId(1));
}

TEST_CASE("removeAdjacency()", "[AdjacencyList]") {
    int id = 0;
    int addedIdToAdjacencyList = 4;
    auto adjacencyList = new AdjacencyList<int>(id, (int) 5);
    adjacencyList->pushAdjacency(addedIdToAdjacencyList);
    adjacencyList->pushAdjacency(3);
    adjacencyList->removeAdjacency(addedIdToAdjacencyList);
    adjacencyList->getAdjacencyId(addedIdToAdjacencyList);
    REQUIRE(-1 == adjacencyList->getAdjacencyId(1));
}

TEST_CASE("operator!=()", "[AdjacencyList]") {
    auto adjacencyList = new AdjacencyList<int>(1, (int) 5);
    auto adjacencyList2 = new AdjacencyList<int>(1, (int) 5);
    adjacencyList->pushAdjacency(2);
    adjacencyList2->pushAdjacency(2);
    REQUIRE(adjacencyList != adjacencyList2);
}

TEST_CASE("operator==()", "[AdjacencyList]") {
    auto adjacencyList = new AdjacencyList<int>(1, (int) 5);
    adjacencyList->pushAdjacency(2);
    auto adjacencyList2 = &adjacencyList;
    REQUIRE(&adjacencyList == adjacencyList2);
}
