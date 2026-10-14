#include "Trid.h"

#include <cmath>

Trid::Trid(int d) : Problem("Trid", d, Bound(-static_cast<double>(d * d)), Bound(static_cast<double>(d * d))) {
}

double Trid::evaluate(const std::vector<double> &x_star) {
    checkDimension(x_star);

    auto firstTerm = 0.0;
    auto secondTerm = 0.0;

    for (int i = 0; i < getD(); i++) {
        auto x = x_star[i];
        checkBounds(x, i);

        firstTerm += std::pow((x - 1), 2);

        if (i >= 1) {
            auto x_minus_one = x_star[i - 1];
            checkBounds(x_minus_one, i - 1);

            secondTerm += x * x_minus_one;
        }
    }

    return firstTerm - secondTerm;
}
