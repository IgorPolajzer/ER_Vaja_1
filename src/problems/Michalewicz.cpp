#include "Michalewicz.h"

#include <numbers>

Michalewicz::Michalewicz() {
    setName("Michalewicz");
    setLowerBound(0.0);
    setUpperBound(std::numbers::pi);
}

double Michalewicz::evaluate(const std::vector<double> & /*x_star*/) {
    return 0;
}

int Michalewicz::generateRandomSolution() {
    return 0;
}
