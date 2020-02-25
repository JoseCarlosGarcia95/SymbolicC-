#include "math.h"
#include "gtest/gtest.h"

#include "symbolicc++.h"

using namespace std;

TEST(Derivative, TestProperties)
{
    Symbolic x("x");

    ASSERT_TRUE(df(sin(x), x) == cos(x));
    ASSERT_TRUE(df(cos(x), x) == -sin(x));
    ASSERT_TRUE(df(exp(x), x) == exp(x));
    ASSERT_TRUE(df(x ^ 2, x) == 2 * x);
    ASSERT_TRUE(df(ln(x), x) == 1 / x);
    ASSERT_TRUE(df(ln(x ^ 2), x) == 2 / x);
    ASSERT_TRUE(df(ln(x) * (x * x), x) == x + ln(x) * 2 * x);
    ASSERT_TRUE(df(ln(x) / x, x) == (1 - ln(x)) / (x * x));
}

TEST(Derivative, Dependencies)
{
    Symbolic x("x"), y("y");

    y = y[x];

    ASSERT_TRUE(df(y + x, x) == df(y, x) + 1);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}