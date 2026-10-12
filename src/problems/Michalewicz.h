#pragma once

#include "Problem.h"

class Michalewicz : public Problem {
public:
    Michalewicz();

    double evaluate(const std::vector<double> &x_star) override;

protected:
    int generateRandomSolution() override;
};
