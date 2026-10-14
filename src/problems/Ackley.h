//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_ACKLEY_H
#define ER_VAJA_1_ACKLEY_H

#include "Problem.h"

class Ackley : public Problem {
public:
    Ackley();

    double evaluate(const std::vector<double> &x_star) override;
};

#endif //ER_VAJA_1_ACKLEY_H
