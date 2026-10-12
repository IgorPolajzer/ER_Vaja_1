#pragma once

#include "Problem.h"

class Griewank : public Problem {
public:
    Griewank();

    double evaluate(const std::vector<double> &x_star) override;

protected:
    int generateRandomSolution() override;
};
