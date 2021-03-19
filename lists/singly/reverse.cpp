#include "reverse.hpp"

#include <memory>

#include "singly.hpp"

namespace singly {

std::shared_ptr<Node> reverse(std::shared_ptr<Node> head) noexcept
{
    std::shared_ptr<Node> prev;
    std::shared_ptr<Node> next;

    for (auto curr = head; curr; curr = next) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
    }

    return prev;
}

} // namespace singly
