#include "RandomNumberGenerator.h"

using namespace std;

double RandomNumberGenerator::generete(double from, double to) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(from, to);
    return dis(gen);
}