#include "math.h"
#include "gtest/gtest.h"

#include "symbolicc++.h"

using namespace std;

TEST(BasicTest, Sum)
{
    Symbolic a("a"), y;

    y = 5 * a;

    ASSERT_TRUE(y.coeff(a) == 5);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}