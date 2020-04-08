#include "math.h"
#include "gtest/gtest.h"

#include "symbolicc++.h"

using namespace std;

TEST(Solve, 1thDegree) {
  Symbolic x("x");

  auto sols = solve(x - 1, x);

  ASSERT_TRUE(sols.size() == 1);

  for (auto sol : sols) {
    ASSERT_TRUE(sol.rhs == 1);
  }
}

TEST(Solve, 2thDegree) {
  Symbolic x("x");

  auto sols = solve((x - 1) * (x - 1), x);

  ASSERT_TRUE(sols.size() == 2);

  for (auto sol : sols) {
    ASSERT_TRUE(sol.rhs == 1);
  }
}

TEST(Solve, 3thDegree) {
  Symbolic x("x");

  auto sols = solve((x - 1) * (x - 1) * (x - 1), x);

  ASSERT_TRUE(sols.size() == 3);

  for (auto sol : sols) {
    ASSERT_TRUE(sol.rhs.simplify() == 1);
  }
}

TEST(Solve, findroot) {
  Symbolic x("x");
  setprecision(2);
  ASSERT_TRUE(abs(0.96 - find_root(cos(x) * sin(1) - (x / 2), x)) < 0.01);
}

TEST(solve, BasicExp) {
  Symbolic x("x");
  auto sols = solve(3 * exp(2 * x) - 2, x);
  for (auto sol : sols) {
    ASSERT_TRUE(sol.rhs.simplify() ==
                1 / Symbolic(2) * log(SymbolicConstant::e, Symbolic(2) / 3));
  }
}

TEST(solve, ExpBasic2thDegree) {
  Symbolic x("x"), z("z");

  auto sols = solve((exp(x ^ 2)) - 1, x);
  ASSERT_TRUE(sols.size() == 2);

  for (auto sol : sols) {
    ASSERT_TRUE(sol.rhs.simplify() == 0);
  }
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}