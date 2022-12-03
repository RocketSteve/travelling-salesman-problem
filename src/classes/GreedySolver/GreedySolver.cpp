#include "GreedySolver.h"

GreedySolver::GreedySolver(Instance instance) {
    this->instance = instance;
}

double GreedySolver::solve() {
    return 0;
}

int GreedySolver::findFirstVertex() const {
    if (this->instance.graph->getSize() > 0) {
        int firstIndex = 0;
        while (!this->instance.graph->checkIfVertexIdExist(firstIndex)) {
            firstIndex++;
        }
        return firstIndex;
    }
    return -1;
}


