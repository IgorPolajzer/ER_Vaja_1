#include <memory>
#include <vector>

#include "algorithm/RandomSearch.h"
#include "algorithm/Runner.h"
#include "problems/Ackley.h"
#include "problems/Bukin.h"
#include "problems/CarromTable.h"
#include "problems/Griewank.h"
#include "problems/Levy.h"
#include "problems/Michalewicz.h"
#include "problems/Rastrigin.h"
#include "problems/Rosenbrock.h"
#include "problems/Schwefel26.h"
#include "problems/Sphere.h"
#include "problems/StyblinskiTang.h"
#include "problems/Trid.h"

int main() {
    std::vector<std::unique_ptr<Problem> > ownedProblems;

    // Ackley.
    ownedProblems.push_back(std::make_unique<Ackley>(2));
    ownedProblems.push_back(std::make_unique<Ackley>(5));
    ownedProblems.push_back(std::make_unique<Ackley>(10));

    // Bukin.
    ownedProblems.push_back(std::make_unique<Bukin>()); // Fixed to 2 dimensions.

    // CarromTable.
    ownedProblems.push_back(std::make_unique<CarromTable>()); // Fixed to 2 dimensions.

    // Griewank.
    ownedProblems.push_back(std::make_unique<Griewank>(2));
    ownedProblems.push_back(std::make_unique<Griewank>(5));
    ownedProblems.push_back(std::make_unique<Griewank>(10));

    // Levy.
    ownedProblems.push_back(std::make_unique<Levy>(2));
    ownedProblems.push_back(std::make_unique<Levy>(5));
    ownedProblems.push_back(std::make_unique<Levy>(10));

    // Michalewicz.
    ownedProblems.push_back(std::make_unique<Michalewicz>(2));
    ownedProblems.push_back(std::make_unique<Michalewicz>(5));
    ownedProblems.push_back(std::make_unique<Michalewicz>(10));

    // Rastrigin.
    ownedProblems.push_back(std::make_unique<Rastrigin>(2));
    ownedProblems.push_back(std::make_unique<Rastrigin>(5));
    ownedProblems.push_back(std::make_unique<Rastrigin>(10));

    // Rosenbrock.
    ownedProblems.push_back(std::make_unique<Rosenbrock>(2));
    ownedProblems.push_back(std::make_unique<Rosenbrock>(5));
    ownedProblems.push_back(std::make_unique<Rosenbrock>(10));

    // Schwefel26.
    ownedProblems.push_back(std::make_unique<Schwefel26>(2));
    ownedProblems.push_back(std::make_unique<Schwefel26>(5));
    ownedProblems.push_back(std::make_unique<Schwefel26>(10));

    // Sphere.
    ownedProblems.push_back(std::make_unique<Sphere>(2));
    ownedProblems.push_back(std::make_unique<Sphere>(5));
    ownedProblems.push_back(std::make_unique<Sphere>(10));

    // StyblinskiTang.
    ownedProblems.push_back(std::make_unique<StyblinskiTang>(2));
    ownedProblems.push_back(std::make_unique<StyblinskiTang>(5));
    ownedProblems.push_back(std::make_unique<StyblinskiTang>(10));

    // Trid.
    ownedProblems.push_back(std::make_unique<Trid>(2));
    ownedProblems.push_back(std::make_unique<Trid>(5));
    ownedProblems.push_back(std::make_unique<Trid>(10));

    std::vector<Problem *> problems;
    for (const auto &problem: ownedProblems)
        problems.push_back(problem.get());

    RandomSearch randomSearch;
    Runner::execute(problems, randomSearch);

    return 0;
}
