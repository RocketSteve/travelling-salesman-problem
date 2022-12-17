#include "SimulatedAnnealingSolver.h"
#include <cmath>
#include <random>
#include <algorithm>

using namespace std;

SimulatedAnnealingSolver::SimulatedAnnealingSolver(Instance *instance, double stoppingTemperature,
                                                   float temperature, int stoppingIteration,
                                                   float alpha) {
    this->instance = instance;
    this->temperature = temperature;
    this->stoppingTemperature = stoppingTemperature;
    this->stoppingIteration = stoppingIteration;
    this->alpha = alpha;

    GreedySolver greedySolver = *new GreedySolver(*instance);
    greedySolver.solve();
    this->answer = greedySolver.answer;
    this->currentAnswer = answer;
    this->distance = greedySolver.getDistance();
    this->currentDistance = greedySolver.getDistance();
}

double SimulatedAnnealingSolver::calculateDistance(
        vector<AdjacencyList<struct CoordinateWithVisitedState> *> coordinateList) const {
    double tmpDistance = 0;
    for (int i = 0; i < coordinateList.size() - 1; i++) {
        auto currentCoordinate = coordinateList[i]->getValue();
        Coordinate nextCoordinate = coordinateList[i + 1]->getValue();
        tmpDistance += currentCoordinate.getDistance(nextCoordinate);
    }
    auto last = coordinateList[this->answer.size() - 1]->getValue();
    Coordinate first = coordinateList[0]->getValue();
    tmpDistance += last.getDistance(first);
    return tmpDistance;
}

double SimulatedAnnealingSolver::getDistance() const {
    return this->distance;
}

void SimulatedAnnealingSolver::calculateDistance() {
    this->distance = this->calculateDistance(this->answer);
}

double SimulatedAnnealingSolver::probabilityAccept(double probabilityDistance) {
    return exp(-(probabilityDistance - this->distance) / this->temperature);
}

void SimulatedAnnealingSolver::accept(vector<AdjacencyList<CoordinateWithVisitedState> *> candidate) {
    auto candidateDistance = this->calculateDistance(candidate);
    if (candidateDistance < this->currentDistance) {
        this->currentDistance = candidateDistance;
        this->currentAnswer = candidate;
        if (candidateDistance < distance) {
            this->distance = candidateDistance;
            this->answer = candidate;
        }
    } else {
        auto tmp = this->probabilityAccept(candidateDistance);
        if (SimulatedAnnealingSolver::generateRandomNumber(0.0, 1.0) < this->probabilityAccept(candidateDistance)) {
            cout << currentDistance << endl;
            this->currentDistance = candidateDistance;
            this->currentAnswer = candidate;
        }
    }
}

double SimulatedAnnealingSolver::generateRandomNumber(double from, double to) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(from, to);
    return dis(gen);
}

void SimulatedAnnealingSolver::solve() {
    int iteration = 0;
    while (this->temperature >= this->stoppingTemperature && this->stoppingIteration > iteration) {
        vector<AdjacencyList<CoordinateWithVisitedState> *> candidate;
        candidate.assign(this->currentAnswer.begin(), this->currentAnswer.end());
        auto l = (int) SimulatedAnnealingSolver::generateRandomNumber(2, this->currentAnswer.size() - 1);
        auto i = (int) SimulatedAnnealingSolver::generateRandomNumber(0.0, this->currentAnswer.size() - l);
        reverse(candidate.begin() + i, candidate.begin() + i + l);
        this->accept(candidate);
        this->newTemperature();
        iteration++;
    }
    cout << iteration << endl;
}

void SimulatedAnnealingSolver::newTemperature() {
    this->temperature = this->temperature * this->alpha;
}
