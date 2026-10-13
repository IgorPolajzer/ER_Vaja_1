//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_RASTRIGIN_H
#define ER_VAJA_1_RASTRIGIN_H

#include "Problem.h"

class Rastrigin : public Problem {
public:
    Rastrigin();

    double evaluate(const std::vector<double> &x_star) override;

protected:
    int generateRandomSolution() override;
};

#endif //ER_VAJA_1_RASTRIGIN_H
