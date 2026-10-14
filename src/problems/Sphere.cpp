#include "Sphere.h"

Sphere::Sphere(int d) : Problem("Sphere", d, Bound(-100.0), Bound(100.0)) {
}

double Sphere::evaluate(const std::vector<double> &x_star) {
    checkDimension(x_star);

    auto result = 0.0;

    for (int i = 0; i < getD(); i++) {
        auto x = x_star[i];

        checkBounds(x, i);

        result += x * x;
    }

    return result;
}
