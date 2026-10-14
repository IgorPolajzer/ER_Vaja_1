//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_TRID_H
#define ER_VAJA_1_TRID_H

#include "Problem.h"

class Trid : public Problem {
public:
    Trid();

    void setD(int d) override;

    double evaluate(const std::vector<double> &x_star) override;
};

#endif //ER_VAJA_1_TRID_H
