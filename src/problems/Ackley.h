#pragma once

#include "Problem.h"

class Ackley : public Problem {
public:
    Ackley();

    double evaluate(const std::vector<double> &x_star) override;

protected:
    int generateRandomSolution() override;
};
