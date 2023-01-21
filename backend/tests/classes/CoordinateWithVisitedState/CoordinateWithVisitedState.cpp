#include "../../../src/classes/GreedySolver/GreedySolver.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

TEST_CASE("constructor", "[CoordinateWithVisitedState]") {
    auto coordinate = CoordinateWithVisitedState(1, 2);
    REQUIRE(coordinate.getLongitude() == 2);
    REQUIRE(coordinate.getLatitude() == 1);
}

TEST_CASE("visitedTest", "[CoordinateWithVisitedState]") {
    auto coordinate = CoordinateWithVisitedState(1, 2);
    REQUIRE(coordinate.getVisited() == false);
    coordinate.visitCoordinate();
    REQUIRE(coordinate.getVisited() == true);
}
