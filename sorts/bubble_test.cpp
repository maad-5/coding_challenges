#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

#include "bubble.hpp"
#include "sorts.hpp"

namespace {

TEST(bubble, empty)
{
    std::vector<int> empty{sorts::empty};
    std::vector<int> reference{sorts::empty};

    sorts::bubble(empty);
    std::ranges::sort(reference);

    EXPECT_EQ(empty, reference);
}

TEST(bubble, all_equal)
{
    std::vector<int> all_equal{sorts::all_equal};
    std::vector<int> reference{sorts::all_equal};

    sorts::bubble(all_equal);
    std::ranges::sort(reference);

    EXPECT_EQ(all_equal, reference);
}

TEST(bubble, monotonic)
{
    std::vector<int> monotonic;
    std::vector<int> reference;

    for (auto&& v : {sorts::increasing, sorts::decreasing}) {
        monotonic = v;
        reference = v;

        sorts::bubble(monotonic);
        std::ranges::sort(reference);

        EXPECT_EQ(monotonic, reference);
    }
}

TEST(bubble, any)
{
    std::vector<int> any;
    std::vector<int> reference;

    for (auto&& v : {sorts::any_1, sorts::any_5, sorts::any_10, sorts::any_20}) {
        any = v;
        reference = v;

        sorts::bubble(any);
        std::ranges::sort(reference);

        EXPECT_EQ(any, reference);
    }
}

} // namespace
