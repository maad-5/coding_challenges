#include "singly.hpp"

#include <memory>
#include <vector>

namespace singly {

std::shared_ptr<Node> new_list(const std::vector<int>& v)
{
    auto head = std::make_shared<Node>();
    auto curr = head;

    for (auto&& n : v) {
        curr->next = std::make_shared<Node>(n);
        curr = curr->next;
    }

    return head->next;
}

} // namespace singly
