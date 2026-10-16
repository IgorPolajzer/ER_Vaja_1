#include <iostream>

#include "algorithm/RandomSearch.h"
#include "problems/Sphere.h"

int main() {
    Sphere sphere(2);
    RandomSearch randomSearch;
    auto res = randomSearch.execute(sphere, 1000);

    std::cout << res.toString() << std::endl;

    return 0;
}
