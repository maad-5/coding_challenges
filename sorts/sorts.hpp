#ifndef SORTS__SORTS_HPP
#define SORTS__SORTS_HPP

#include <vector>

namespace sorts {

inline const std::vector<int> empty{};

inline const std::vector<int> all_equal{3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

inline const std::vector<int> increasing{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
inline const std::vector<int> decreasing{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

inline const std::vector<int> any_1{5};
inline const std::vector<int> any_5{-1, 4, -1, -2, 3};
inline const std::vector<int> any_10{-4, 9, 3, -2, 5, 6, 0, 0, 7, -1};
inline const std::vector<int> any_20{6, 6, -8, -20, 4, -6, -10, -16, 11, -4, 10, -1, 5, 12, 16, 7, 15, 4, -11, 17};

} // namespace sorts

#endif
