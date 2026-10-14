#include "StyblinskiTang.h"

#include <cmath>

StyblinskiTang::StyblinskiTang() {
    setName("StyblinskiTang");
    setLowerBound(Bound(-5.0));
    setUpperBound(Bound(5.0));
}

double StyblinskiTang::evaluate(const std::vector<double> &x_star) {
    setDfromInput(x_star);

    auto secondTerm = 0.0;

    for (int i = 0; i < getD(); i++) {
        auto x = x_star[i];

        checkBounds(x, i);

        secondTerm += std::pow(x, 4) - 16.0 * std::pow(x, 2) + 5.0 * x;
    }

    return 0.5 * secondTerm;
}
