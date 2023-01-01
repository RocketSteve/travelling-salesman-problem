#include "GreedySolver.h"
#include <cfloat>

GreedySolver::GreedySolver(Instance instance) {
    this->instance = instance;
}

void GreedySolver::solve() {
    auto firstVertex = this->findFirstVertex();
    this->answer.clear();
    this->distance = 0;
    this->addVertexToAnswer(firstVertex);
    auto currentVertex = pair<AdjacencyList<CoordinateWithVisitedState> *, double>(firstVertex, 0);
    while ((currentVertex = GreedySolver::nextVertex(currentVertex.first)).first != nullptr) {
        this->distance += currentVertex.second;
        this->addVertexToAnswer(currentVertex.first);
    }
    auto lastVertex = this->answer[this->answer.size() - 1];
    this->distance += lastVertex->getValue().getDistance(firstVertex->getValue());
    this->addVertexToAnswer(firstVertex);
}

AdjacencyList<CoordinateWithVisitedState> *GreedySolver::findFirstVertex() const {
    if (this->instance.graph->getSize() < 1) {
        return nullptr;
    }
    return this->instance.graph->vertices[0];
}

pair<AdjacencyList<CoordinateWithVisitedState> *, double> GreedySolver::nextVertex(
        AdjacencyList<CoordinateWithVisitedState> *currentVertex) {
    auto currentTheBestDistance = DBL_MAX;
    AdjacencyList<CoordinateWithVisitedState> *currentTheBest = nullptr;
    for (auto potentiallyNextVertex: currentVertex->adjacencyList) {
        if (!potentiallyNextVertex->getValue().getVisited()) {
            double newDistance = currentVertex->getValue().getDistance(potentiallyNextVertex->getValue());
            if (newDistance < currentTheBestDistance) {
                currentTheBest = potentiallyNextVertex;
                currentTheBestDistance = newDistance;
            }
        }
    }
    return {currentTheBest, currentTheBestDistance};
}

void GreedySolver::addVertexToAnswer(AdjacencyList<CoordinateWithVisitedState> *vertex) {
    vertex->getValue().visitCoordinate();
    this->answer.push_back(vertex);
}

double GreedySolver::getDistance() const {
    return this->distance;
}
