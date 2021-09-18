#ifndef HASH_TABLE__HASH_TABLE_HPP
#define HASH_TABLE__HASH_TABLE_HPP

#include <algorithm>
#include <array>
#include <cmath>
#include <exception>
#include <functional>
#include <list>
#include <utility>
#include <vector>

namespace hash_table {

/**
 * Hash table implementation.
 *
 * Capacity is fixed at 64 (number of buckets).
 */
template <typename K, typename V>
class Hash_table final {
  public:
    /**
     * Add a `{key,value}` pair.
     *
     * \exception std::invalid_argument @p key already exists.
     */
    void add(const K& key, const V& value)
    {
        auto&& bucket = m_buckets.at(hash_function(key));
        auto record = std::find_if(bucket.begin(), bucket.end(), std::bind(find_key, std::placeholders::_1, key));

        if (record != bucket.end()) {
            throw std::invalid_argument{"ERROR: {key,value} already exists"};
        }

        bucket.push_back({key, value});
        m_size++;
    }

    /**
     * Get a key's value.
     *
     * \exception std::invalid_argument @p key does not exist.
     */
    V get(const K& key) const
    {
        const auto& bucket = m_buckets.at(hash_function(key));
        auto record = std::find_if(bucket.begin(), bucket.end(), std::bind(find_key, std::placeholders::_1, key));

        if (record == bucket.end()) {
            throw std::invalid_argument{"ERROR: no such key"};
        }

        return record->second;
    }

    /**
     * Set a key's value.
     *
     * @exception std::invalid_argument Throw if @p key does not exist.
     */
    void set(const K& key, const V& value)
    {
        auto&& bucket = m_buckets.at(hash_function(key));
        auto record = std::find_if(bucket.begin(), bucket.end(), std::bind(find_key, std::placeholders::_1, key));

        if (record == bucket.end()) {
            throw std::invalid_argument{"ERROR: no such key"};
        }

        record->second = value;
    }

    /**
     * Remove a key and its value.
     *
     * @note The function is a no-op if @p key does not exist.
     */
    void remove(const K& key)
    {
        m_size -= m_buckets.at(hash_function(key)).remove_if(std::bind(find_key, std::placeholders::_1, key));
    }

    int size() const noexcept { return m_size; }
    float load_factor() const noexcept { return static_cast<float>(m_size) / m_capacity; }

  private:
    using Record = std::pair<K, V>;
    using Bucket = std::list<Record>;

    static constexpr int m_capacity{64};

    static bool find_key(const Record& bucket, const K& key) noexcept { return bucket.first == key; }

    int hash_function(const K& key) const noexcept { return std::abs(int(std::hash<K>{}(key) % m_capacity)); }

    int m_size{0};
    std::array<Bucket, m_capacity> m_buckets;
};

} // namespace hash_table

#endif
