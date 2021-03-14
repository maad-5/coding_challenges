#include "insertion.hpp"

#include <algorithm>
#include <vector>

namespace sorts {

void insertion(std::vector<int>& v) noexcept
{
    for (auto i = v.begin() + 1; i < v.end(); ++i) {
        int x{*i};
        auto j = i - 1;

        while (j >= v.begin() && x < *j) {
            --j;
        }

        // Shift elements to the right, then assign x in-place.
        std::copy(j + 1, i, j + 2);
        *(j + 1) = x;
    }
}

} // namespace sorts
