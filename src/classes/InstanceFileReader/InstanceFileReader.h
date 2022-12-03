#ifndef TRAVELLING_SALESMAN_PROBLEM_INSTANCEFILEREADER_H
#define TRAVELLING_SALESMAN_PROBLEM_INSTANCEFILEREADER_H

#include <string>
#include <iostream>
#include <fstream>
#include "../Instance/Instance.h"
#include "../Instance/Instance.cpp"

using namespace std;

class InstanceFileReader : public Instance {
private:
    ifstream file;

    void addVertexByLine(string line) const;

public:
    explicit InstanceFileReader(const string &filename);
};


#endif //TRAVELLING_SALESMAN_PROBLEM_INSTANCEFILEREADER_H
