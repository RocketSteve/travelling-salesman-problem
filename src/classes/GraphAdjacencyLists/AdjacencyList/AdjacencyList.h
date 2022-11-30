#ifndef TRAVELLING_SALESMAN_PROBLEM_ADJACENCYLIST_H
#define TRAVELLING_SALESMAN_PROBLEM_ADJACENCYLIST_H
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

template<typename ValueType>
class AdjacencyList {
private:
    int id{};
    ValueType value;
    set<int> adjacencyList;
public:
    AdjacencyList(int id, ValueType value);

    ValueType getValue();

    void pushAdjacency(int adjacencyId);

    void removeAdjacency(int adjacency);

    int getId();

    int getAdjacencyId(int index);

    int getSize();

    bool operator==(const AdjacencyList<ValueType> &other);
};




#endif //TRAVELLING_SALESMAN_PROBLEM_ADJACENCYLIST_H
