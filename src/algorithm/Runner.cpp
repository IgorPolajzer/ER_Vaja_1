//
// Created by igor on 10/16/26.
//

#include "Runner.h"

#include "util/StatisticsUtility.h"

namespace Runner {
    static constexpr int DEFAULT_RUN_COUNT = 100;
    static constexpr int DEFAULT_MAXFES_FACTOR = 3000;

    void execute(const std::vector<Problem*> &problems, Algorithm &algorithm) {
        std::vector<Solution> solutions;

        for (auto problem : problems) {
            // TODO run 100 times.
            auto solution = algorithm.execute(problem, DEFAULT_MAXFES_FACTOR * problem->getD());
            solutions.push_back(solution);
        }

        StatisticsUtility::printStatistics(solutions);
    }
}
