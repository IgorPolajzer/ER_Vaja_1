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
    Sphere problem(d);
    std::vector specimen(d, 0.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_EQ(0.0, fitness);
}

TEST_P(ProblemTests, testAckely) {
    auto d = GetParam();
    Ackley problem(d);
    std::vector specimen(d, 0.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_NEAR(0.0, fitness, 1e-7);
}

TEST_P(ProblemTests, testGriewank) {
    auto d = GetParam();
    Griewank problem(d);
    std::vector specimen(d, 0.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_EQ(0.0, fitness);
}

TEST_P(ProblemTests, testRastrigin) {
    auto d = GetParam();
    Rastrigin problem(d);
    std::vector specimen(d, 0.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_EQ(0.0, fitness);
}

TEST_P(ProblemTests, testSchwefel26) {
    auto d = GetParam();
    Schwefel26 problem(d);
    std::vector specimen(d, 420.968746);
    auto fitness = problem.evaluate(specimen);

    EXPECT_NEAR(-418.982887272433799807913601398 * d, fitness, 1e-7);
}

TEST_P(ProblemTests, testRosenbrock) {
    auto d = GetParam();
    Rosenbrock problem(d);
    std::vector specimen(d, 1.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_EQ(0.0, fitness);
}

TEST_P(ProblemTests, testTrid) {
    auto d = GetParam();
    Trid problem(d);
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
    Levy problem(d);
    std::vector specimen(d, 1.0);
    auto fitness = problem.evaluate(specimen);

    EXPECT_NEAR(0.0, fitness, 1e-7);
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

    EXPECT_NEAR(-24.15681551650653, fitness, 1e-7);
}

TEST_P(ProblemTests, testStyblinskiTang) {
    auto d = GetParam();
    StyblinskiTang problem(d);
    std::vector specimen(d, -2.90353401818596);
    auto fitness = problem.evaluate(specimen);

    EXPECT_NEAR(-39.16616570377142 * d, fitness, 1e-7);
}

TEST_F(ProblemTest, testMichalewicz) {
    // 2 dim.
    Michalewicz problemTwo(2);
    std::vector specimenTwo{2.202906, 1.570796};
    auto fitness = problemTwo.evaluate(specimenTwo);

    EXPECT_NEAR(-1.8013034, fitness, 1e-7);

    // 5 dim.
    Michalewicz problemFive(5);
    std::vector specimenFive{2.202906, 1.570796, 1.284992, 1.923058, 1.720470};
    fitness = problemFive.evaluate(specimenFive);

    EXPECT_NEAR(-4.6876582, fitness, 1e-7);

    // 10 dim.
    Michalewicz problemTen(10);
    std::vector specimenTen{2.202906, 1.570796, 1.284992, 1.923058, 1.720470, 1.570796, 1.454414, 1.756087, 1.655717, 1.570796};
    fitness = problemTen.evaluate(specimenTen);

    EXPECT_NEAR(-9.6601517, fitness, 1e-7);
}

TEST_F(ProblemTest, testIsScalable) {
    EXPECT_TRUE(Sphere(5).isScalable());
    EXPECT_TRUE(Trid(3).isScalable());
    EXPECT_FALSE(Bukin().isScalable());
    EXPECT_FALSE(CarromTable().isScalable());
}

INSTANTIATE_TEST_SUITE_P(Dimensions, ProblemTests, testing::Values(2, 5, 10));
