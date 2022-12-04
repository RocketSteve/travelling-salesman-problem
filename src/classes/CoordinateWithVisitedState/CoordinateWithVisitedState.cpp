#include "CoordinateWithVisitedState.h"

CoordinateWithVisitedState::CoordinateWithVisitedState(double latitude, double longitude)
        : Coordinate(latitude, longitude) {
}

CoordinateWithVisitedState::CoordinateWithVisitedState()
        : Coordinate(0, 0) {
}

void CoordinateWithVisitedState::visitCoordinate() {
    this->visited = true;
}

bool CoordinateWithVisitedState::getVisited() const {
    return this->visited;
}
