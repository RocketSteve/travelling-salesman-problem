#include "../../../src/classes/RandomNumberGenerator/RandomNumberGenerator.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>

TEST_CASE("constructor", "[RandomInstanceGenerator]") {
    auto random = RandomNumberGenerator::generate(0, 100);
    REQUIRE(random >= 0);
    REQUIRE(random <= 100);
}
