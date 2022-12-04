#include "Coordinate.h"
#include  <ctgmath>

double Coordinate::getLatitude() const {
    return this->mLatitude;
}

double Coordinate::getLongitude() const {
    return this->mLongitude;
}

Coordinate::Coordinate(double latitude, double longitude) {
    this->mLatitude = latitude;
    this->mLongitude = longitude;
}

double Coordinate::getDistance(Coordinate point) const {
    double a = this->mLongitude - point.mLongitude;
    double b = this->mLatitude - point.mLatitude;
    double c_squared = pow(a, 2) + pow(b, 2);
    return pow(c_squared, 0.5);
}

std::string Coordinate::to_string() const {
    return "Latitude: " + std::to_string(this->mLatitude)
           + " Longitude: " + std::to_string(this->mLongitude);
}

bool Coordinate::operator==(const Coordinate &other) const {
    return this->mLongitude == other.mLongitude
           && this->mLatitude == other.mLatitude;
}

