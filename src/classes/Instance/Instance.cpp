#include <fstream>
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

void Instance::writeToFile(const string &filename) const {
    fstream file;
    file.open(filename.c_str(), ios::out | ios::in);
    file << to_string(this->graph->getSize()) << endl;
    for (AdjacencyList<CoordinateWithVisitedState> &i: this->graph->vertices) {
        file << to_string(i.getValue().getLatitude()) << " " << to_string(i.getValue().getLongitude()) << endl;
    }
    file.close();
}
