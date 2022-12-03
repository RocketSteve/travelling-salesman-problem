//
// Created by mateusz on 14.11.22.
//

#include "Instance.h"
#include "../GraphAdjacencyLists/AdjacencyList/AdjacencyList.cpp"

void Instance::addVertex(CoordinateWithVisitedState point) const {
    this->graph->addVertex(CoordinateWithVisitedState(point.getLatitude(), point.getLongitude()));
}

void Instance::connectAllPoints() const {
    for (AdjacencyList<CoordinateWithVisitedState> &listWithIdToAdded: this->graph->vertices) {
        for (AdjacencyList<CoordinateWithVisitedState> &listWhereIdWillBeAdded: this->graph->vertices) {
            if (listWithIdToAdded.getId() != listWhereIdWillBeAdded.getId())
                listWhereIdWillBeAdded.pushAdjacency(listWithIdToAdded.getId());
        }
    }
}
