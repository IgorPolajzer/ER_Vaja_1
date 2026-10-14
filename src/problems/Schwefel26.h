//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_SCHWEFEL26_H
#define ER_VAJA_1_SCHWEFEL26_H

#include "Problem.h"

class Schwefel26 : public Problem {
public:
    explicit Schwefel26(int d);

    double evaluate(const std::vector<double> &x_star) override;
};

#endif //ER_VAJA_1_SCHWEFEL26_H
