#include <fstream>
#include "Instance.h"
#include "../GraphAdjacencyLists/AdjacencyList/AdjacencyList.cpp"

void Instance::addVertex(CoordinateWithVisitedState point) const {
    this->graph->addVertex(CoordinateWithVisitedState(point.getLatitude(), point.getLongitude()));
}

void Instance::connectAllPoints() const {
    for (AdjacencyList<CoordinateWithVisitedState> *listWithIdToAdded: this->graph->vertices) {
        for (AdjacencyList<CoordinateWithVisitedState> *listWhereIdWillBeAdded: this->graph->vertices) {
            if (listWithIdToAdded->getId() != listWhereIdWillBeAdded->getId())
                listWhereIdWillBeAdded->pushAdjacency(listWithIdToAdded);
        }
    }
}

void Instance::writeToFile(const string &filename) const {
    ofstream file;
    file.open(filename.c_str());
    file << to_string(this->graph->getSize()) << endl;
    for (AdjacencyList<CoordinateWithVisitedState> *i: this->graph->vertices) {
        file << to_string(i->getValue().getLatitude()) << " " << to_string(i->getValue().getLongitude()) << endl;
    }
    file.close();
}
