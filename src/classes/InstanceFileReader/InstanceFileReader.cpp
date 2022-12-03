#include <vector>
#include "InstanceFileReader.h"
#include <iostream>
#include <string>
#include <unistd.h>

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
    system("pwd");
    this->file.open(filename);
    string line;
    char buffer[200];
    getcwd(buffer, sizeof(buffer));
    string s(buffer);
    int size = 0;
    bool first = true;
    if (file.is_open()) {
        while (file) {
            getline(file, line);
            if (first) {
                size = stoi(line);
                first = false;
            } else if (!line.empty())
                addVertexByLine(line);
        }
    }
    this->connectAllPoints();
    try {
        if (this->graph->getSize() != size) {
            throw size;
        }
    } catch (int size) {
        cout << "BadInstanceFileOrReadFileError: size of instance is different" << endl;
    }
}

void InstanceFileReader::addVertexByLine(string line) const {
    auto divideLine = split(line, " ");
    double latitude = stod(divideLine.first);
    double longitude = stod(divideLine.second);
    this->addVertex(CoordinateWithVisitedState(latitude, longitude));
}

