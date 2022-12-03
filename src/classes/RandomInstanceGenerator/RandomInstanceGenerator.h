#ifndef TRAVELLING_SALESMAN_PROBLEM_RANDOMINSTANCEGENERATOR_H
#define TRAVELLING_SALESMAN_PROBLEM_RANDOMINSTANCEGENERATOR_H

#include "../Instance/Instance.h"

class RandomInstanceGenerator : public Instance {
public:
    explicit RandomInstanceGenerator(int size);
};


#endif //TRAVELLING_SALESMAN_PROBLEM_RANDOMINSTANCEGENERATOR_H
