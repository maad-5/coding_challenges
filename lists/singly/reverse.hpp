#ifndef SINGLY__REVERSE_HPP
#define SINGLY__REVERSE_HPP

/// @file

#include <memory>

#include "singly.hpp"

namespace singly {

/// @brief Reverse a list.
///
/// @param[in] head A pointer to the head node of a list.
///
/// @return A pointer to the new head.
std::shared_ptr<Node> reverse(std::shared_ptr<Node> head) noexcept;

} // namespace singly

#endif
