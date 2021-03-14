#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

#include "insertion.hpp"
#include "sorts.hpp"

namespace {

TEST(insertion, empty)
{
    std::vector<int> empty{sorts::empty};
    std::vector<int> reference{sorts::empty};

    sorts::insertion(empty);
    std::ranges::sort(reference);

    EXPECT_EQ(empty, reference);
}

TEST(insertion, all_equal)
{
    std::vector<int> all_equal{sorts::all_equal};
    std::vector<int> reference{sorts::all_equal};

    sorts::insertion(all_equal);
    std::ranges::sort(reference);

    EXPECT_EQ(all_equal, reference);
}

TEST(insertion, monotonic)
{
    std::vector<int> monotonic;
    std::vector<int> reference;

    for (auto&& v : {sorts::increasing, sorts::decreasing}) {
        monotonic = v;
        reference = v;

        sorts::insertion(monotonic);
        std::ranges::sort(reference);

        EXPECT_EQ(monotonic, reference);
    }
}

TEST(insertion, any)
{
    std::vector<int> any;
    std::vector<int> reference;

    for (auto&& v : {sorts::any_1, sorts::any_5, sorts::any_10, sorts::any_20}) {
        any = v;
        reference = v;

        sorts::insertion(any);
        std::ranges::sort(reference);

        EXPECT_EQ(any, reference);
    }
}

} // namespace
