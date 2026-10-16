//
// Created by igor on 10/15/26.
//

#include "StatisticsUtility.h"

#include <complex>
#include <iostream>
#include <stdexcept>

Solution StatisticsUtility::findBest(const std::vector<Solution> &solutions) {
    if (solutions.empty())
        throw std::invalid_argument("The provided solutions are empty");

    Solution best = solutions[0];

    for (auto s : solutions)
        if (s.getValue() < best.getValue()) best = s;

    return best;
}


double StatisticsUtility::calculateAverage(const std::vector<Solution> &solutions) {
    if (solutions.empty())
        throw std::invalid_argument("The provided solutions are empty");

    double sum = 0;

    for (auto s : solutions) {
        sum += s.getValue();
    }

    return sum / solutions.size();
}

double StatisticsUtility::calculateStandardDeviation(const std::vector<Solution>& solutions) {
    if (solutions.empty())
        throw std::invalid_argument("The provided solutions are empty");

    double mean = calculateAverage(solutions);
    double sum = 0.0;

    for (const auto& s : solutions) {
        // Subtract the mean.
        double newValue= s.getValue() - mean;
        sum += std::pow(newValue, 2);
    }

    return std::sqrt(sum / solutions.size());
}

void StatisticsUtility::printStatistics(std::vector<Solution>& solutions) {
    auto best = findBest(solutions);
    auto average = calculateAverage(solutions);
    auto stdDev = calculateStandardDeviation(solutions);

    std::cout << "Statistics for " + std::to_string(solutions.size()) + " solutions" << std::endl;
    std::cout << "Best solution: " << best.getValue() << std::endl;
    std::cout << "Average solution: " << average << std::endl;
    std::cout << "Standard deviation: " << stdDev << std::endl;
}