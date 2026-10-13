#include "Ackley.h"

#include <cmath>
#include <numbers>

Ackley::Ackley() {
    setName("Ackley");
    setLowerBound(Bound(-32.768));
    setUpperBound(Bound(32.768));
}

double Ackley::evaluate(const std::vector<double> &x_star) {
    setDfromInput(x_star);

    auto a = 20;
    auto b = 0.2;
    auto c = 2 * std::numbers::pi;
    auto d = getD();

    // Iteration operations.
    auto firstSum = 0.0;
    auto secondSum = 0.0;

    for (int i = 0; i < getD(); i++) {
        auto x = x_star[i];

        checkBounds(x, i);

        firstSum += x * x;
        secondSum += std::cos(c * x);
    }

    // First Term.
    auto k = (1.0 / d) * firstSum;
    auto root = std::pow(-b, 1.0 / k);
    auto firstTerm = -a * std::exp(root);

    // Second root.
    auto secondTerm = std::exp((1.0 / d) * secondSum);

    return firstTerm - secondTerm + a + std::exp(1.0);
}

int Ackley::generateRandomSolution() {
    return 0;
}
