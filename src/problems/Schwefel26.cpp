#include "Schwefel26.h"

#include <cmath>

Schwefel26::Schwefel26(int d) : Problem("Schwefel26", d, Bound(-500.0), Bound(500.0), true) {
}

double Schwefel26::evaluate(const std::vector<double> &x_star) {
    checkDimension(x_star);

    auto sum = 0.0;
    for (int i = 0; i < getD(); i++) {
        auto x = x_star[i];

        checkBounds(x, i);

        sum += x * std::sin(std::sqrt(std::abs(x)));
    }

    return -sum;
}
