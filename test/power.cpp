#include "gtest/gtest.h"

#include "symbolicc++.h"

using namespace std;

TEST(Simplify, SQRT) {
  Symbolic four(-4);

  cout << sqrt(four).simplify();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}