#pragma once

#include "Problem.h"

class Rosenbrock : public Problem {
public:
    Rosenbrock();

    double evaluate(const std::vector<double> &x_star) override;

protected:
    int generateRandomSolution() override;
};
