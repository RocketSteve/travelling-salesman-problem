#include "../src/classes/InstanceFileReader/InstanceFileReader.h"
#include "../src/classes/SimulatedAnnealingSolver/SimulatedAnnealingSolver.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#define BERLIN52 "resources/berlin52.txt"
#define BIER127 "resources/bier127.txt"
#define TSP1000 "resources/tsp1000.txt"
#define TSP500 "resources/tsp500.txt"
#define TSP250 "resources/tsp250.txt"

using std::cout;

void test_instance(const string &filename) {
    Instance *instance = new InstanceFileReader(filename);
    auto simulatedAnnealing = new SimulatedAnnealingSolver(instance);
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

TEST_CASE("berlin52", "[BenchmarkTests]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "BERLIN52" << endl;
    test_instance(BERLIN52);
}

TEST_CASE("bier127", "[BenchmarkTests]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "BIER127" << endl;
    test_instance(BIER127);
}

TEST_CASE("tsp1000", "[BenchmarkTests]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "TSP1000" << endl;
    test_instance(TSP1000);
}

TEST_CASE("tsp500", "[BenchmarkTests]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "TSP500" << endl;
    test_instance(TSP500);
}


TEST_CASE("tsp250", "[BenchmarkTests]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "TSP250" << endl;
    test_instance(TSP250);
}
