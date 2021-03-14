#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

#include "merge.hpp"
#include "sorts.hpp"

namespace {

TEST(merge, empty)
{
    std::vector<int> empty{sorts::empty};
    std::vector<int> reference{sorts::empty};

    sorts::merge(empty);
    std::ranges::sort(reference);

    EXPECT_EQ(empty, reference);
}

TEST(merge, all_equal)
{
    std::vector<int> all_equal{sorts::all_equal};
    std::vector<int> reference{sorts::all_equal};

    sorts::merge(all_equal);
    std::ranges::sort(reference);

    EXPECT_EQ(all_equal, reference);
}

TEST(merge, monotonic)
{
    std::vector<int> monotonic;
    std::vector<int> reference;

    for (auto&& v : {sorts::increasing, sorts::decreasing}) {
        monotonic = v;
        reference = v;

        sorts::merge(monotonic);
        std::ranges::sort(reference);

        EXPECT_EQ(monotonic, reference);
    }
}

TEST(merge, any)
{
    std::vector<int> any;
    std::vector<int> reference;

    for (auto&& v : {sorts::any_1, sorts::any_5, sorts::any_10, sorts::any_20}) {
        any = v;
        reference = v;

        sorts::merge(any);
        std::ranges::sort(reference);

        EXPECT_EQ(any, reference);
    }
}

} // namespace
