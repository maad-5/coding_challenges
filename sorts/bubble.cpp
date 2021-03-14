#include "bubble.hpp"

#include <algorithm>
#include <vector>

namespace sorts {

void bubble(std::vector<int>& v) noexcept
{
    auto i = v.begin() + 1;
    auto j = v.end();

    while (i < j) {
        auto m = i;

        for (auto k = i; k < j; ++k) {
            if (*k < *(k - 1)) {
                std::iter_swap(k, k - 1);
                m = k;
            }
        }

        // m == i: no swaps happened, vector is sorted
        //   != i: v[m:] is sorted, skip it next time
        j = m;
    }
}

} // namespace sorts
