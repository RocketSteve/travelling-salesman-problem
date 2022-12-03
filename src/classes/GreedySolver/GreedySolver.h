#ifndef TRAVELLING_SALESMAN_PROBLEM_GREEDYSOLVER_H
#define TRAVELLING_SALESMAN_PROBLEM_GREEDYSOLVER_H

#include "../Instance/Instance.h"

class GreedySolver {
private:
    Instance instance;
public:
    explicit GreedySolver(Instance instance);

    int findFirstVertex() const;

    double solve();
};


#endif //TRAVELLING_SALESMAN_PROBLEM_GREEDYSOLVER_H
