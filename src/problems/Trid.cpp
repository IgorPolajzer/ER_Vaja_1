#include "Trid.h"

#include <cmath>

Trid::Trid() {
    setName("Trid");
}

void Trid::setD(int d) {
    Problem::setD(d);
    setLowerBound(-(d * d));
    setUpperBound(d * d);
}

double Trid::evaluate(const std::vector<double> &x_star) {
    setDfromInput(x_star);

    auto firstTerm = 0.0;
    auto secondTerm = 0.0;

    for (int i = 0; i < getD(); i++) {
        auto x = x_star[i];
        checkBounds(x);

        firstTerm += std::pow((x - 1), 2);

        if (i >= 1) {
            auto x_minus_one = x_star[i - 1];
            checkBounds(x_minus_one);

            secondTerm += x * x_minus_one;
        }
    }

    return firstTerm - secondTerm;
}

int Trid::generateRandomSolution() {
    return 0;
}
