#include "Sphere.h"

Sphere::Sphere() {
    setName("Sphere");
    setLowerBound(-100.0);
    setUpperBound(100.0);
}

double Sphere::evaluate(const std::vector<double> &x_star) {
    setDfromInput(x_star);

    auto result = 0.0;

    for (int i = 0; i < getD(); i++) {
        auto x = x_star[i];

        checkBounds(x);

        result += x * x;
    }

    return result;
}

int Sphere::generateRandomSolution() {
    return 0;
}
