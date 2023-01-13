#ifndef TRAVELLING_SALESMAN_PROBLEM_COORDINATEWITHVISTIEDSTATE_H
#define TRAVELLING_SALESMAN_PROBLEM_COORDINATEWITHVISTIEDSTATE_H

#include "../Coordinate/Coordinate.h"
#include <string>

class CoordinateWithVisitedState {
private:
    bool visited = false;

public:
    Coordinate coordinate;
    explicit CoordinateWithVisitedState(double latitude, double longitude);
    CoordinateWithVisitedState();
    void visitCoordinate();
    bool getVisited() const;
    double getLatitude() const { return this->coordinate.getLatitude(); }
    double getLongitude() const { return this->coordinate.getLongitude(); }
    double getDistance(Coordinate point) const { return this->coordinate.getDistance(point); }
    double getDistance(CoordinateWithVisitedState point) const {
        return this->coordinate.getDistance(point.coordinate);
    }
    string to_string() const { return this->coordinate.to_string(); }
    bool operator==(const CoordinateWithVisitedState &other) const { return this->coordinate == other.coordinate; }
};


#endif//TRAVELLING_SALESMAN_PROBLEM_COORDINATEWITHVISTIEDSTATE_H
