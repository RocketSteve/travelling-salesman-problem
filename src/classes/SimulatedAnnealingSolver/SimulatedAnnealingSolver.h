#ifndef TRAVELLING_SALESMAN_PROBLEM_SIMULATEDANNEALINGSOLVER_H
#define TRAVELLING_SALESMAN_PROBLEM_SIMULATEDANNEALINGSOLVER_H

#include <vector>
#include "../Instance/Instance.h"
#include "../GreedySolver/GreedySolver.h"
#include "../GraphAdjacencyLists/AdjacencyList/AdjacencyList.h"
#include "../GraphAdjacencyLists/GraphAdjacencyLists.h"

class SimulatedAnnealingSolver {
private:
    Instance *instance;
    double temperature;
    double stoppingTemperature{};
    int stoppingIteration;
    double distance;
    double currentDistance{};
    float alpha;
    vector<AdjacencyList<CoordinateWithVisitedState> *> currentAnswer = {};

    static double generateRandomNumber(double from, double to);

    void newTemperature();

public:
    vector<AdjacencyList<CoordinateWithVisitedState> *> answer = {};

    explicit SimulatedAnnealingSolver(Instance *instance, double stoppingTemperature = 1e-8,
                                      float temperature = 10000, int stoppingIteration = 1000000,
                                      float alpha = 0.999);

    double calculateDistance(vector<AdjacencyList<struct CoordinateWithVisitedState> *> coordinateList) const;

    void calculateDistance();

    double getDistance() const;

    double probabilityAccept(double probabilityDistance);

    void accept(vector<AdjacencyList<CoordinateWithVisitedState> *> candidate);

    void solve();
};


#endif //TRAVELLING_SALESMAN_PROBLEM_SIMULATEDANNEALINGSOLVER_H
