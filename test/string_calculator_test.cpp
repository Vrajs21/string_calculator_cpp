#include <gtest/gtest.h>
#include "../include/string_calculator.hpp"


GTEST_TEST(StringCalculatorTest, EmptyString) {
    EXPECT_EQ(StringCalculator::add(""), 0);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}