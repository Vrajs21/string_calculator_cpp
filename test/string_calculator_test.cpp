#include <gtest/gtest.h>
#include "../include/string_calculator.hpp"


GTEST_TEST(StringCalculatorTest, EmptyString) {
    EXPECT_EQ(StringCalculator::add(""), 0);
}

GTEST_TEST(StringCalculatorTest,Check_Single_Interger_input) {
    EXPECT_EQ(StringCalculator::add("3"), 3);
}

GTEST_TEST(StringCalculatorTest, TwoNumbers) {
    EXPECT_EQ(6, StringCalculator::add("1,5"));
}

GTEST_TEST(StringCalculatorTest, MultipleNumbers) {
    EXPECT_EQ(15, StringCalculator::add("1,2,3,4,5"));
}

GTEST_TEST(StringCalculatorTest, NegativeNumbers) {
    EXPECT_EQ(-5, StringCalculator::add("-1,-4"));
}

GTEST_TEST(StringCalculatorTest, MixedNumbers) {
    EXPECT_EQ(0, StringCalculator::add("1,-1"));
}

GTEST_TEST(StringCalculatorTest,Allow_newline_opereator) {
    EXPECT_EQ(99, StringCalculator::add("100\n-1"));
}
GTEST_TEST(StringCalculatorTest,is_custom_delimeter_is_allowed) {
    EXPECT_EQ(16, StringCalculator::add("//;\n7\n1;8"));
}
GTEST_TEST(StringCalculatorTest,is_custom_delimeter_is_allowed_2) {
    EXPECT_EQ(30, StringCalculator::add("//;\n18;10;2"));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}