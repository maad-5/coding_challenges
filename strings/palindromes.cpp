#include "palindromes.hpp"

#include <string_view>

namespace strings {

bool is_palindrome(std::string_view sv) noexcept
{
    auto lo = sv.begin();
    auto hi = sv.end() - 1;

    while (lo < hi) {
        if (*lo != *hi) {
            return false;
        }

        ++lo, --hi;
    }

    return true;
}

bool is_almost_palindrome(std::string_view sv) noexcept
{
    auto lo = sv.begin();
    auto hi = sv.end() - 1;

    while (lo < hi) {
        if (*lo != *hi) {
            if (*(lo + 1) == *hi) {
                return is_palindrome(std::string_view(lo + 1, hi + 1));
            }
            else if (*lo == *(hi - 1)) {
                return is_palindrome(std::string_view(lo, hi));
            }

            break;
        }

        ++lo, --hi;
    }

    return false;
}

} // namespace strings
