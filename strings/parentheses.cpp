#include "parentheses.hpp"

#include <stack>
#include <string_view>

namespace strings {

int count_parentheses_pairs(std::string_view sv) noexcept
{
    std::stack<char8_t> stack;
    int matches{0};

    for (auto&& ch : sv) {
        if (ch == ')' && !stack.empty() && stack.top() == '(') {
            stack.pop();
            matches++;
        }
        else if (ch == '(') {
            stack.push(ch);
        }
    }

    return matches;
}

} // namespace strings
