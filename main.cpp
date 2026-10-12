#include <iostream>
#include <vector>

#include "problems/Sphere.h"

int main() {
    Sphere sphere;
    sphere.setD(2);
    std::vector specimen{5.12, -5.12};
    auto res = sphere.evaluate(specimen);
    std::cout << res << std::endl;

    return 0;
}
