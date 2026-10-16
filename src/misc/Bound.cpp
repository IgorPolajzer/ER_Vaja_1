#include "Bound.h"

Bound::Bound(double number) {
    setNumber(number);
}

Bound::Bound(const std::vector<double> &range) {
    setRange(range);
}

std::variant<double, std::vector<double> > Bound::getBound() const {
    if (isRange())
        return range;

    return number;
}

bool Bound::isRange() const {
    return !range.empty();
}
