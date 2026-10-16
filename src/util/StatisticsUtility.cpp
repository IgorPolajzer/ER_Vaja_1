//
// Created by igor on 10/15/26.
//

#include "StatisticsUtility.h"

#include <complex>
#include <stdexcept>

Solution findBest(const std::vector<Solution> &solutions) {
    if (solutions.empty())
        throw std::invalid_argument("The provided solutions are empty");

    Solution best = solutions[0];

    for (auto s : solutions)
        if (s.getValue() < best.getValue()) best = s;

    return best;
}


double calculateAverage(const std::vector<Solution>& solutions) {
    if (solutions.empty())
        throw std::invalid_argument("The provided solutions are empty");

    double sum = 0;

    for (auto s : solutions) {
        sum += s.getValue();
    }

    return sum / solutions.size();
}

double calculateStandardDeviation(const std::vector<Solution>& solutions) {
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