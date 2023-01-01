#ifndef TRAVELLING_SALESMAN_PROBLEM_SIMULATEDANNEALINGSOLVER_H
#define TRAVELLING_SALESMAN_PROBLEM_SIMULATEDANNEALINGSOLVER_H

#include "../GraphAdjacencyLists/AdjacencyList/AdjacencyList.h"
#include "../GraphAdjacencyLists/GraphAdjacencyLists.h"
#include "../GreedySolver/GreedySolver.h"
#include "../Instance/Instance.h"
#include <vector>

class SimulatedAnnealingSolver {
private:
    double temperature;
    double stoppingTemperature{};
    int stoppingIteration;
    double distance{};
    double currentDistance{};
    float alpha;
    Instance instance;
    vector<AdjacencyList<CoordinateWithVisitedState> *> currentAnswer = {};

    void newTemperature();

public:
    vector<AdjacencyList<CoordinateWithVisitedState> *> answer = {};

    explicit SimulatedAnnealingSolver(Instance *instance, double stoppingTemperature = 1e-6,
                                      int stoppingIteration = 2000000,
                                      float alpha = 0.99999);

    double calculateDistance(vector<AdjacencyList<struct CoordinateWithVisitedState> *> coordinateList) const;

    void calculateDistance();

    double getDistance() const;

    double probabilityAccept(double probabilityDistance) const;

    void accept(const vector<AdjacencyList<CoordinateWithVisitedState> *> &candidate);

    void solve();

    void greedySolve();
};


#endif//TRAVELLING_SALESMAN_PROBLEM_SIMULATEDANNEALINGSOLVER_H
