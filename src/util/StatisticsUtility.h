//
// Created by igor on 10/15/26.
//

#ifndef ER_VAJA_1_STATISTICSUTILITY_H
#define ER_VAJA_1_STATISTICSUTILITY_H
#include "algorithm/Solution.h"
#include "problems/Problem.h"


class StatisticsUtility {
public:
    virtual ~StatisticsUtility() = default;

    void printStatistics(std::vector<Solution> &solutions);
protected:
    Solution findBest(const std::vector<Solution> &solutions);

    double calculateAverage(const std::vector<Solution> &solutions);

    double calculateStandardDeviation(const std::vector<Solution> &solutions);
};


#endif //ER_VAJA_1_STATISTICSUTILITY_H
