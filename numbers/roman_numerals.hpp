#ifndef NUMBERS__ROMAN_NUMERALS
#define NUMBERS__ROMAN_NUMERALS

/// @file

#include <string>
#include <string_view>

namespace numbers {

/// Convert a string of roman numerals to a decimal number.
///
/// @note Constraints:
///     - @p roman is made of the letters 'I', 'V', 'X', 'L', 'C', 'D' and 'M'
///       only.
///
/// @return `-1` in case of an invalid input, such as:
///     - too many symbols in a row (e.g. "IIII", "VV")
///     - invalid subtract cases (e.g. "IIX", "IXI", "VL")
int roman_to_decimal(std::string_view roman) noexcept;

/// Convert a decimal number to a string of roman numerals.
///
/// @note Constraints:
///     - @p decimal is within the range `[1..3999]`.
std::string decimal_to_roman(int decimal) noexcept;

} // namespace numbers

#endif
