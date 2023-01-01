#include "SimulatedAnnealingSolver.h"
#include "../RandomNumberGenerator/RandomNumberGenerator.h"
#include <algorithm>
#include <cmath>

SimulatedAnnealingSolver::SimulatedAnnealingSolver(Instance *instance, double stoppingTemperature,
                                                   int stoppingIteration, float alpha) {
    this->stoppingTemperature = stoppingTemperature;
    this->stoppingIteration = stoppingIteration;
    this->alpha = alpha;
    this->instance = *instance;
    this->temperature = 1 / (double) this->instance.graph->getSize();
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

double SimulatedAnnealingSolver::getDistance() const { return this->distance; }

void SimulatedAnnealingSolver::calculateDistance() { this->distance = this->calculateDistance(this->answer); }

double SimulatedAnnealingSolver::probabilityAccept(double probabilityDistance) const {
    return exp(-(probabilityDistance - this->currentDistance) / this->temperature);
}

void SimulatedAnnealingSolver::accept(const vector<AdjacencyList<CoordinateWithVisitedState> *> &candidate) {
    auto candidateDistance = this->calculateDistance(candidate);
    if (candidateDistance < this->currentDistance) {
        this->currentDistance = candidateDistance;
        this->currentAnswer = candidate;
        if (candidateDistance < distance) {
            this->distance = candidateDistance;
            this->answer = candidate;
        }
    } else {
        if (RandomNumberGenerator::generate(0.0, 1.0) < this->probabilityAccept(candidateDistance)) {
            this->currentDistance = candidateDistance;
            this->currentAnswer = candidate;
        }
    }
}

void SimulatedAnnealingSolver::solve() {
    this->greedySolve();
    this->temperature = this->distance * this->temperature;
    int iteration = 0;
    while (this->temperature >= this->stoppingTemperature && this->stoppingIteration > iteration) {
        vector<AdjacencyList<CoordinateWithVisitedState> *> candidate;
        candidate.assign(this->currentAnswer.begin(), this->currentAnswer.end());
        auto l = (int) RandomNumberGenerator::generate(2, (double) this->currentAnswer.size() - 1);
        auto i = (int) RandomNumberGenerator::generate(1, (double) this->currentAnswer.size() - l);
        reverse(candidate.begin() + i, candidate.begin() + i + l);
        this->accept(candidate);
        this->newTemperature();
        iteration++;
    }
}

void SimulatedAnnealingSolver::newTemperature() { this->temperature = this->temperature * this->alpha; }

void SimulatedAnnealingSolver::greedySolve() {
    if (this->answer.empty()) {
        GreedySolver greedySolver = *new GreedySolver(this->instance);
        greedySolver.solve();
        this->answer = greedySolver.answer;
        this->currentAnswer = answer;
        this->distance = greedySolver.getDistance();
        this->currentDistance = greedySolver.getDistance();
    }
}