#ifndef TRAVELLING_SALESMAN_PROBLEM_INSTANCE_H
#define TRAVELLING_SALESMAN_PROBLEM_INSTANCE_H

#include "../CoordinateWithVisitedState/CoordinateWithVisitedState.h"
#include "../GraphAdjacencyLists/GraphAdjacencyLists.h"

class Instance {
public:
    GraphAdjacencyLists<CoordinateWithVisitedState> *graph = new GraphAdjacencyLists<CoordinateWithVisitedState>();

    void addVertex(CoordinateWithVisitedState point) const;

    void connectAllPoints() const;

    void writeToFile(const string &filename) const;
};


#endif//TRAVELLING_SALESMAN_PROBLEM_INSTANCE_H
