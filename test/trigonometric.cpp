#include "gtest/gtest.h"

#include "symbolicc++.h"

using namespace std;

TEST(Simplify, SIN) {
  ASSERT_TRUE(sin(0) == 0);
  ASSERT_TRUE(sin(SymbolicConstant::pi / 6).simplify() == Symbolic(1) / 2);
  ASSERT_TRUE(sin(SymbolicConstant::pi / 4).simplify() ==
              sqrt(Symbolic(2)) / 2);
  ASSERT_TRUE(sin(SymbolicConstant::pi / 3).simplify() ==
              sqrt(Symbolic(3)) / 2);
  ASSERT_TRUE(sin(SymbolicConstant::pi / 2).simplify() == 1);
  ASSERT_TRUE(sin(Symbolic(5) / 3 * SymbolicConstant::pi).simplify() ==
              -sqrt(Symbolic(3)) / 2);
  ASSERT_TRUE(sin(SymbolicConstant::pi / 4 + SymbolicConstant::pi).simplify() ==
              -sqrt(Symbolic(2)) / 2);
}

TEST(Simplify, COS) {
  ASSERT_TRUE(cos(0) == 1);
  ASSERT_TRUE(cos(SymbolicConstant::pi / 6).simplify() ==
              sqrt(Symbolic(3)) / 2);
  ASSERT_TRUE(cos(SymbolicConstant::pi / 4).simplify() ==
              sqrt(Symbolic(2)) / 2);
  ASSERT_TRUE(cos(SymbolicConstant::pi / 3).simplify() == Symbolic(1) / 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}