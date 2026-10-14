//
// Created by igor on 10/13/26.
//

#include "CarromTable.h"

#include <cmath>
#include <numbers>
#include <stdexcept>

CarromTable::CarromTable() {
    setName("CarromTable");
    setLowerBound(Bound(std::vector{-10.0, -10.0}));
    setUpperBound(Bound(std::vector{10.0, 10.0}));
}

double CarromTable::evaluate(const std::vector<double> &x_star) {
    if (x_star.size() != 2)
        throw std::out_of_range("CarromTable specimen dimension is not 2. It should always be 2.");

    setDfromInput(x_star);

    checkBounds(x_star[0], 0);
    checkBounds(x_star[1], 1);

    auto firstTerm = -1.0 / 30.0;
    auto secondTerm = std::exp(2 * std::abs(1 - std::sqrt(std::pow(x_star[0], 2) + std::pow(x_star[1], 2)) / std::numbers::pi));
    auto thirdTerm = std::pow(std::cos(x_star[0]), 2);
    auto fourthTerm = std::pow(std::cos(x_star[1]), 2);

    return firstTerm * secondTerm * thirdTerm * fourthTerm;
}
