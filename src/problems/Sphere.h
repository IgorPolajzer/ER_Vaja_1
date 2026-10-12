#pragma once

#include "Problem.h"

class Sphere : public Problem {
public:
    Sphere();

    double evaluate(const std::vector<double> &x_star) override;

protected:
    int generateRandomSolution() override;
};
