#include "lru_cache.hpp"

#include <memory>
#include <stdexcept>
#include <string>

namespace design {

LRU_Cache::LRU_Cache(std::size_t capacity) : m_capacity{capacity}
{
    if (m_capacity > s_max_capacity) {
        throw std::invalid_argument{"cache capacity cannot exceed 100"};
    }
    else if (m_capacity == 0) {
        throw std::invalid_argument{"cache capacity must be strictly positive"};
    }

    m_head->next = m_tail;
    m_tail->prev = m_head;
}

std::optional<std::string> LRU_Cache::get(int key)
{
    if (auto I = m_cache.find(key); I != m_cache.end()) {
        move_front(I->second);
        return I->second->value;
    }

    return {};
}

void LRU_Cache::put(int key, std::string_view value)
{
    if (auto I = m_cache.find(key); I != m_cache.end()) {
        move_front(I->second);
        I->second->value = value;
        return;
    }

    if (m_cache.size() == m_capacity) {
        m_cache.erase(m_tail->prev.lock()->key);
        pop_back();
    }

    auto new_node = std::make_shared<Node>(key, value);

    push_front(new_node);
    m_cache[key] = new_node;
}

// =====================================================================================================================

void LRU_Cache::push_front(std::shared_ptr<Node>& node)
{
    // attach node to list
    node->next = m_head->next;
    node->prev = m_head;

    // insert node after list's head
    m_head->next = node;
    node->next->prev = node;
}

void LRU_Cache::move_front(std::shared_ptr<Node>& node)
{
    // remove node from list
    node->prev.lock()->next = node->next;
    node->next->prev = node->prev;

    push_front(node);
}

void LRU_Cache::pop_back()
{
    auto old_last = m_tail->prev;
    auto new_last = old_last.lock()->prev;

    new_last.lock()->next = m_tail;
    m_tail->prev = new_last;
}

} // namespace design
