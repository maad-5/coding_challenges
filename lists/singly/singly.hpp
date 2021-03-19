#ifndef SINGLY__SINGLY_HPP
#define SINGLY__SINGLY_HPP

/// @file

#include <memory>
#include <vector>

namespace singly {

/// @brief A singly list node.
struct Node final {
    int value{0};
    std::shared_ptr<Node> next;
};

/// @brief Create a new list from the input array.
std::shared_ptr<Node> new_list(const std::vector<int>& v);

} // namespace singly

#endif
