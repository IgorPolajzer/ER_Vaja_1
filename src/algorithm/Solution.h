//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_SOLUTION_H
#define ER_VAJA_1_SOLUTION_H

#include <string>
#include <utility>
#include <vector>

class Solution {
public:
    explicit Solution(std::vector<double> position) : position(std::move(position)) {}

    double getValue() const { return this->value; }
    void setValue(const double value) { this->value = value; }

    const std::vector<double> &getPosition() const { return this->position; }
    void setPosition(const std::vector<double> &position) { this->position = position; }

    std::string toString() const {
        std::string positionString;

        for (int i = 0; i < position.size(); i++) {
            positionString += "dim_" + std::to_string(i) + ": " + std::to_string(position[i]) + ", ";
        }

        return "Solution: \nValue: " + std::to_string(value) + "\nPosition: " + positionString;
    }
private:
    std::vector<double> position;
    double value = 0.0;
};


#endif //ER_VAJA_1_SOLUTION_H
