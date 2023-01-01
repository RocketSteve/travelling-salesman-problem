#ifndef TRAVELLING_SALESMAN_PROBLEM_GRAPHADJACENCYLISTS_H
#define TRAVELLING_SALESMAN_PROBLEM_GRAPHADJACENCYLISTS_H

#include "AdjacencyList/AdjacencyList.h"
#include <list>
#include <map>
#include <vector>

using namespace std;

template<class ValueType>
class GraphAdjacencyLists {
private:
    int idIterator = 0;

public:
    vector<AdjacencyList<ValueType> *> vertices;

    GraphAdjacencyLists() = default;

    void addVertex(ValueType value);

    void removeVertex(int id);

    AdjacencyList<ValueType> *getVertex(int id);

    void addAdjacencyToVertex(int vertexId, int adjacencyId);

    void removeAdjacencyFromVertex(int vertexId, int adjacencyId);

    int getIdByValue(ValueType value);

    int getSize();

    bool checkIfVertexIdExist(int id);

    AdjacencyList<ValueType> *getVertexByIndex(int index);
};

#endif//TRAVELLING_SALESMAN_PROBLEM_GRAPHADJACENCYLISTS_H
