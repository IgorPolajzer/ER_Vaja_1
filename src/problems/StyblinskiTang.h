#pragma once

#include "Problem.h"

class StyblinskiTang : public Problem {
public:
    StyblinskiTang();

    double evaluate(const std::vector<double> &x_star) override;

protected:
    int generateRandomSolution() override;
};
