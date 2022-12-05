#include <algorithm>
#include "GraphAdjacencyLists.h"

using namespace std;

template<typename ValueType>
void GraphAdjacencyLists<ValueType>::addVertex(ValueType value) {
    this->vertices.push_back(AdjacencyList<ValueType>(idIterator, value));
    idIterator++;
}

template<typename ValueType>
AdjacencyList<ValueType> &GraphAdjacencyLists<ValueType>::getVertex(int id) {
    for (AdjacencyList<ValueType> &i: this->vertices) {
        if (i.getId() == id) {
            return i;
        }
    }
    throw id;
}


template<typename ValueType>
AdjacencyList<ValueType> &GraphAdjacencyLists<ValueType>::getVertexByIndex(int index) {
    if (index >= this->vertices.size() || index < 0) {
        throw index;
    }
    return this->vertices.at(index);
}

template<typename ValueType>
void GraphAdjacencyLists<ValueType>::removeVertex(int id) {
    try {
        const AdjacencyList<ValueType> elementToRemove = this->getVertex(id);
        auto it = find(this->vertices.begin(), this->vertices.end(), elementToRemove);
        this->vertices.erase(it);
    }
    catch (int id) {
        cout << "OperationNotAllowedException: vertex id " + to_string(id) + " don't exist" << endl;
    }
}

template<typename ValueType>
void GraphAdjacencyLists<ValueType>::addAdjacencyToVertex(int vertexId, int adjacencyId) {
    try {
        AdjacencyList<ValueType> &vertex = getVertex(vertexId);
        if (this->checkIfVertexIdExist(adjacencyId)) {
            vertex.pushAdjacency(adjacencyId);
        } else {
            throw adjacencyId;
        }
    }
    catch (int id) {
        cout << "OperationNotAllowedException: vertex id " + to_string(id) + " don't exist" << endl;
    }
}

template<typename ValueType>
void GraphAdjacencyLists<ValueType>::removeAdjacencyToVertex(int vertexId, int adjacencyId) {
    try {
        AdjacencyList<ValueType> &vertex = getVertex(vertexId);
        if (this->checkIfVertexIdExist(adjacencyId)) {
            vertex.removeAdjacency(adjacencyId);
        }
    }
    catch (int id) {
        cout << "OperationNotAllowedException: vertex id " + to_string(id) + " don't exist" << endl;
    }
}

template<typename ValueType>
int GraphAdjacencyLists<ValueType>::getIdByValue(ValueType value) {
    for (AdjacencyList<ValueType> &i: this->vertices) {
        if (i.getValue() == value) {
            return i.getId();
        }
    }
    return -1;
}

template<typename ValueType>
int GraphAdjacencyLists<ValueType>::getSize() {
    return this->vertices.size();
}

template<typename ValueType>
int GraphAdjacencyLists<ValueType>::checkIfVertexIdExist(int id) {
    bool isExist = false;
    for (AdjacencyList<ValueType> &i: this->vertices) {
        if (i.getId() == id) {
            isExist = true;
        }
    }
    return isExist;
}

template<typename ValueType>
map<int, int> GraphAdjacencyLists<ValueType>::getIdToIndex() {
    int i = 0;
    map<int, int> idToIndex;
    for (AdjacencyList<ValueType> &object: this->vertices) {
        idToIndex.insert(pair<int, int>(object.getId(), i));
        i++;
    }
    return idToIndex;
}
