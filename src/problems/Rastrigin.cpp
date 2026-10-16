#include "Rastrigin.h"

#include <cmath>
#include <numbers>

Rastrigin::Rastrigin(int d) : Problem("Rastrigin", d, Bound(-5.12), Bound(5.12), true) {
}

double Rastrigin::evaluate(const std::vector<double> &x_star) {
    checkDimension(x_star);

    auto sum = 0.0;

    for (int i = 0; i < getD(); i++) {
        auto x = x_star[i];

        checkBounds(x, i);

        sum += x * x - 10 * std::cos(2 * std::numbers::pi * x);
    }

    return 10 * getD() + sum;
}
