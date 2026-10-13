#include "Schwefel26.h"

#include <cmath>

Schwefel26::Schwefel26() {
    setName("Schwefel26");
    setLowerBound(Bound(-500.0));
    setUpperBound(Bound(500.0));
}

double Schwefel26::evaluate(const std::vector<double> &x_star) {
    setDfromInput(x_star);

    auto sum = 0.0;
    for (int i = 0; i < getD(); i++) {
        auto x = x_star[i];

        checkBounds(x, i);

        sum += x * std::sin(std::sqrt(std::abs(x)));
    }

    return -sum;
}

int Schwefel26::generateRandomSolution() {
    return 0;
}
