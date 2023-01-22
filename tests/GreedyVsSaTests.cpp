#include "../src/classes/InstanceFileReader/InstanceFileReader.h"
#include "../src/classes/RandomInstanceGenerator/RandomInstanceGenerator.h"
#include "../src/classes/SimulatedAnnealingSolver/SimulatedAnnealingSolver.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

using std::cout;
using std::endl;
using std::to_string;

void test_instance(Instance *instance) {
    auto simulatedAnnealing = new SimulatedAnnealingSolver(instance, 1e-6, 2000000, 0.99999);
    simulatedAnnealing->greedySolve();
    auto greedyDistance = simulatedAnnealing->getDistance();
    simulatedAnnealing->solve();
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << "TEST RESULT | Greedy distance: " << greedyDistance << endl;
    cout << "TEST RESULT | Distance: " << simulatedAnnealing->getDistance() << endl;
    string path;
    for (AdjacencyList<CoordinateWithVisitedState> *i: simulatedAnnealing->answer) {
        path += to_string(i->getId()) + " ";
    }
    cout << "TEST RESULT | Path: " << path << endl;
    delete instance;
    delete simulatedAnnealing;
}

TEST_CASE("RandomInstances", "[GAvsSATests]") {
    for (int i = 50; i <= 800; i += 50) {
        SECTION("Random Tests for size: " + to_string(i)) {
            auto randomInstanceGenerator = new RandomInstanceGenerator(i);
            randomInstanceGenerator->connectAllPoints();
            test_instance(randomInstanceGenerator);
        }
    }
}