#include "Rosenbrock.h"

#include <cmath>

Rosenbrock::Rosenbrock() {
    setName("Rosenbrock");
    setLowerBound(-5.0);
    setUpperBound(10.0);
}

double Rosenbrock::evaluate(const std::vector<double> &x_star) {
    setDfromInput(x_star);

    auto result = 0.0;
    for (int i = 0; i < getD() - 1; i++) {
        auto x = x_star[i];
        auto x_plus_one = x_star[i + 1];

        checkBounds(x);
        checkBounds(x_plus_one);

        result += 100 * std::pow((x_plus_one - (x * x)), 2) + std::pow((x - 1), 2);
    }

    return result;
}

int Rosenbrock::generateRandomSolution() {
    return 0;
}
