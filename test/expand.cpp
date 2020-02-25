#include "math.h"
#include "gtest/gtest.h"

#include "symbolicc++.h"

using namespace std;

TEST(ExpandTest, Basic)
{
    Symbolic a("a"), b("b"), c("c"), y;

    y = ((a + b) * (a + b));

    ASSERT_TRUE(y.coeff(a) == 2 * b);
    ASSERT_TRUE(y.coeff(a * a) == 1);
    ASSERT_TRUE(y.coeff(b * b) == 1);
    ASSERT_TRUE(y.coeff(c) == 0);
    ASSERT_TRUE(y.coeff(b) == 2 * a);
}

TEST(ExpandTest, Newton)
{
    Symbolic a("a"), b("b"), c("c"), y;

    y = ((a + b) ^ 2);

    ASSERT_TRUE(y.coeff(a) == 2 * b);
    ASSERT_TRUE(y.coeff(a * a) == 1);
    ASSERT_TRUE(y.coeff(b * b) == 1);
    ASSERT_TRUE(y.coeff(c) == 0);
    ASSERT_TRUE(y.coeff(b) == 2 * a);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}