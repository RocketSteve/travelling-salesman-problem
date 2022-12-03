#ifndef TRAVELLING_SALESMAN_PROBLEM_GREEDYSOLVER_H
#define TRAVELLING_SALESMAN_PROBLEM_GREEDYSOLVER_H

#include "../Instance/Instance.h"

class GreedySolver {
private:
    Instance instance;
    map<int, int> idToIndex;
public:
    vector<int> answer;

    explicit GreedySolver(Instance instance);

    int findFirstVertex() const;

    int nextVertex(int currentVertexId) const;

    double solve();

    void addVertexToAnswer(int id);
};


#endif //TRAVELLING_SALESMAN_PROBLEM_GREEDYSOLVER_H
