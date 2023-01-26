#include "RandomNumberGenerator.h"

using std::mt19937;
using std::random_device;
using std::uniform_real_distribution;

double RandomNumberGenerator::generate(double from, double to) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(from, to);
    return dis(gen);
}
