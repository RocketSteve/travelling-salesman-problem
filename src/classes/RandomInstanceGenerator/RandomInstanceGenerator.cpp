#include "RandomInstanceGenerator.h"

RandomInstanceGenerator::RandomInstanceGenerator(int size) {
    while (this->graph->getSize() != size) {
        double latitude = rand() % 100000;
        double longitude = rand() % 100000;
        this->addVertex(CoordinateWithVisitedState(latitude, longitude));
    }
}
