#include "RandomInstanceGenerator.h"
#include "../RandomNumberGenerator/RandomNumberGenerator.h"

RandomInstanceGenerator::RandomInstanceGenerator(int size) {
    while (this->graph->getSize() != size) {
        double latitude = RandomNumberGenerator::generate(0, 100000);
        double longitude = RandomNumberGenerator::generate(0, 100000);
        this->addVertex(CoordinateWithVisitedState(latitude, longitude));
    }
}
