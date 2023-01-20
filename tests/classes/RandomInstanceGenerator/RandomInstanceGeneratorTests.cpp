#include "../../../src/classes/GreedySolver/GreedySolver.h"
#include "../../../src/classes/RandomInstanceGenerator/RandomInstanceGenerator.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>

TEST_CASE("constructor", "[RandomInstanceGenerator]") {
    auto randomInstanceGenerator = new RandomInstanceGenerator(5);
    REQUIRE(randomInstanceGenerator->graph->getSize() == 5);
}
