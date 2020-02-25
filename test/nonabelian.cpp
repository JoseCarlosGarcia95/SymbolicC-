#include "math.h"
#include "gtest/gtest.h"

#include "symbolicc++.h"

using namespace std;

TEST(NonAbelian, Basic)
{
    Symbolic a("a"), b("b"), y;
    a = ~a;
    b = ~b;

    y = a * b + b * a;
    ASSERT_TRUE(y.coeff(a) == b);
    ASSERT_TRUE(y.coeff(b) == a);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}