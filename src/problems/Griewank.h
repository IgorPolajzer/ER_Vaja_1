//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_GRIEWANK_H
#define ER_VAJA_1_GRIEWANK_H

#include "Problem.h"

class Griewank : public Problem {
public:
    Griewank();

    double evaluate(const std::vector<double> &x_star) override;
};

#endif //ER_VAJA_1_GRIEWANK_H
