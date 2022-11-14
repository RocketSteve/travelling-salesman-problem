#ifndef TRAVELLING_SALESMAN_PROBLEM_GRAPHADJACENCYMATRIX_H
#define TRAVELLING_SALESMAN_PROBLEM_GRAPHADJACENCYMATRIX_H


class GraphAdjacencyMatrix {
public:
    int v;
    int* visit;
    double** arr;
    std::vector<int> answer;

    // Init function
    GraphAdjacencyMatrix(int x){
        answer.push_back(0);
        v = x;
        arr = new double*[x];
        for (int i = 0; i < x; i++){
            arr[i] = new double[x];
            visit = new int[x];
        }
        for (int i = 0; i < x; i++){
            visit[i] = 0;
        }
    }

    void addEdge(int x, int y, double weight){
        if (weight != 0){
            arr[x][y] = weight;
        }
    }

    void delEdge(int x){
        for (int i = 0; i < this->v; i ++){
            arr[x][i] = 0;
            arr[i][x] = 0;
        }
    }

    void visited(int x){
        visit[x] = 1;
    }

    void printGraph(){
        int v = this->v;
        for (int i = 0; i < v; i++){
            for (int j = 0; j < v; j++){
                cout.precision(3);
                std::cout << arr[i][j] << ' ';
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void printAns(){
        int v = this->v + 1;
        for (int i = 0; i < v; i++){
            std::cout << this->answer[i] << "-";
        }
        std::cout << " poszukiwany cykl hamiltona\n";
    }


    GraphAdjacencyMatrix travellingSalesman_recursive(int start, GraphAdjacencyMatrix ans, double path, GraphAdjacencyMatrix original);
    GraphAdjacencyMatrix travellingSalesman_start(int start, GraphAdjacencyMatrix original);
};


#endif //TRAVELLING_SALESMAN_PROBLEM__GRAPHADJACENCYMATRIX_H
