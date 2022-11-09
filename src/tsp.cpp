#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <random>
#include <time.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


// Graph represented by adjecency matrix with weighted paths
class adjMatrix {
    public:
    int v;
    int* visit;
    double** arr;
    std::vector<int> answer;

    // Init function
    adjMatrix(int x){
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


    adjMatrix travellingSalesman_recursive(int start, adjMatrix ans, double path, adjMatrix original);
    adjMatrix travellingSalesman_start(int start, adjMatrix original);
};


// Index 0,0 gives the total lenght of choosen path
// Naive approach by going to the next clostest node 
adjMatrix adjMatrix::travellingSalesman_start(int start, adjMatrix original){
    adjMatrix ans(v);
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

adjMatrix adjMatrix::travellingSalesman_recursive(int start, adjMatrix ans, double lenght, adjMatrix original){

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

double calculateDistance(int x, int y, int n, int m);


// Taking input file and transferring it to array of pairs to calculate distances between points
// TODO: have a option to choose if program generates random instance of the problem or take the input from file
class coordSystem {
    private:
    std::vector<pair<int, int> > arr;

    public:
    int V;
    coordSystem(string fileName){
        ifstream instance;
        instance.open(fileName);
        // read number of verticies 
        string line;
        getline(instance, line);
        V = stoi(line);
        // read file line by line
        int counter = 0;
        int tempx, tempy;
        while(getline(instance, line)){
            std::stringstream ss(line);
            // separate lines by space characters and add them to the coordinate system vector
            while(getline(ss, line, ' ')){
                if (counter % 2 == 0){
                tempx = stoi(line);
                //std::cout << counter << " - " << line << "\n";
                }
                else {
                    tempy = stoi(line);
                    arr.push_back(make_pair(tempx, tempy));
                }
                counter++;
            }
        }
        instance.close();
    }

    void print();
    void convert(adjMatrix graph);

};

void coordSystem::print(){
    for (int i = 0; i < V; i++){
        std::cout << arr[i].first << ", " << arr[i].second << " - " << i << '\n';
    }
}

// Taking coordinates form coordinate system, calculates distance between them and puts it to the adjecency matrix
void coordSystem::convert(adjMatrix graph){
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

double calculateDistance(int x, int y, int n, int m){
    double dist = sqrt(pow(n - x, 2) + pow(m - y, 2));
    return dist;
}

void randomInstanceGenerator(int V, int top){
    srand(time(NULL));
    ofstream randInstance("random.txt");

    randInstance << V << "\n";
    for (int i = 0; i < V; i++){
        randInstance << rand() % (1 + top) << ' ' << rand() % (1 + top) << "\n";
    }

    randInstance.close();
}



int main(){
    string filename = "random.txt";

    //randomInstanceGenerator(4, 10);
    
    coordSystem test(filename);


    adjMatrix graph(test.V);
    adjMatrix graphCopy(test.V);

    test.convert(graph);
    test.convert(graphCopy);

    auto start = high_resolution_clock::now();

    adjMatrix ans = graph.travellingSalesman_start(0, graphCopy);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
 
    std::cout << duration.count() << "µs - czas wykonania algorytmu zachłannego\n";

    graph.printAns();
    
    return 0;
}