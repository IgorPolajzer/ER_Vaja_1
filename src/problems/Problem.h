#pragma once

#include <string>
#include <vector>

class Problem {
public:
    virtual ~Problem() = default;

    virtual double evaluate(const std::vector<double> &x_star) = 0;

    void checkBounds(double x) const;

    void setDfromInput(const std::vector<double> &x_star);

    const std::string &getName() const { return name; }
    void setName(const std::string &name) { this->name = name; }

    int getD() const { return d; }
    virtual void setD(int d) { this->d = d; }

    double getLowerBound() const { return lowerBound; }
    void setLowerBound(double lowerBound) { this->lowerBound = lowerBound; }

    double getUpperBound() const { return upperBound; }
    void setUpperBound(double upperBound) { this->upperBound = upperBound; }

protected:
    virtual int generateRandomSolution() = 0;

private:
    std::string name;
    int d = -1;
    double lowerBound = 0.0;
    double upperBound = 0.0;
};
