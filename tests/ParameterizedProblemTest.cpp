#include <gtest/gtest.h>

#include <vector>

#include "problems/Ackley.h"
#include "problems/Bukin.h"
#include "problems/Griewank.h"
#include "problems/Levy.h"
#include "problems/Rastrigin.h"
#include "problems/Rosenbrock.h"
#include "problems/Schwefel26.h"
#include "problems/Sphere.h"
#include "problems/Trid.h"

class ProblemTest : public testing::Test {
};

class ParameterizedProblemTest : public testing::TestWithParam<int> {
};

TEST_P(ParameterizedProblemTest, testSphere) {
    auto d = GetParam();
    Sphere problem;
    std::vector specimen(d, 0.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_EQ(0.0, fitness);
}

TEST_P(ParameterizedProblemTest, testAckely) {
    auto d = GetParam();
    Ackley problem;
    std::vector specimen(d, 0.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_NEAR(0.0, fitness, 1e-9);
}

TEST_P(ParameterizedProblemTest, testGriewank) {
    auto d = GetParam();
    Griewank problem;
    std::vector specimen(d, 0.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_EQ(0.0, fitness);
}

TEST_P(ParameterizedProblemTest, testRastrigin) {
    auto d = GetParam();
    Rastrigin problem;
    std::vector specimen(d, 0.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_EQ(0.0, fitness);
}

TEST_P(ParameterizedProblemTest, testSchwefel26) {
    auto d = GetParam();
    Schwefel26 problem;
    std::vector specimen(d, 420.968746);
    auto fitness = problem.evaluate(specimen);

    EXPECT_NEAR(-418.982887272433799807913601398 * d, fitness, 1e-9);
}

TEST_P(ParameterizedProblemTest, testRosenbrock) {
    auto d = GetParam();
    Rosenbrock problem;
    std::vector specimen(d, 1.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_EQ(0.0, fitness);
}

TEST_P(ParameterizedProblemTest, testTrid) {
    auto d = GetParam();
    Trid problem;
    std::vector<double> specimen;

    for (int i = 1; i <= d; i++) {
        specimen.push_back(i * (d + 1.0 - i));
    }

    auto fitness = problem.evaluate(specimen);

    auto expected = -d * (d + 4.0) * (d - 1.0) / 6.0;
    EXPECT_EQ(expected, fitness);
}

TEST_P(ParameterizedProblemTest, testLevy) {
    auto d = GetParam();
    Levy problem;
    std::vector specimen(d, 1.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_NEAR(0.0, fitness, 1e-9);
}

TEST_F(ProblemTest, testBukin) {
    Bukin problem;
    std::vector specimen = std::vector{-10.0, 1.0};
    auto fitness = problem.evaluate(specimen);

    EXPECT_EQ(0.0, fitness);
}

INSTANTIATE_TEST_SUITE_P(Dimensions, ParameterizedProblemTest, testing::Values(2, 5, 10));
