#include "Problem.h"

#include <sstream>
#include <stdexcept>

void checkFixedDimension(int dim) {
    
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

void Problem::setDfromInput(const std::vector<double> &x_star) {
    auto upperBound = getUpperBound();
    auto lowerBound = getLowerBound();

    if (x_star.empty())
        throw std::invalid_argument("The provided input is empty.");

    checkBoundsType(lowerBound, upperBound);

    if (upperBound.isRange() && x_star.size() != upperBound.getRange().size())
        throw std::invalid_argument("The provided range bounds dont match the problem dimension.");

    setD(static_cast<int>(x_star.size()));
}
