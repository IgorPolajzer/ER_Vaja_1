//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_RANDOMSEARCH_H
#define ER_VAJA_1_RANDOMSEARCH_H
#include "Algorithm.h"


class RandomSearch : public Algorithm {
public:
    ~RandomSearch() override = default;

    Solution execute(Problem* problem, int maxFes) override;
};


#endif //ER_VAJA_1_RANDOMSEARCH_H
