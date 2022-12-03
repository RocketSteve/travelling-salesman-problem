#include "GreedySolver.h"

GreedySolver::GreedySolver(Instance instance) {
    this->instance = instance;
    this->idToIndex = this->instance.graph->getIdToIndex();
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

int GreedySolver::nextVertex(int currentVertexId) const {
    auto vertex = this->instance.graph->getVertex(currentVertexId);
    auto vertices = this->instance.graph->vertices;
    double distance = 0;
    int currentTheSmallestDistanceId = -1;
    for (auto &i: vertex.adjacencyList) {
        auto potentiallyNextVertexId = this->idToIndex.at(i);
        AdjacencyList<CoordinateWithVisitedState> potentiallyNextVertex = vertices[potentiallyNextVertexId];
        if (!potentiallyNextVertex.getValue().getVisited()) {
            double newDistance = vertex.getValue().getDistance(potentiallyNextVertex.getValue());
            if (newDistance > distance) {
                currentTheSmallestDistanceId = potentiallyNextVertex.getId();
            }
        }
    }
    return currentTheSmallestDistanceId;
}


