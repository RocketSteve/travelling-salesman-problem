#ifndef TRAVELLING_SALESMAN_PROBLEM_COORDINATE_H
#define TRAVELLING_SALESMAN_PROBLEM_COORDINATE_H
#include <string>

class Coordinate {
private:
    double mLatitude;
    double mLongitude;
public:
    Coordinate(double latitude, double longitude);
    double getLatitude();
    double getLongitude();
    double getDistance(Coordinate point);
    std::string to_string() const;
};


#endif //TRAVELLING_SALESMAN_PROBLEM_COORDINATE_H
