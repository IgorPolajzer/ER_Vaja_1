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

    std::pair<int, int> getPosition() const { return this->position; }
    void setPosition(const std::pair<int, int> position) { this->position = position; }
private:
    std::pair<int, int> position = std::pair(0, 0);
    double value = 0;
};


#endif //ER_VAJA_1_SOLUTION_H
