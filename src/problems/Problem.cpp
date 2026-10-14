#include "Problem.h"

#include <random>
#include <sstream>
#include <stdexcept>
#include <utility>

Problem::Problem(std::string name, int d, Bound lowerBound, Bound upperBound)
    : name(std::move(name)), d(d), lowerBound(std::move(lowerBound)), upperBound(std::move(upperBound)) {
    if (d <= 0)
        throw std::invalid_argument("The problem dimension must be positive.");

    checkBoundsType(this->lowerBound, this->upperBound);

    if (this->upperBound.isRange() && this->upperBound.getRange().size() != d)
        throw std::invalid_argument("The provided range bounds dont match the problem dimension.");
}

void Problem::checkBoundsType(const Bound &lowerBound, const Bound &upperBound) {
    if (upperBound.isRange() != lowerBound.isRange())
        throw std::invalid_argument("The provided bounds are not of the same type.");

    if (upperBound.isRange() && upperBound.getRange().size() != lowerBound.getRange().size())
        throw std::invalid_argument("The provided bounds are not the same size.");
}

void Problem::checkBounds(double x, int index) const {
    auto upperBound = getUpperBound();
    auto lowerBound = getLowerBound();

    checkBoundsType(lowerBound, upperBound);

    double upper;
    double lower;

    if (upperBound.isRange()) {
        if (index < 0 || index >= upperBound.getRange().size())
            throw std::out_of_range("The provided index is outside of the range bounds.");

        upper = upperBound.getRange()[index];
        lower = lowerBound.getRange()[index];
    } else {
        upper = upperBound.getNumber();
        lower = lowerBound.getNumber();
    }

    if (x > upper || x < lower) {
        std::ostringstream msg;
        msg << "[" << getName() << "]" << "Specimen entry is out of bounds. "
                << "X:" << x << "; Index:" << index << "; Upper bound:" << upper << "; Lower bound:" << lower << ".";
        throw std::out_of_range(msg.str());
    }
}

void Problem::checkDimension(const std::vector<double> &x_star) const {
    if (x_star.size() != getD()) {
        std::ostringstream msg;
        msg << "[" << getName() << "]" << "Specimen dimension does not match the problem dimension. "
                << "Specimen:" << x_star.size() << "; Problem:" << getD() << ".";
        throw std::invalid_argument(msg.str());
    }
}

Solution Problem::generateRandomSolution(int maxFes) {
    auto upperBound = getUpperBound();
    auto lowerBound = getLowerBound();



    return Solution();
}
