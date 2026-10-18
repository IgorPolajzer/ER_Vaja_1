#include "Problem.h"

#include <random>
#include <sstream>
#include <stdexcept>

Problem::Problem(const std::string& name, int d, const Bound& lowerBound, const Bound& upperBound, bool scalable)
    : name(name), d(d), scalable(scalable), lowerBound(lowerBound), upperBound(upperBound) {
    if (d <= 0)
        throw std::invalid_argument("The problem dimension must be positive.");

    checkBoundsType(this->lowerBound, this->upperBound);

    if (scalable && this->upperBound.isRange())
        throw std::invalid_argument("A scalable problem cannot have per-index range bounds.");

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

Solution Problem::generateRandomSolution() {
    std::vector<double> position;
    auto upperBound = getUpperBound();
    auto lowerBound = getLowerBound();

    checkBoundsType(lowerBound, upperBound);

    for (int i = 0; i < getD(); i++) {
        double lower, upper;

        if (lowerBound.isRange() && upperBound.isRange()) {
            lower = lowerBound.getRange()[i];
            upper = upperBound.getRange()[i];
        } else {
            lower = lowerBound.getNumber();
            upper = upperBound.getNumber();
        }

        // Generate a random number in lower and upper range.
        static std::mt19937 re(std::random_device{}());
        std::uniform_real_distribution unif(lower, upper);
        double solution = unif(re);

        position.push_back(solution);
    }

    return Solution(position);
}
