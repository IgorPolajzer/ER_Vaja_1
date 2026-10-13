//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_STYBLINSKITANG_H
#define ER_VAJA_1_STYBLINSKITANG_H

#include "Problem.h"

class StyblinskiTang : public Problem {
public:
    StyblinskiTang();

    double evaluate(const std::vector<double> &x_star) override;

protected:
    int generateRandomSolution() override;
};

#endif //ER_VAJA_1_STYBLINSKITANG_H
