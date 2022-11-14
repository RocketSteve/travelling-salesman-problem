#ifndef TRAVELLING_SALESMAN_PROBLEM_COORDINATESYSTEM_H
#define TRAVELLING_SALESMAN_PROBLEM_COORDINATESYSTEM_H


class CoordinateSystem {
private:
    std::vector<pair<int, int> > arr;

public:
    int V;
    CoordinateSystem(string fileName){
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
    void convert(GraphAdjacencyMatrix graph);

};

#endif //TRAVELLING_SALESMAN_PROBLEM_COORDINATESYSTEM_H
