#include "gtest/gtest.h"

#include "symbolicc++.h"

using namespace std;

TEST(Integer, Factorize)
{
    mpz_class composite = mpz_class(
        "45105705414323153");
    list<mpz_class> factors = factorize_int(composite);
    ASSERT_TRUE(factors.size() == 2);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}