#pragma once

#include "Problem.h"

class Rastrigin : public Problem {
public:
    Rastrigin();

    double evaluate(const std::vector<double> &x_star) override;

protected:
    int generateRandomSolution() override;
};
