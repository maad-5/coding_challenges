#include <exception>
#include <string>
#include <utility>

#include <gtest/gtest.h>

#include "hash_table.hpp"

namespace {

const std::pair<std::string, int> kv1 = {"John DOE", 123};
const std::pair<std::string, int> kv2 = {"Alice DEE", 456};

TEST(hash_table, add)
{
    hash_table::Hash_table<std::string, int> ht;

    EXPECT_NO_THROW(ht.add(kv1.first, kv1.second));
    EXPECT_NO_THROW(ht.add(kv2.first, kv2.second));

    EXPECT_THROW(ht.add(kv1.first, kv1.second), std::invalid_argument);
    EXPECT_THROW(ht.add(kv2.first, kv2.second), std::invalid_argument);

    EXPECT_EQ(ht.size(), 2);
    EXPECT_FLOAT_EQ(ht.load_factor(), 2.0 / 64);
}

TEST(hash_table, get)
{
    hash_table::Hash_table<std::string, int> ht;

    ht.add(kv1.first, kv1.second);
    ht.add(kv2.first, kv2.second);

    EXPECT_EQ(ht.get(kv1.first), kv1.second);
    EXPECT_EQ(ht.get(kv2.first), kv2.second);
    EXPECT_EQ(ht.size(), 2);
    EXPECT_FLOAT_EQ(ht.load_factor(), 2.0 / 64);
}

TEST(hash_table, set)
{
    hash_table::Hash_table<std::string, int> ht;

    EXPECT_THROW(ht.set(kv1.first, kv1.second), std::invalid_argument);
    EXPECT_THROW(ht.set(kv2.first, kv2.second), std::invalid_argument);

    ht.add(kv1.first, kv1.second);
    ht.add(kv2.first, kv2.second);

    int new_kv1_value = 627;
    int new_kv2_value = 987;

    EXPECT_NO_THROW(ht.set(kv1.first, new_kv1_value));
    EXPECT_NO_THROW(ht.set(kv2.first, new_kv2_value));

    EXPECT_EQ(ht.get(kv1.first), new_kv1_value);
    EXPECT_EQ(ht.get(kv2.first), new_kv2_value);
    EXPECT_EQ(ht.size(), 2);
    EXPECT_FLOAT_EQ(ht.load_factor(), 2.0 / 64);
}

TEST(hash_table, remove)
{
    hash_table::Hash_table<std::string, int> ht;

    ht.add(kv1.first, kv1.second);
    ht.add(kv2.first, kv2.second);

    EXPECT_NO_THROW(ht.remove(kv1.first));
    EXPECT_NO_THROW(ht.remove(kv2.first));

    EXPECT_THROW(ht.get(kv1.first), std::invalid_argument);
    EXPECT_THROW(ht.get(kv2.first), std::invalid_argument);

    EXPECT_EQ(ht.size(), 0);
    EXPECT_FLOAT_EQ(ht.load_factor(), 0.0);
}

} // namespace
