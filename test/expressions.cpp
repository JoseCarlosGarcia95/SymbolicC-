#include "math.h"
#include "gtest/gtest.h"

#include "symbolicc++.h"

using namespace std;

TEST(BasicTest, Sum)
{
    Symbolic a("a"), b("b"), y;

    y = a + a + a + a + b;

    ASSERT_TRUE(y.coeff(a) == 4);
    ASSERT_TRUE(y.coeff(b) == 1);
    ASSERT_TRUE(y.coeff(b * b) == 0);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}