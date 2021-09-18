#include <optional>
#include <stdexcept>

#include <gtest/gtest.h>

#include "lru_cache.hpp"

namespace {

TEST(lru_cache, exception__wrong_capacity)
{
    EXPECT_THROW(design::LRU_Cache(-1), std::invalid_argument);
    EXPECT_THROW(design::LRU_Cache(0), std::invalid_argument);
    EXPECT_THROW(design::LRU_Cache(101), std::invalid_argument);
}

TEST(lru_cache, basic__put_get)
{
    auto cache = design::LRU_Cache(2);

    cache.put(0, "0");
    cache.put(1, "1");

    EXPECT_EQ(cache.get(0), "0");
    EXPECT_EQ(cache.get(1), "1");

    EXPECT_EQ(cache.get(2), std::nullopt);
    EXPECT_EQ(cache.get(3), std::nullopt);

    EXPECT_EQ(cache.get_size(), 2);
    EXPECT_EQ(cache.get_capacity(), 2);
}

TEST(lru_cache, basic__put_overwrite)
{
    auto cache = design::LRU_Cache(2);

    cache.put(0, "0");
    cache.put(1, "1");

    EXPECT_EQ(cache.get(0), "0");
    EXPECT_EQ(cache.get(1), "1");

    cache.put(0, "000");
    cache.put(1, "111");

    EXPECT_EQ(cache.get(0), "000");
    EXPECT_EQ(cache.get(1), "111");

    EXPECT_EQ(cache.get_size(), 2);
    EXPECT_EQ(cache.get_capacity(), 2);
}

TEST(lru_cache, basic__put_rotation)
{
    auto cache = design::LRU_Cache(2);

    cache.put(0, "0");
    cache.put(1, "1");

    EXPECT_EQ(cache.get(0), "0");
    EXPECT_EQ(cache.get(1), "1");

    cache.put(2, "2");
    cache.put(3, "3");

    EXPECT_EQ(cache.get(0), std::nullopt);
    EXPECT_EQ(cache.get(1), std::nullopt);
    EXPECT_EQ(cache.get(2), "2");
    EXPECT_EQ(cache.get(3), "3");

    EXPECT_EQ(cache.get_size(), 2);
    EXPECT_EQ(cache.get_capacity(), 2);
}

TEST(lru_cache, usecase)
{
    auto cache = design::LRU_Cache(5);

    cache.put(0, "0");
    cache.put(3, "3");

    EXPECT_EQ(cache.get(3), "3");
    EXPECT_EQ(cache.get(0), "0");
    EXPECT_EQ(cache.get(5), std::nullopt);
    EXPECT_EQ(cache.get(1), std::nullopt);

    cache.put(0, "00");

    EXPECT_EQ(cache.get(0), "00");

    cache.put(1, "1");
    cache.put(2, "2");
    cache.put(4, "4");

    EXPECT_EQ(cache.get_size(), 5);
    EXPECT_EQ(cache.get_capacity(), 5);

    cache.put(5, "5");
    cache.put(9, "9");

    EXPECT_EQ(cache.get_size(), 5);
    EXPECT_EQ(cache.get_capacity(), 5);

    EXPECT_EQ(cache.get(3), std::nullopt);
    EXPECT_EQ(cache.get(0), std::nullopt);
}

} // namespace
