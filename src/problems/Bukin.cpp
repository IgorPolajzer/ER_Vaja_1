//
// Created by igor on 10/13/26.
//

#include "Bukin.h"

#include <cmath>

Bukin::Bukin() : Problem("Bukin", 2, Bound(std::vector{-15.0, -3.0}), Bound(std::vector{-5.0, 3.0}), false) {
}

double Bukin::evaluate(const std::vector<double> &x_star) {
    checkDimension(x_star);

    auto firstTerm = 100 * std::sqrt(std::abs(x_star[1] - 0.01 * std::pow(x_star[0], 2)));
    auto secondTerm = 0.01 * std::abs(x_star[0] + 10);

    return firstTerm + secondTerm;
}
