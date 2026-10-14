//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_SOLUTION_H
#define ER_VAJA_1_SOLUTION_H

#include <vector>

class Solution {
public:
    virtual ~Solution() = default;

    double getValue() const { return this->value; }
    void setValue(const double value) { this->value = value; }

    const std::pair<double, double> &getPosition() const { return this->position; }
    void setPosition(const std::pair<double, double> &position) { this->position = position; }
private:
    std::pair<double, double> position;
    double value = 0;
};


#endif //ER_VAJA_1_SOLUTION_H
