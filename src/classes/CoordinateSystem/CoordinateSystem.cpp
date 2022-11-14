#include "CoordinateSystem.h"

void CoordinateSystem::print(){
    for (int i = 0; i < V; i++){
        std::cout << arr[i].first << ", " << arr[i].second << " - " << i << '\n';
    }
}

// Taking coordinates form coordinate system, calculates distance between them and puts it to the adjecency matrix
void CoordinateSystem::convert(GraphAdjacencyMatrix graph){
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (i == j){
                graph.addEdge(i, j, 0);
            } else {
                double dist = calculateDistance(arr[i].first, arr[i].second, arr[j].first, arr[j].second);
                graph.addEdge(i, j, dist);
                //std::cout << dist << "\n";
            }
        }
    }
}


//
//double calculateDistance(int x, int y, int n, int m){
//    double dist = sqrt(pow(n - x, 2) + pow(m - y, 2));
//    return dist;
//}