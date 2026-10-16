//
// Created by igor on 10/16/26.
//

#include "Runner.h"

#include <iomanip>
#include <iostream>

#include "util/StatisticsUtility.h"

namespace Runner {
    static constexpr int DEFAULT_RUN_COUNT = 100;
    static constexpr int DEFAULT_MAXFES_FACTOR = 3000;

    void execute(const std::vector<Problem*> &problems, Algorithm &algorithm) {

        std::cout << "Solving " + std::to_string(problems.size()) << " problems on the provided algorithm." << std::endl;
        std::cout << "------------------------------" << std::endl;

        for (auto problem : problems) {
            std::vector<Solution> solutions;
            std::cout << "Solving " << problem->getD() << " dim " << problem->getName() << ".\nSolutions (" << DEFAULT_RUN_COUNT << " iterations): ";

            for (int i = 0; i < DEFAULT_RUN_COUNT; i++) {
                auto solution = algorithm.execute(problem, DEFAULT_MAXFES_FACTOR * problem->getD());
                solutions.push_back(solution);

                std::cout << "i=" << i + 1 << ": " << solution.getValue() << "; ";
            }
            std::cout << std::endl;
            StatisticsUtility::printStatistics(solutions, *problem);
            std::cout << std::endl;
        }
    }
}
