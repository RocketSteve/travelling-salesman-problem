#include "classes/InstanceFileReader/InstanceFileReader.h"
#include "classes/SimulatedAnnealingSolver/SimulatedAnnealingSolver.h"
#include <iostream>

using std::cout;
using std::endl;
using std::stod;
using std::stof;
using std::stoi;
using std::to_string;

int main(int argc, char *argv[]) {
    SimulatedAnnealingSolver *solver;
    if (argc < 2) {
        cout << "Too few arguments" << endl;
        cout << "Usage minimal: instanceFilename" << endl;
        cout << "Usage: instanceFilename stoppingTemperature stoppingIteration alpha" << endl;
    } else if (argc < 5) {
        Instance *instance = new InstanceFileReader(argv[1]);
        solver = new SimulatedAnnealingSolver(instance);
    } else {
        Instance *instance = new InstanceFileReader(argv[1]);
        solver = new SimulatedAnnealingSolver(instance, stod(argv[2]), stoi(argv[3]), stof(argv[4]));
    }
    solver->solve();
    cout << "Distance: " << solver->getDistance() << endl;
    string path;
    for (AdjacencyList<CoordinateWithVisitedState> *i: solver->answer) { path += to_string(i->getId()) + " "; }
    cout << "Path: " << path << endl;
    return 0;
}
