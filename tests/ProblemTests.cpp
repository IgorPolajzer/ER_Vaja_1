#include <gtest/gtest.h>

#include <vector>

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

class ProblemTest : public testing::Test {
};

class ProblemTests : public testing::TestWithParam<int> {
};

TEST_P(ProblemTests, testSphere) {
    auto d = GetParam();
    Sphere problem;
    std::vector specimen(d, 0.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_EQ(0.0, fitness);
}

TEST_P(ProblemTests, testAckely) {
    auto d = GetParam();
    Ackley problem;
    std::vector specimen(d, 0.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_NEAR(0.0, fitness, 1e-9);
}

TEST_P(ProblemTests, testGriewank) {
    auto d = GetParam();
    Griewank problem;
    std::vector specimen(d, 0.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_EQ(0.0, fitness);
}

TEST_P(ProblemTests, testRastrigin) {
    auto d = GetParam();
    Rastrigin problem;
    std::vector specimen(d, 0.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_EQ(0.0, fitness);
}

TEST_P(ProblemTests, testSchwefel26) {
    auto d = GetParam();
    Schwefel26 problem;
    std::vector specimen(d, 420.968746);
    auto fitness = problem.evaluate(specimen);

    EXPECT_NEAR(-418.982887272433799807913601398 * d, fitness, 1e-9);
}

TEST_P(ProblemTests, testRosenbrock) {
    auto d = GetParam();
    Rosenbrock problem;
    std::vector specimen(d, 1.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_EQ(0.0, fitness);
}

TEST_P(ProblemTests, testTrid) {
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

TEST_P(ProblemTests, testLevy) {
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

TEST_F(ProblemTest, testCarromTable) {
    CarromTable problem;
    std::vector specimen = std::vector{9.646157266348881, 9.646157266348881};
    auto fitness = problem.evaluate(specimen);

    EXPECT_NEAR(-24.15681551650653, fitness, 1e-6);
}

TEST_P(ProblemTests, testStyblinskiTang) {
    auto d = GetParam();
    StyblinskiTang problem;
    std::vector specimen(d, -2.903534);
    auto fitness = problem.evaluate(specimen);

    EXPECT_NEAR(-39.16599 * d, fitness, 1e-2);
}

TEST_F(ProblemTest, testMichalewicz) {
    Michalewicz problem;

    // 1 dim.
    std::vector specimenOne{2.20290552017261};
    auto fitness = problem.evaluate(specimenOne);

    EXPECT_NEAR(-0.801303410098552549, fitness, 1e-9);

    // 2 dim.
    std::vector specimenTwo{2.20290552014618,1.57079632677565};
    fitness = problem.evaluate(specimenTwo);

    EXPECT_NEAR(-1.80130341009855321, fitness, 1e-9);
}

INSTANTIATE_TEST_SUITE_P(Dimensions, ProblemTests, testing::Values(2, 5, 10));
