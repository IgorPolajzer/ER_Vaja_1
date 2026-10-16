//
// Created by igor on 10/15/26.
//

#ifndef ER_VAJA_1_STATISTICSUTILITY_H
#define ER_VAJA_1_STATISTICSUTILITY_H
#include "algorithm/Solution.h"
#include "problems/Problem.h"


class StatisticsUtility {
public:
    StatisticsUtility();

    virtual ~StatisticsUtility() = default;

    void printStatistics(Problem &problem);

protected:
    Solution findBest(std::vector<Solution> solutions);

    double calculateAverage(std::vector<Solution> solutions);

    double calculateStandardDeviation(std::vector<Solution> solutions);
};


#endif //ER_VAJA_1_STATISTICSUTILITY_H
