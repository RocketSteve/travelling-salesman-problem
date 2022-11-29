#ifndef TRAVELLING_SALESMAN_PROBLEM_COORDINATE_H
#define TRAVELLING_SALESMAN_PROBLEM_COORDINATE_H
#include <string>

using namespace std;

class Coordinate {
private:
    double mLatitude;
    double mLongitude;
public:
    Coordinate(double latitude, double longitude);
    double getLatitude() const;
    double getLongitude() const;
    double getDistance(Coordinate point) const;
    std::string to_string() const;

    bool operator==(const Coordinate &other) const;
};


#endif //TRAVELLING_SALESMAN_PROBLEM_COORDINATE_H
