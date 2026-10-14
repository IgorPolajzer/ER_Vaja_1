//
// Created by igor on 10/13/26.
//

#include "Bukin.h"

#include <stdexcept>
#include <cmath>

Bukin::Bukin() {
    setName("Bukin");
    setLowerBound(Bound(std::vector{-15.0, -3.0}));
    setUpperBound(Bound(std::vector{-5.0, 3.0}));
}

double Bukin::evaluate(const std::vector<double> &x_star) {
    setDfromInput(x_star);

    if (x_star.size() != 2)
        throw std::out_of_range("Bukin specimen dimension is not 2. It should always be 2.");

    auto firstTerm = 100 * std::sqrt(std::abs(x_star[1] - 0.01 * std::pow(x_star[0], 2)));
    auto secondTerm = 0.01 * std::abs(x_star[0] + 10);

    return firstTerm + secondTerm;
}
