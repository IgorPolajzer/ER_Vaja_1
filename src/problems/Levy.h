#pragma once

#include "Problem.h"

class Levy : public Problem {
public:
    Levy();

    double evaluate(const std::vector<double> &x_star) override;

protected:
    int generateRandomSolution() override;
};
