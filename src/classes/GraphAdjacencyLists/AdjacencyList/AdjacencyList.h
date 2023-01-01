#ifndef TRAVELLING_SALESMAN_PROBLEM_ADJACENCYLIST_H
#define TRAVELLING_SALESMAN_PROBLEM_ADJACENCYLIST_H

#include "../../Coordinate/Coordinate.h"
#include "../../CoordinateWithVisitedState/CoordinateWithVisitedState.h"
#include <iostream>
#include <iterator>
#include <memory>
#include <set>

using namespace std;

template<typename ValueType>
class AdjacencyList {
private:
    int id{};
    ValueType value;

public:
    set<AdjacencyList<ValueType> *> adjacencyList;

    AdjacencyList(int id, ValueType value);

    ValueType &getValue();

    void pushAdjacency(AdjacencyList<ValueType> *adjacency);

    void removeAdjacency(AdjacencyList<ValueType> *adjacency);

    int getId();

    AdjacencyList<ValueType> *getAdjacency(int index);

    int getSize();

    bool operator==(const AdjacencyList<ValueType> &other);
};


#endif//TRAVELLING_SALESMAN_PROBLEM_ADJACENCYLIST_H
