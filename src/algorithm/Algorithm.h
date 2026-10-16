//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_ALGORITHM_H
#define ER_VAJA_1_ALGORITHM_H
#include "Solution.h"
#include "problems/Problem.h"


class Algorithm {
public:
    virtual ~Algorithm() = default;

    virtual Solution execute(Problem* problem, int maxFes) = 0;
};


#endif //ER_VAJA_1_ALGORITHM_H
