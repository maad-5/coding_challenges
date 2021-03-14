#include "heap.hpp"

#include <vector>

namespace sorts {

void sift_down(std::vector<int>& vector, std::vector<int>::size_type begin, std::vector<int>::size_type end)
{
    auto root = begin;

    while (2 * root + 1 <= end) {
        auto left_child = 2 * root + 1;
        auto right_child = 2 * root + 2;
        auto swap = root;

        if (vector.at(swap) < vector.at(left_child)) {
            swap = left_child;
        }
        if (right_child <= end && vector.at(swap) < vector.at(right_child)) {
            swap = right_child;
        }

        if (swap == root) {
            return;
        }

        std::swap(vector.at(root), vector.at(swap));
        root = swap;
    }
}

void heap(std::vector<int>& v) noexcept
{
    if (v.empty()) {
        return;
    }

    auto end = v.size() - 1;
    int parent = (end - 1) / 2;

    // heapify
    while (parent >= 0) {
        sift_down(v, parent, end);
        parent--;
    }

    while (end > 0) {
        std::swap(v.at(end), v.at(0));
        end--;
        sift_down(v, 0, end);
    }
}

} // namespace sorts
