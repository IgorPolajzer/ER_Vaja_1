#include "Problem.h"

#include <sstream>
#include <stdexcept>

void Problem::checkBounds(double x) const {
    if (x > getUpperBound() || x < getLowerBound()) {
        std::ostringstream msg;
        msg << "[" << getName() << "]" << "Specimen entry is out of bounds. "
                << "X:" << x << "; Upper bound:" << getUpperBound() << "; Lower bound:" << getLowerBound() << ".";
        throw std::out_of_range(msg.str());
    }
}

void Problem::setDfromInput(const std::vector<double> &x_star) {
    if (x_star.empty())
        throw std::invalid_argument("The provided input is empty.");

    setD(static_cast<int>(x_star.size()));
}
