#include "math.h"
#include "gtest/gtest.h"

#include "symbolicc++.h"

using namespace std;

TEST(Integrate, Basic)
{
    Symbolic x("x");

    ASSERT_TRUE(integrate(sin(x), x) == -cos(x));
    ASSERT_TRUE(integrate(cos(x), x) == sin(x));
    ASSERT_TRUE(integrate(exp(x), x) == exp(x));
    ASSERT_TRUE(integrate(2 * x, x) == x * x);
    ASSERT_TRUE(integrate(1 / x, x) == ln(x));
    ASSERT_TRUE(integrate(2 / x, x) == 2 * ln(x));
}

TEST(Integrate, Complex)
{
    Symbolic x("x"), y;

    y = (1 - x) * (1 - x) + cos(x) + x * exp(x);

    y = integrate(y, x);
    y = y[integrate(x * exp(x), x) == x * exp(x) - exp(x)];

    ASSERT_TRUE(y == Symbolic(1) / 3 * x * x * x - x * x + sin(x) + x * exp(x) - exp(x) + x);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}