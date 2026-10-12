#pragma once

#include "Problem.h"

class Trid : public Problem {
public:
    Trid();

    void setD(int d) override;

    double evaluate(const std::vector<double> &x_star) override;

protected:
    int generateRandomSolution() override;
};
