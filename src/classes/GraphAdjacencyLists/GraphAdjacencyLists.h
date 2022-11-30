#ifndef TRAVELLING_SALESMAN_PROBLEM_GRAPHADJACENCYLISTS_H
#define TRAVELLING_SALESMAN_PROBLEM_GRAPHADJACENCYLISTS_H

#include <list>
#include "AdjacencyList/AdjacencyList.h"

using namespace std;

template<typename ValueType>
class GraphAdjacencyLists {
private:
    list <AdjacencyList<ValueType>> vertices;
    int idIterator = 0;
public:
    GraphAdjacencyLists() = default;

    void addVertex(ValueType value);

    void removeVertex(int id);

    AdjacencyList<ValueType> &getVertex(int id);

    void addAdjacencyToVertex(int vertexId, int adjacencyId);

    void removeAdjacencyToVertex(int vertexId, int adjacencyId);

    int getIdByValue(ValueType value);

    int getSize();

    int checkIfVertexIdExist(int id);
};

#endif //TRAVELLING_SALESMAN_PROBLEM_GRAPHADJACENCYLISTS_H
