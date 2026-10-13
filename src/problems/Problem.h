//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_PROBLEM_H
#define ER_VAJA_1_PROBLEM_H

#include <string>
#include <vector>

#include "misc/Bound.h"

class Problem {
public:
    virtual ~Problem() = default;

    virtual double evaluate(const std::vector<double> &x_star) = 0;

    void checkBounds(double x, int index) const;

    void setDfromInput(const std::vector<double> &x_star);

    const std::string &getName() const { return name; }
    void setName(const std::string &name) { this->name = name; }

    int getD() const { return d; }
    virtual void setD(int d) { this->d = d; }

    Bound getLowerBound() const { return lowerBound; }
    void setLowerBound(const Bound lowerBound) { this->lowerBound = lowerBound; }

    Bound getUpperBound() const { return upperBound; }
    void setUpperBound(const Bound upperBound) { this->upperBound = upperBound; }

protected:
    virtual int generateRandomSolution() = 0;

    static void checkBoundsType(const Bound &lowerBound, const Bound &upperBound);

private:
    std::string name;
    int d = -1;
    Bound lowerBound = Bound(0.0);
    Bound upperBound = Bound(0.0);
};

#endif //ER_VAJA_1_PROBLEM_H
