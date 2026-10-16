//
// Created by igor on 10/13/26.
//

#include "RandomSearch.h"

Solution RandomSearch::execute(Problem* problem, int maxFes) {
    // First evaluation.
    auto bestSolution = problem->generateRandomSolution();
    problem->evaluateSolution(bestSolution);

    for (int fes = 1; fes < maxFes; fes++) {
        auto solution = problem->generateRandomSolution();

        if (problem->evaluateSolution(solution) < bestSolution.getValue())
            bestSolution = solution;
    }

    return bestSolution;
}