#include "gtest/gtest.h"

#include "symbolicc++.h"

using namespace std;

TEST(Numeric, SQRT) {
  Symbolic three(3);

  ASSERT_DOUBLE_EQ(double(sqrt(three) + 5 * three + sqrt(2)),
                   sqrt(3) + 5 * 3 + sqrt(2));
}

TEST(Numeric, SIN) {
  Symbolic three(3);

  ASSERT_DOUBLE_EQ(double(sin(three) + 5 * three + sin(2)),
                   sin(3) + 5 * 3 + sin(2));
}

TEST(Numeric, COS) {
  Symbolic three(3);

  ASSERT_DOUBLE_EQ(double(cos(three) + 5 * three + cos(2)),
                   cos(3) + 5 * 3 + cos(2));
}

TEST(Numeric, LOG) {
  Symbolic three(3);

  ASSERT_DOUBLE_EQ(double(log(three, SymbolicConstant::e) + 5 * three +
                          log(2, SymbolicConstant::e)),
                   log(3) + 5 * 3 + log(2));
}

TEST(Numeric, SINH) {
  Symbolic three(3);

  ASSERT_DOUBLE_EQ(double(sinh(three) + 5 * three + sinh(2)),
                   sinh(3) + 5 * 3 + sinh(2));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}