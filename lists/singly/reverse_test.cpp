#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

#include "reverse.hpp"
#include "singly.hpp"

namespace {

TEST(reverse, empty)
{
    std::vector<int> empty;

    auto list = singly::new_list(empty);
    auto reversed = singly::reverse(singly::reverse(list));

    EXPECT_EQ(list, reversed);
}

TEST(reverse, one)
{
    std::vector<int> one{5};

    auto list = singly::new_list(one);
    auto reversed = singly::reverse(singly::reverse(list));

    EXPECT_EQ(list, reversed);
}

TEST(reverse, increasing)
{
    std::vector<int> increasing{1, 2, 3, 4, 5};

    auto list = singly::new_list(increasing);
    auto reversed = singly::reverse(singly::reverse(list));

    EXPECT_EQ(list, reversed);
}

TEST(reverse, decreasing)
{
    std::vector<int> decreasing{5, 4, 3, 2, 1};

    auto list = singly::new_list(decreasing);
    auto reversed = singly::reverse(singly::reverse(list));

    EXPECT_EQ(list, reversed);
}

TEST(reverse, any)
{
    std::vector<int> any{-1, 4, -1, -2, 3};

    auto list = singly::new_list(any);
    auto reversed = singly::reverse(singly::reverse(list));

    EXPECT_EQ(list, reversed);
}

} // namespace
