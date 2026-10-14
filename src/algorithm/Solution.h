//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_SOLUTION_H
#define ER_VAJA_1_SOLUTION_H

#include <vector>

class Solution {
public:
    virtual ~Solution() = default;

private:
    std::pair<int, int> position = std::pair(0, 0);
    double solution = 0;
};


#endif //ER_VAJA_1_SOLUTION_H
