#ifndef TRAVELLING_SALESMAN_PROBLEM_INSTANCEFILEREADER_H
#define TRAVELLING_SALESMAN_PROBLEM_INSTANCEFILEREADER_H

#include "../Instance/Instance.h"
#include <fstream>
#include <iostream>
#include <string>

using std::string;

class InstanceFileReader : public Instance {
private:
    void addVertexByLine(const string &line) const;

public:
    explicit InstanceFileReader(const string &filename);
};


#endif//TRAVELLING_SALESMAN_PROBLEM_INSTANCEFILEREADER_H
