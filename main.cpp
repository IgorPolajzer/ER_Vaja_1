#include "algorithm/RandomSearch.h"
#include "algorithm/Runner.h"
#include "problems/Ackley.h"
#include "problems/Sphere.h"

int main() {
    Sphere sphere(2);
    Ackley ackley(3);

    RandomSearch randomSearch;
    std::vector<Problem*> problems;
    problems.push_back(&sphere);
    problems.push_back(&ackley);

    Runner::execute(problems, randomSearch);

    return 0;
}
