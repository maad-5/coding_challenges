#ifndef STRINGS__PALINDROMES
#define STRINGS__PALINDROMES

/// @file

#include <string_view>

namespace strings {

/// Tell if a string is a palindrome.
///
/// @remark A _palindrome_ is a string that is spelled the same backwards as it
/// is forwards, like "racecar."
bool is_palindrome(std::string_view sv) noexcept;

/// Tell if a string is almost a palindrome.
///
/// @remark An _almost_ palindrome is a string that turns into a palindrome by
/// removing one (and only one) character.
bool is_almost_palindrome(std::string_view sv) noexcept;

} // namespace strings

#endif
