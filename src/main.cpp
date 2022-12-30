#include "../src/classes/SimulatedAnnealingSolver/SimulatedAnnealingSolver.h"
#include "../src/classes/InstanceFileReader/InstanceFileReader.h"
#include <chrono>

#include <iostream>

using namespace std;
using namespace std::chrono;


int main() {
    Instance *instance = new InstanceFileReader("resources/berlin52.txt");
    auto simulatedAnnealing = new SimulatedAnnealingSolver(instance);
    simulatedAnnealing->greedySolve();
    auto greedyDistance = simulatedAnnealing->getDistance();
    auto start = high_resolution_clock::now();
    simulatedAnnealing->solve();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << "TEST RESULT | Time: " << duration.count() << endl;
    cout << "TEST RESULT | Greedy distance: " << greedyDistance << endl;
    cout << "TEST RESULT | Distance: " << simulatedAnnealing->getDistance() << endl;
    string path;
    for (AdjacencyList<CoordinateWithVisitedState> *i: simulatedAnnealing->answer) {
        path += to_string(i->getId()) + " ";
    }
    cout << "TEST RESULT | Path: " << path << endl;
    return 0;
}