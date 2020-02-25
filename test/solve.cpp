#include "math.h"
#include "gtest/gtest.h"

#include "symbolicc++.h"

using namespace std;

TEST(Solve, 1thDegree)
{
    Symbolic x("x");

    auto sols = solve(x - 1, x);

    ASSERT_TRUE(sols.size() == 1);

    for (auto sol : sols) {
        ASSERT_TRUE(sol.rhs == 1);
    }
}

TEST(Solve, 2thDegree)
{
    Symbolic x("x");

    auto sols = solve((x - 1) * (x - 1), x);

    ASSERT_TRUE(sols.size() == 2);

    for (auto sol : sols) {
        ASSERT_TRUE(sol.rhs == 1);
    }
}

TEST(Solve, 3thDegree)
{
    Symbolic x("x");

    auto sols = solve((x - 1) * (x - 1) * (x - 1), x);

    ASSERT_TRUE(sols.size() == 3);

    for (auto sol : sols) {
        ASSERT_TRUE(sol.rhs == 1);
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}