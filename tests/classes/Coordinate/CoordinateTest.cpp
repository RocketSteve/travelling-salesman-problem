#include "../../../src/classes/Coordinate/Coordinate.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

using namespace Catch::Matchers;

TEST_CASE("constructor", "[Coordinate]") {
    const auto longitude = 10.20;
    const auto latitude = 20.34;
    auto coordinate = Coordinate(latitude, longitude);
    REQUIRE(coordinate.getLongitude() == longitude);
    REQUIRE(coordinate.getLatitude() == latitude);
}

TEST_CASE("getLongitude", "[Coordinate]") {
    const auto longitude = 10.20;
    const auto latitude = 20.34;
    auto coordinate = Coordinate(latitude, longitude);
    REQUIRE(coordinate.getLongitude() == longitude);
}

TEST_CASE("getLatitude", "[Coordinate]") {
    const auto longitude = 10.20;
    const auto latitude = 20.34;
    auto coordinate = Coordinate(latitude, longitude);
    REQUIRE(coordinate.getLatitude() == latitude);
}

TEST_CASE("getDistance", "[Coordinate]") {
    auto coordinate = Coordinate(20.5, 30.5);
    auto coordinate2 = Coordinate(10, 15);
    auto coordinate3 = Coordinate(25, 15);
    const double result = 18.7216452268;
    const double result2 = 16.1400123916;
    SECTION("Positive A and B") { REQUIRE_THAT(coordinate.getDistance(coordinate2), WithinRel(result, 0.000001)); }
    SECTION("Negative A and B") { REQUIRE_THAT(coordinate2.getDistance(coordinate), WithinRel(result, 0.000001)); }
    SECTION("Negative A and positive B") {
        REQUIRE_THAT(coordinate.getDistance(coordinate3), WithinRel(result2, 0.000001));
    }
    SECTION("Positive A and negative B") {
        REQUIRE_THAT(coordinate3.getDistance(coordinate), WithinRel(result2, 0.000001));
    }
    SECTION("Distance between the same points") { REQUIRE(coordinate.getDistance(coordinate) == 0); }
}

TEST_CASE("operator==", "[Coordinate]") {
    auto coordinate = Coordinate(10, 15);
    auto coordinate2 = Coordinate(10, 15);
    REQUIRE(coordinate == coordinate2);
}