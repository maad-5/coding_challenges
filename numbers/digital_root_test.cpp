#include <gtest/gtest.h>

#include "digital_root.hpp"

namespace {

TEST(digital_root, any)
{
    EXPECT_EQ(numbers::digital_root(0), 0);
    EXPECT_EQ(numbers::digital_root(5), 5);
    EXPECT_EQ(numbers::digital_root(39), 3);
    EXPECT_EQ(numbers::digital_root(871), 7);
    EXPECT_EQ(numbers::digital_root(5'642), 8);
    EXPECT_EQ(numbers::digital_root(93'201), 6);
    EXPECT_EQ(numbers::digital_root(123'456'789), 9);
    EXPECT_EQ(numbers::digital_root(2'147'483'647), 1);
}

} // namespace
