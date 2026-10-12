#pragma once

#include "Problem.h"

class Schwefel26 : public Problem {
public:
    Schwefel26();

    double evaluate(const std::vector<double> &x_star) override;

protected:
    int generateRandomSolution() override;
};
