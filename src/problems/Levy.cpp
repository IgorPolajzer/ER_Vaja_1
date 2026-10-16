#include "Levy.h"

#include <cmath>
#include <numbers>

Levy::Levy(int d) : Problem("Levy", d, Bound(-10.0), Bound(10.0), true) {
}

double Levy::evaluate(const std::vector<double> &x_star) {
    checkDimension(x_star);

    std::vector<double> omegaList;
    auto secondTerm = 0.0;

    // Init omegas.
    for (int i = 0; i < getD(); i++) {
        auto x = x_star[i];
        checkBounds(x, i);

        auto omega = 1 + (x - 1) / 4;
        omegaList.push_back(omega);
    }

    // Second Term.
    for (int i = 0; i < getD() - 1; i++) {
        auto x = x_star[i];
        auto omega = omegaList[i];
        auto omegaD = omegaList.back();
        checkBounds(x, i);

        secondTerm += std::pow((omega - 1), 2) * (1 + 10 * std::pow(std::sin(std::numbers::pi * omega + 1), 2));
        secondTerm += std::pow((omegaD - 1), 2) * (1 + std::pow(std::sin(2 * std::numbers::pi * omegaD), 2));
    }

    auto firstTerm = std::pow(std::sin(std::numbers::pi * omegaList.front()), 2);

    return firstTerm + secondTerm;
}
