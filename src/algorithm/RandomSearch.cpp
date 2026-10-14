//
// Created by igor on 10/13/26.
//

#include "RandomSearch.h"


Solution execute(Problem &problem, int maxFes) {
    Solution bestSolution;
    int fes = 0;

    while(maxFes > fes) {
        auto solution = problem.generateRandomSolution(maxFes);

        if (solution.getValue() >= bestSolution.getValue())
            bestSolution = solution;

        fes++;
    }

    return bestSolution;
}