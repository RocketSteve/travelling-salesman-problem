#include "RandomInstanceGenerator.h"
#include "../RandomNumberGenerator/RandomNumberGenerator.h"

RandomInstanceGenerator::RandomInstanceGenerator(int size) {
    while (this->graph->getSize() != size) {
        double latitude = RandomNumberGenerator::generete(0, 100000);
        double longitude = RandomNumberGenerator::generete(0, 100000);
        this->addVertex(CoordinateWithVisitedState(latitude, longitude));
    }
}
