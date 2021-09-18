#ifndef DESIGN__LRU_CACHE
#define DESIGN__LRU_CACHE

/// @file

#include <memory>
#include <string>
#include <unordered_map>

namespace design {

/**
 * LRU (least-recently used) cache system.
 *
 * Implements `O(1)` lookup, insertion and deletion time.
 *
 * @note Constraints:
 *   - keys are integers, values are strings
 *   - maximum capacity is 100, default is 10
 */
class LRU_Cache final {
  public:
    explicit LRU_Cache(std::size_t capacity);

    LRU_Cache(const LRU_Cache&) = delete;
    LRU_Cache& operator=(const LRU_Cache&) = delete;

    LRU_Cache(LRU_Cache&&) = delete;
    LRU_Cache& operator=(LRU_Cache&&) = delete;

    /**
     * @returns `std::nullopt` if @p key does not exist.
     */
    std::optional<std::string> get(int key);

    /**
     * @remark Push node with @p key value to the front of the cache.
     */
    void put(int key, std::string_view value);

    std::size_t get_size() const noexcept { return m_cache.size(); }
    std::size_t get_capacity() const noexcept { return m_capacity; }

  private:
    struct Node final {
        Node() = default;
        Node(int key, std::string_view value) : key{key}, value{value} {}

        int key{0};
        std::string value;

        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev; // prevent cyclic deps / memory leaks
    };

    void push_front(std::shared_ptr<Node>& node);
    void move_front(std::shared_ptr<Node>& node);
    void pop_back();

    std::shared_ptr<Node> m_head{std::make_shared<Node>()}; // dummy node
    std::shared_ptr<Node> m_tail{std::make_shared<Node>()}; // dummy node

    std::unordered_map<int, std::shared_ptr<Node>> m_cache;
    std::size_t m_capacity{10};

    static constexpr std::size_t s_max_capacity{100};
};

} // namespace design

#endif
