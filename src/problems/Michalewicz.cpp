#include "Michalewicz.h"

#include <cmath>
#include <numbers>

Michalewicz::Michalewicz(int d) : Problem("Michalewicz", d, Bound(0.0), Bound(std::numbers::pi)) {
}

double Michalewicz::evaluate(const std::vector<double> & x_star) {
    checkDimension(x_star);

    auto m = 10;
    auto sum = 0.0;

    for (int i = 0; i < getD(); i++) {
        auto x = x_star[i];
        checkBounds(x, i);

        sum += std::sin(x) * std::pow(std::sin(((i + 1) * std::pow(x, 2)) / std::numbers::pi), 2 * m);
    }

    return - sum;
}
