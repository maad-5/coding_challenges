#include "selection.hpp"

#include <algorithm>
#include <vector>

namespace sorts {

void selection(std::vector<int>& v) noexcept
{
    for (auto i = v.begin(); i < v.end(); ++i) {
        auto min = i;

        for (auto j = i + 1; j < v.end(); ++j) {
            if (*j < *min) {
                min = j;
            }
        }

        std::iter_swap(i, min);
    }
}

} // namespace sorts
