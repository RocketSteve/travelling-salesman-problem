//
// Created by mateusz on 14.11.22.
//

#include "GraphAdjacencyMatrix.h"

// Index 0,0 gives the total lenght of choosen path
// Naive approach by going to the next clostest node
GraphAdjacencyMatrix GraphAdjacencyMatrix::travellingSalesman_start(int start, GraphAdjacencyMatrix original){
    GraphAdjacencyMatrix ans(v);
    double lenght;

    double path = __DBL_MAX__;
    double oldPath = path;

    int temp;

    // Check if this node has been visited
    if (this->visit[start] == 0){
        for (int i = 0; i < v; i++){
            if (this->arr[start][i] != 0){
                path = min(path, this->arr[start][i]);
                // Test if path minimum value has changed and save its position
                if (oldPath != path){
                    temp = i;
                    oldPath = path;
                }
            }
        }
        lenght += this->arr[start][temp];
        this->delEdge(start);
        this->visited(start);
        ans.addEdge(start, temp, 1);
        this->answer.push_back(temp);

        this->travellingSalesman_recursive(temp, ans, lenght, original);

        return ans;
    } else {
        std::cout << lenght << " - długość ściezki\n";
        return ans;
    }
}

GraphAdjacencyMatrix GraphAdjacencyMatrix::travellingSalesman_recursive(int start, GraphAdjacencyMatrix ans, double lenght, GraphAdjacencyMatrix original){

    double path = __DBL_MAX__;
    double oldPath = path;

    int temp = 0;

    // Check if this node has been visited
    if (this->visit[start] == 0){
        for (int i = 0; i < v; i++){
            if (this->arr[start][i] != 0){
                path = min(path, this->arr[start][i]);
                // Test if path has changed
                if (oldPath != path){
                    temp = i;
                    oldPath = path;
                }
            }
        }
        lenght += this->arr[start][temp];

        // Delete edge to make it easier and mark it as visited
        this->delEdge(start);
        this->visited(start);
        // Add edge to matrix containing only Hamiltionian cycle and add next node to answer array
        ans.addEdge(start, temp, 1);
        this->answer.push_back(temp);

        this->travellingSalesman_recursive(temp, ans, lenght, original);

        return ans;
    } else {
        // Original graph needed to extract lenght of path between last visited node and the first one
        original.printGraph();
        lenght += original.arr[answer.end()[-2]][0];
        std::cout << lenght << " - długość ściezki\n";
        return ans;
    }
}