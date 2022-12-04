#include "RandomInstanceGenerator.h"
#include "../../../src/classes/Instance/Instance.h"
#include "../../../src/classes/Instance/Instance.cpp"

RandomInstanceGenerator::RandomInstanceGenerator(int size) {
    while (this->graph->getSize() != size) {
        double latitude = rand() % 100000;
        double longitude = rand() % 100000;
        this->addVertex(CoordinateWithVisitedState(latitude, longitude));
    }
}
