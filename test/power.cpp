#include "gtest/gtest.h"

#include "symbolicc++.h"

using namespace std;

TEST(Simplify, SQRT) {
  Symbolic four(-4);

  ASSERT_TRUE(sqrt(four).simplify() == 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}