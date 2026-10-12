#include "StyblinskiTang.h"

StyblinskiTang::StyblinskiTang() {
    setName("StyblinskiTang");
    setLowerBound(-5.0);
    setUpperBound(5.0);
}

double StyblinskiTang::evaluate(const std::vector<double> & /*x_star*/) {
    return 0;
}

int StyblinskiTang::generateRandomSolution() {
    return 0;
}
