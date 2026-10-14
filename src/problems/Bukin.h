//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_BUKIN_H
#define ER_VAJA_1_BUKIN_H

#include "Problem.h"

class Bukin : public Problem {
public:
    Bukin();

    double evaluate(const std::vector<double> &x_star) override;
};


#endif //ER_VAJA_1_BUKIN_H
