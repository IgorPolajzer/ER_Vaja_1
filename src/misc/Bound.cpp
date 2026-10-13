#include "Bound.h"

Bound::Bound(double number) {
    setNumber(number);
}

Bound::Bound(const std::vector<double> &range) {
    setRange(range);
}

std::variant<double, std::vector<double> > Bound::getBound() const {
    if (isRange())
        return number;

    return range;
}

bool Bound::isRange() const {
    if (range.empty())
        return false;

    return true;
}
