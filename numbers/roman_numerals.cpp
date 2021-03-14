#include "roman_numerals.hpp"

#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

namespace numbers {

enum Symbol
{
    I = 1,      // 1
    V = I << 1, // 5
    X = V << 1, // 10
    L = X << 1, // 50
    C = L << 1, // 100
    D = C << 1, // 500
    M = D << 1, // 1000
    N = M << 1  // special value (upper bound)
};

Symbol map_to_symbol(char ch) noexcept
{
    static const std::unordered_map<char, Symbol> mapping{
        {'I', I},
        {'V', V},
        {'X', X},
        {'L', L},
        {'C', C},
        {'D', D},
        {'M', M},
    };

    if (mapping.contains(ch)) {
        return mapping.at(ch);
    }

    return N;
}

int map_to_decimal(Symbol symbol) noexcept
{
    static const std::unordered_map<Symbol, int> mapping{
        {I, 1},
        {V, 5},
        {X, 10},
        {L, 50},
        {C, 100},
        {D, 500},
        {M, 1000},
    };

    if (mapping.contains(symbol)) {
        return mapping.at(symbol);
    }

    return 0;
}

int roman_to_decimal(std::string_view roman) noexcept
{
    Symbol previous{N};
    Symbol max{N};
    int accumulator{0};
    int decimal{0};

    for (auto&& ch : roman) {
        Symbol current{map_to_symbol(ch)};

        // Invalid cases: "VV" / "VIV" / "IXI" / "CMC"
        if (current == N || current >= max) {
            return -1;
        }

        // Invalid cases: "IIX" / "CCM"
        if (accumulator == 2 && current > previous) {
            return -1;
        }

        // Invalid cases: "IIII" / "CCCC"
        if (current == previous) {
            if (accumulator++; accumulator > 3) {
                return -1;
            }
        }
        else {
            accumulator = 1;
        }

        // Cases: "IV" / "CM"
        if ((previous & (I | X | C)) && current > previous && current <= (previous << 2)) {
            decimal += map_to_decimal(current) - 2 * map_to_decimal(previous);

            max = previous;
        }
        // Case: "VI" / "CL"
        else {
            decimal += map_to_decimal(current);

            if (current & (V | L | D)) {
                max = current;
            }
        }

        previous = current;
    }

    return decimal;
}

// =====================================================================================================================

std::string decimal_to_roman(int decimal) noexcept
{
    static const std::vector<std::pair<std::size_t, std::string>> symbols{
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
    };

    std::ostringstream buffer;

    for (auto&& [value, symbol] : symbols) {
        auto quotient = decimal / value;

        for (std::size_t i{1}; i <= quotient; i++) {
            buffer << symbol;
        }

        decimal -= value * quotient;
    }

    return buffer.str();
}

} // namespace numbers
