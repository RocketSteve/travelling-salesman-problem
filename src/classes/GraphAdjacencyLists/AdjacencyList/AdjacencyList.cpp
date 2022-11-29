#include <algorithm>
#include "AdjacencyList.h"

using namespace std;

template<typename ValueType>
AdjacencyList<ValueType>::AdjacencyList(int id, ValueType value) {
    this->value = value;
    this->id = id;
}

template<typename ValueType>
ValueType AdjacencyList<ValueType>::getValue() {
    return this->value;
}

template<typename ValueType>
void AdjacencyList<ValueType>::pushAdjacency(int adjacencyId) {
    this->adjacencyList.insert(adjacencyId);
}

template<typename ValueType>
void AdjacencyList<ValueType>::removeAdjacency(int adjacencyId) {
    this->adjacencyList.erase(adjacencyId);

}

template<typename ValueType>
set<int> AdjacencyList<ValueType>::getAdjacencyList() {
    return this->adjacencyList;
}

template<typename ValueType>
int AdjacencyList<ValueType>::getId() {
    return this->id;
}

template<typename ValueType>
int AdjacencyList<ValueType>::getAdjacencyId(int index) {
    int currentIndex = 0;
    for (auto &adjacency: this->adjacencyList) {
        if (currentIndex == index) {
            return adjacency;
        }
        currentIndex++;
    }
    return -1;
}

template<typename ValueType>
bool AdjacencyList<ValueType>::operator==(const AdjacencyList<ValueType> &other) {
    return this->id == other.id &&
           this->value == other.value &&
           this->adjacencyList == other.adjacencyList;
}




