#include "InstanceFileReader.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <utility>
#include <vector>

using std::cout;
using std::ifstream;
using std::pair;
using std::pair;
using std::vector;
using std::endl;

pair<string, string> split(const string &s, const string &delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    return make_pair(token, s.substr(pos_start));
}

InstanceFileReader::InstanceFileReader(const string &filename) : Instance() {
    ifstream file;
    file.open(filename);
    string line;
    int size = 0;
    bool first = true;
    if (file.is_open()) {
        while (true) {
            getline(file, line);
            if (first) {
                size = stoi(line);
                first = false;
            } else if (!line.empty()) {
                addVertexByLine(line);
            }
            if (file.eof()) break;
        }
    }
    this->connectAllPoints();
    try {
        if (this->graph->getSize() != size) { throw size; }
    } catch (int size) { cout << "BadInstanceFileOrReadFileError: size of instance is different" << endl; }
}

void InstanceFileReader::addVertexByLine(const string &line) const {
    auto divideLine = split(line, " ");
    double latitude = stod(divideLine.first);
    double longitude = stod(divideLine.second);
    this->addVertex(CoordinateWithVisitedState(latitude, longitude));
}
