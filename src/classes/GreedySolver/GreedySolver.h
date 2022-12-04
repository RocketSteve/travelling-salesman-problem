#ifndef TRAVELLING_SALESMAN_PROBLEM_GREEDYSOLVER_H
#define TRAVELLING_SALESMAN_PROBLEM_GREEDYSOLVER_H

#include "../Instance/Instance.h"

class GreedySolver {
private:
    Instance instance;
    map<int, int> idToIndex;
    double distance = 0;
public:
    vector<int> answer;

    explicit GreedySolver(Instance instance);

    int findFirstVertex() const;

    pair<int, double> nextVertex(int currentVertexId) const;

    void solve();

    void addVertexToAnswer(int id);

    double getDistance() const;
};


#endif //TRAVELLING_SALESMAN_PROBLEM_GREEDYSOLVER_H
