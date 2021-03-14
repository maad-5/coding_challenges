#include <limits>

#include <gtest/gtest.h>

#include "roman_numerals.hpp"

namespace {

TEST(roman_numerals, to_decimal__single_symbol)
{
    EXPECT_EQ(numbers::roman_to_decimal("I"), 1);
    EXPECT_EQ(numbers::roman_to_decimal("X"), 10);
    EXPECT_EQ(numbers::roman_to_decimal("D"), 500);
    EXPECT_EQ(numbers::roman_to_decimal("M"), 1000);
}

TEST(roman_numerals, to_decimal__many_symbols)
{
    EXPECT_EQ(numbers::roman_to_decimal("VIII"), 8);
    EXPECT_EQ(numbers::roman_to_decimal("XXII"), 22);
    EXPECT_EQ(numbers::roman_to_decimal("DCLVI"), 656);
    EXPECT_EQ(numbers::roman_to_decimal("MCLXVII"), 1167);
}

TEST(roman_numerals, to_decimal__subtract)
{
    EXPECT_EQ(numbers::roman_to_decimal("IV"), 4);
    EXPECT_EQ(numbers::roman_to_decimal("XIX"), 19);
    EXPECT_EQ(numbers::roman_to_decimal("XLII"), 42);
    EXPECT_EQ(numbers::roman_to_decimal("MMCM"), 2900);
}

TEST(roman_numerals, to_decimal__invalid)
{
    // Too many symbols in a row
    EXPECT_EQ(numbers::roman_to_decimal("IIII"), -1);
    EXPECT_EQ(numbers::roman_to_decimal("VV"), -1);

    // Invalid subtract
    EXPECT_EQ(numbers::roman_to_decimal("IIX"), -1);
    EXPECT_EQ(numbers::roman_to_decimal("IXI"), -1);
    EXPECT_EQ(numbers::roman_to_decimal("VX"), -1);
    EXPECT_EQ(numbers::roman_to_decimal("VIV"), -1);
}

// =====================================================================================================================

TEST(roman_numerals, to_numeral__valid)
{
    EXPECT_EQ(numbers::decimal_to_roman(1), "I");
    EXPECT_EQ(numbers::decimal_to_roman(10), "X");
    EXPECT_EQ(numbers::decimal_to_roman(176), "CLXXVI");
    EXPECT_EQ(numbers::decimal_to_roman(345), "CCCXLV");
    EXPECT_EQ(numbers::decimal_to_roman(2489), "MMCDLXXXIX");
    EXPECT_EQ(numbers::decimal_to_roman(3888), "MMMDCCCLXXXVIII");
    EXPECT_EQ(numbers::decimal_to_roman(3999), "MMMCMXCIX");
}

} // namespace
