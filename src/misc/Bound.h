#pragma once

#include <variant>
#include <vector>

class Bound {
public:
    explicit Bound(double number);

    explicit Bound(const std::vector<double> &range);

    std::variant<double, std::vector<double> > getBound() const;

    bool isRange() const;

    double getNumber() const { return number; }
    void setNumber(double number) { this->number = number; }

    const std::vector<double> &getRange() const { return range; }
    void setRange(const std::vector<double> &range) { this->range = range; }

private:
    double number = 0.0;
    std::vector<double> range;
};
