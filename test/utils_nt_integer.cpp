#include "gtest/gtest.h"

#include "symbolicc++.h"

using namespace std;

TEST(Integer, BigFactorize) {
  mpz_class composite = mpz_class("45105705414323153");
  list<mpz_class> factors = factorize_int(composite);
  ASSERT_TRUE(factors.size() == 2);
}

TEST(Integer, SmallFactorize) {
  list<int> factors = list<int>{};
  _factorize_trial_division<int>(1234, &factors);
  ASSERT_TRUE(factors.size() == 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}