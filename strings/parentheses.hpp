#ifndef STRINGS__PARENTHESES
#define STRINGS__PARENTHESES

/// @file

#include <string_view>

namespace strings {

/// Count all matching pairs of nested parentheses `(` and `)`.
///
/// @remark `"()"` and `"())"` both count to one pair.
int count_parentheses_pairs(std::string_view sv) noexcept;

} // namespace strings

#endif
