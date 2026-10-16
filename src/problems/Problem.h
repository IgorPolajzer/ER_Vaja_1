//
// Created by igor on 10/13/26.
//

#ifndef ER_VAJA_1_PROBLEM_H
#define ER_VAJA_1_PROBLEM_H

#include <string>
#include <vector>

#include "algorithm/Solution.h"
#include "misc/Bound.h"

class Problem {
public:
    virtual ~Problem() = default;

    virtual double evaluate(const std::vector<double> &x_star) = 0;

    double evaluateSolution(Solution &solution) {
        double fitness = evaluate(solution.getPosition());
        solution.setValue(fitness);
        return fitness;
    }

    void checkBounds(double x, int index) const;

    void checkDimension(const std::vector<double> &x_star) const;

    const std::string &getName() const { return name; }
    void setName(const std::string &name) { this->name = name; }

    int getD() const { return d; }

    bool isScalable() const { return scalable; }

    Bound getLowerBound() const { return lowerBound; }

    Bound getUpperBound() const { return upperBound; }

    Solution generateRandomSolution();

protected:
    Problem(std::string name, int d, Bound lowerBound, Bound upperBound, bool scalable);

    static void checkBoundsType(const Bound &lowerBound, const Bound &upperBound);

private:
    std::string name;
    int d;
    bool scalable;
    Bound lowerBound;
    Bound upperBound;
};

#endif //ER_VAJA_1_PROBLEM_H
