#include "quick.hpp"

#include <algorithm>
#include <iterator>
#include <vector>

namespace sorts {

// FIXME: translate into iterative call
void quick_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end) noexcept
{
    if (end - begin < 2) {
        return;
    }

    auto lo = begin;
    auto hi = end - 1;

    // Hoare partition scheme.
    int pivot{*(lo + (hi - lo) / 2)};

    while (lo <= hi) {
        while (*lo < pivot) {
            ++lo;
        }

        while (pivot < *hi) {
            --hi;
        }

        if (lo <= hi) {
            std::iter_swap(lo, hi);
            ++lo;
            --hi;
        }
    }

    quick_sort(begin, lo);
    quick_sort(lo, end);
}

void quick(std::vector<int>& v) noexcept
{
    quick_sort(v.begin(), v.end());
}

} // namespace sorts
