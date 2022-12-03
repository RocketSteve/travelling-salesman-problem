#ifndef TRAVELLING_SALESMAN_PROBLEM_GREEDYSOLVER_H
#define TRAVELLING_SALESMAN_PROBLEM_GREEDYSOLVER_H

#include "../Instance/Instance.h"

class GreedySolver {
private:
    Instance instance;
    vector<int> answer;
    map<int, int> idToIndex;
public:
    explicit GreedySolver(Instance instance);

    int findFirstVertex() const;

    int nextVertex(int currentVertexId) const;

    double solve();
};


#endif //TRAVELLING_SALESMAN_PROBLEM_GREEDYSOLVER_H
