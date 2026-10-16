//
// Created by igor on 10/13/26.
//

#include "RandomSearch.h"

Solution RandomSearch::execute(Problem &problem, int maxFes) {
    Solution bestSolution;
    int fes = 0;

    while(fes <= maxFes) {
        auto solution = problem.generateRandomSolution();
        auto fitness = problem.evaluate(solution);

        if (fes == 0 || fitness < bestSolution.getValue())
            bestSolution = solution;

        fes++;
    }

    return bestSolution;
}