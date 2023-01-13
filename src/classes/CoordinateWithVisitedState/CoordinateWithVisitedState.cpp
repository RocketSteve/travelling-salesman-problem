#include "CoordinateWithVisitedState.h"

CoordinateWithVisitedState::CoordinateWithVisitedState(double latitude, double longitude)
    : coordinate(latitude, longitude) {}

CoordinateWithVisitedState::CoordinateWithVisitedState() : coordinate(0, 0) {}

void CoordinateWithVisitedState::visitCoordinate() { this->visited = true; }

bool CoordinateWithVisitedState::getVisited() const { return this->visited; }
