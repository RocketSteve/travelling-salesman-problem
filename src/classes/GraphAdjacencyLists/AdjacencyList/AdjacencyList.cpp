#include "AdjacencyList.h"

using namespace std;

template<typename ValueType>
AdjacencyList<ValueType>::AdjacencyList(int id, ValueType value) {
    this->value = value;
    this->id = id;
}

template<typename ValueType>
ValueType &AdjacencyList<ValueType>::getValue() {
    return this->value;
}

template<typename ValueType>
void AdjacencyList<ValueType>::pushAdjacency(AdjacencyList<ValueType> *adjacency) {
    this->adjacencyList.insert(adjacency);
}

template<typename ValueType>
void AdjacencyList<ValueType>::removeAdjacency(AdjacencyList<ValueType> *adjacency) {
    this->adjacencyList.erase(adjacency);
}

template<typename ValueType>
int AdjacencyList<ValueType>::getId() {
    return this->id;
}

template<typename ValueType>
AdjacencyList<ValueType> *AdjacencyList<ValueType>::getAdjacency(int index) {
    int currentIndex = 0;
    for (auto &adjacency: this->adjacencyList) {
        if (currentIndex == index) {
            return adjacency;
        }
        currentIndex++;
    }
    return nullptr;
}

template<typename ValueType>
bool AdjacencyList<ValueType>::operator==(const AdjacencyList<ValueType> &other) {
    return this->id == other.id &&
           this->value == other.value &&
           this->adjacencyList == other.adjacencyList;
}

template<typename ValueType>
int AdjacencyList<ValueType>::getSize() {
    return this->adjacencyList.size();
}

template
class AdjacencyList<int>;

template
class AdjacencyList<CoordinateWithVisitedState>;
