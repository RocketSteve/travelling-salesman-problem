#include "GraphAdjacencyLists.h"
#include <algorithm>

template<typename ValueType>
void GraphAdjacencyLists<ValueType>::addVertex(ValueType value) {
    this->vertices.push_back(new AdjacencyList<ValueType>(idIterator, value));
    idIterator++;
}

template<typename ValueType>
AdjacencyList<ValueType> *GraphAdjacencyLists<ValueType>::getVertex(int id) {
    if (checkIfVertexIdExist(id)) {
        for (AdjacencyList<ValueType> *i: this->vertices) {
            if (i->getId() == id) { return i; }
        }
    } else {
        throw id;
    }
    return nullptr;
}

template<typename ValueType>
AdjacencyList<ValueType> *GraphAdjacencyLists<ValueType>::getVertexByIndex(int index) {
    if (index >= this->vertices.size() || index < 0) { throw index; }
    return this->vertices.at(index);
}


template<typename ValueType>
void GraphAdjacencyLists<ValueType>::removeVertex(int id) {
    try {
        const AdjacencyList<ValueType> *elementToRemove = this->getVertex(id);
        auto it = find(this->vertices.begin(), this->vertices.end(), elementToRemove);
        this->vertices.erase(it);
    } catch (int id) { cout << "OperationNotAllowedException: vertex id " + to_string(id) + " don't exist" << endl; }
}

template<typename ValueType>
void GraphAdjacencyLists<ValueType>::addAdjacencyToVertex(int vertexId, int adjacencyId) {
    try {
        AdjacencyList<ValueType> *vertex = getVertex(vertexId);
        AdjacencyList<ValueType> *vertexToAdd = getVertex(adjacencyId);
        vertex->pushAdjacency(vertexToAdd);
    } catch (int id) { cout << "OperationNotAllowedException: vertex id " + to_string(id) + " don't exist" << endl; }
}

template<typename ValueType>
void GraphAdjacencyLists<ValueType>::removeAdjacencyFromVertex(int vertexId, int adjacencyId) {
    try {
        AdjacencyList<ValueType> *vertex = getVertex(vertexId);
        AdjacencyList<ValueType> *toRemove = getVertex(adjacencyId);
        if (this->checkIfVertexIdExist(adjacencyId)) { vertex->removeAdjacency(toRemove); }
    } catch (int id) { cout << "OperationNotAllowedException: vertex id " + to_string(id) + " don't exist" << endl; }
}

template<typename ValueType>
int GraphAdjacencyLists<ValueType>::getIdByValue(ValueType value) {
    for (AdjacencyList<ValueType> *i: this->vertices) {
        if (i->getValue() == value) { return i->getId(); }
    }
    return -1;
}

template<typename ValueType>
int GraphAdjacencyLists<ValueType>::getSize() {
    return this->vertices.size();
}

template<typename ValueType>
bool GraphAdjacencyLists<ValueType>::checkIfVertexIdExist(int id) {
    bool isExist = false;
    for (AdjacencyList<ValueType> *i: this->vertices) {
        if (i->getId() == id) { isExist = true; }
    }
    return isExist;
}

template class GraphAdjacencyLists<CoordinateWithVisitedState>;

template class GraphAdjacencyLists<int>;
