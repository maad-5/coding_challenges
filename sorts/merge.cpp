#include "merge.hpp"

#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>

namespace sorts {

void merge_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end) noexcept
{
    auto size = end - begin;

    if (size < 2) {
        return;
    }

    auto boundary = begin + (size / 2);

    merge_sort(begin, boundary);
    merge_sort(boundary, end);

    auto lo = begin;
    auto hi = boundary;

    std::vector<int> sorted;

    while (lo != boundary && hi != end) {
        if (*lo < *hi) {
            sorted.push_back(*lo);
            ++lo;
        }
        else {
            sorted.push_back(*hi);
            ++hi;
        }
    }

    if (lo != boundary) {
        sorted.insert(sorted.end(), lo, boundary);
    }
    else if (hi != end) {
        sorted.insert(sorted.end(), hi, end);
    }

    std::move(sorted.begin(), sorted.end(), begin);
}

void merge(std::vector<int>& v) noexcept
{
    merge_sort(v.begin(), v.end());
}

} // namespace sorts
