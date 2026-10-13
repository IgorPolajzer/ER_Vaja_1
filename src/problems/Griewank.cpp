#include "Griewank.h"

#include <cmath>

Griewank::Griewank() {
    setName("Griewank");
    setLowerBound(Bound(-600.0));
    setUpperBound(Bound(600.0));
}

double Griewank::evaluate(const std::vector<double> &x_star) {
    setDfromInput(x_star);

    auto firstTerm = 0.0;
    auto secondTerm = 0.0;
    for (int i = 0; i < getD(); i++) {
        auto x = x_star[i];

        checkBounds(x, i);

        firstTerm += ((x * x) / 4000);
        secondTerm *= std::cos(x / std::sqrt(i + 1)) + 1;
    }

    return firstTerm - secondTerm;
}

int Griewank::generateRandomSolution() {
    return 0;
}
