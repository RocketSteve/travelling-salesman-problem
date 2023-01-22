#include "../src/classes/InstanceFileReader/InstanceFileReader.h"
#include "../src/classes/SimulatedAnnealingSolver/SimulatedAnnealingSolver.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#define A280 "resources/a280.txt"
#define LIN318 "resources/lin318.txt"
#define RD100 "resources/rd100.txt"
#define RAT99 "resources/rat99.txt"
#define ST70 "resources/st70.txt"
#define KROA100 "resources/kroA100.txt"
#define LIN105 "resources/lin105.txt"
#define CH150 "resources/ch150.txt"
#define ELI51 "resources/eil51.txt"
#define U159 "resources/u159.txt"

using std::cout;
using std::endl;
using std::to_string;

void test_instance(const string &filename, const double optimalDistance) {
    Instance *instance = new InstanceFileReader(filename);
    auto simulatedAnnealing = new SimulatedAnnealingSolver(instance);
    simulatedAnnealing->solve();
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << "TEST RESULT | Optimal distance: " << optimalDistance << endl;
    cout << "TEST RESULT | Distance: " << simulatedAnnealing->getDistance() << endl;
    string path;
    for (AdjacencyList<CoordinateWithVisitedState> *i: simulatedAnnealing->answer) {
        path += to_string(i->getId()) + " ";
    }
    cout << "TEST RESULT | Path: " << path << endl;
    delete instance;
    delete simulatedAnnealing;
}

TEST_CASE("A280", "[OpVsSa]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "A280" << endl;
    test_instance(A280, 2579);
}


TEST_CASE("LIN318", "[OpVsSa]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "LIN318" << endl;
    test_instance(LIN318, 42029);
}

TEST_CASE("RD100", "[OpVsSa]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "RD100" << endl;
    test_instance(RD100, 7910);
}

TEST_CASE("RAT99", "[OpVsSa]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "RAT99" << endl;
    test_instance(RAT99, 1211);
}

TEST_CASE("ST70", "[OpVsSa]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "ST70" << endl;
    test_instance(ST70, 675);
}

TEST_CASE("LIN105", "[OpVsSa]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "LIN105" << endl;
    test_instance(LIN105, 14379);
}

TEST_CASE("CH150", "[OpVsSa]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "CH150" << endl;
    test_instance(CH150, 6528);
}

TEST_CASE("ELI51", "[OpVsSa]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "ELI51" << endl;
    test_instance(ELI51, 426);
}

TEST_CASE("KROA100", "[OpVsSa]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "KROA100" << endl;
    test_instance(KROA100, 21282);
}

TEST_CASE("U159", "[OpVsSa]") {
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << endl << "U159" << endl;
    test_instance(U159, 42080);
}