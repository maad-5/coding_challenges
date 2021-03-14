#include <gtest/gtest.h>

#include "parentheses.hpp"

namespace {

TEST(count_parentheses_pairs, empty)
{
    EXPECT_EQ(strings::count_parentheses_pairs(""), 0);
}

TEST(count_parentheses_pairs, zero)
{
    EXPECT_EQ(strings::count_parentheses_pairs("))(("), 0);
    EXPECT_EQ(strings::count_parentheses_pairs("a)b)c(d(e"), 0);
}

TEST(count_parentheses_pairs, simple)
{
    EXPECT_EQ(strings::count_parentheses_pairs("()"), 1);
    EXPECT_EQ(strings::count_parentheses_pairs("a(b)c"), 1);
    EXPECT_EQ(strings::count_parentheses_pairs("(((())))"), 4);
    EXPECT_EQ(strings::count_parentheses_pairs("a(b(c(d(e)f)g)h)i"), 4);
}

TEST(count_parentheses_pairs, complex)
{
    EXPECT_EQ(strings::count_parentheses_pairs(")(()()))())("), 4);
    EXPECT_EQ(strings::count_parentheses_pairs("a)b(c(d)e(f)g)h)i(j)k)l(m"), 4);
}

} // namespace
