//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_MICHALEWICZ_H
#define ER_VAJA_1_MICHALEWICZ_H

#include "Problem.h"

class Michalewicz : public Problem {
public:
    Michalewicz();

    double evaluate(const std::vector<double> &x_star) override;

protected:
    int generateRandomSolution() override;
};

#endif //ER_VAJA_1_MICHALEWICZ_H
