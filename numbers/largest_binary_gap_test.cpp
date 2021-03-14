#include <limits>

#include <gtest/gtest.h>

#include "largest_binary_gap.hpp"

namespace {

TEST(largest_binary_gap, any_gaps)
{
    EXPECT_EQ(numbers::largest_binary_gap(5), 1);           //           5 = 0b101
    EXPECT_EQ(numbers::largest_binary_gap(9), 2);           //           9 = 0b1001
    EXPECT_EQ(numbers::largest_binary_gap(2'546), 2);       //       2'546 = 0b1001'1111'0010
    EXPECT_EQ(numbers::largest_binary_gap(220'267'537), 5); // 220'267'537 = 0b1101'0010'0001'0000'0100'0001'0001

    // 1'073'741'824 = 0b100'0000'0000'0000'0000'0000'0000'0001
    EXPECT_EQ(numbers::largest_binary_gap(1'073'741'825), 29);
}

TEST(largest_binary_gap, no_gaps)
{
    EXPECT_EQ(numbers::largest_binary_gap(1), 0);      //      1 = 0b1
    EXPECT_EQ(numbers::largest_binary_gap(3), 0);      //      3 = 0b11
    EXPECT_EQ(numbers::largest_binary_gap(15), 0);     //     15 = 0b1111
    EXPECT_EQ(numbers::largest_binary_gap(65'280), 0); // 65'280 = 0b1111'1111'0000'0000
}

TEST(largest_binary_gap, min_max)
{
    // 0 = 0b0
    EXPECT_EQ(numbers::largest_binary_gap(0), 0);

    // 2'147'483'647 = 0b111'1111'1111'1111'1111'1111'1111'1111
    EXPECT_EQ(numbers::largest_binary_gap(2'147'483'647), 0);
}

} // namespace
