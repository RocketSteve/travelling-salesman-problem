#include <cfloat>
#include "GreedySolver.h"

GreedySolver::GreedySolver(Instance instance) {
    this->instance = instance;
    this->idToIndex = this->instance.graph->getIdToIndex();
}

void GreedySolver::solve() {
    int firstVertexId = this->findFirstVertex();
    this->answer.clear();
    this->distance = 0;
    this->addVertexToAnswer(firstVertexId);
    auto currentVertex = pair<int, double>(0, 0);
    while ((currentVertex = this->nextVertex(currentVertex.first)).first != -1) {
        this->distance += currentVertex.second;
        this->addVertexToAnswer(currentVertex.first);
    }
    auto lastIndex = this->answer[this->answer.size() - 1];
    auto lastVertex = this->instance.graph->getVertex(lastIndex).getValue();
    auto firstVertex = this->instance.graph->getVertex(firstVertexId).getValue();
    this->distance += lastVertex.getDistance(firstVertex);
    this->addVertexToAnswer(firstVertexId);
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

pair<int, double> GreedySolver::nextVertex(int currentVertexId) const {
    auto vertex = this->instance.graph->getVertex(currentVertexId);
    auto currentTheBestDistance = DBL_MAX;
    int currentTheBestId = -1;
    for (auto &i: vertex.adjacencyList) {
        auto potentiallyNextVertexIndex = this->idToIndex.at(i);
        AdjacencyList<CoordinateWithVisitedState> potentiallyNextVertex = this->instance.graph->getVertexByIndex(
                potentiallyNextVertexIndex);
        if (!potentiallyNextVertex.getValue().getVisited()) {
            double newDistance = vertex.getValue().getDistance(potentiallyNextVertex.getValue());
            if (newDistance < currentTheBestDistance) {
                currentTheBestId = potentiallyNextVertex.getId();
                currentTheBestDistance = newDistance;
            }
        }
    }
    return pair<int, double>(currentTheBestId, currentTheBestDistance);
}

void GreedySolver::addVertexToAnswer(int id) {
    this->instance.graph->getVertex(id).getValue().visitCoordinate();
    this->answer.push_back(id);
}

double GreedySolver::getDistance() const {
    return this->distance;
}


