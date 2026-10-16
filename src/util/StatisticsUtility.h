//
// Created by igor on 10/15/26.
//

#ifndef ER_VAJA_1_STATISTICSUTILITY_H
#define ER_VAJA_1_STATISTICSUTILITY_H

#include <vector>
#include "algorithm/Solution.h"
#include "problems/Problem.h"

namespace StatisticsUtility {
    void printStatistics(const std::vector<Solution> &solutions, const Problem &problem);

    Solution findBest(const std::vector<Solution> &solutions);

    double calculateAverage(const std::vector<Solution> &solutions);

    double calculateStandardDeviation(const std::vector<Solution> &solutions);
}

#endif //ER_VAJA_1_STATISTICSUTILITY_H
