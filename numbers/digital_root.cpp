#include "digital_root.hpp"

namespace numbers {

int digital_root(int n) noexcept
{
    while (n > 9) {
        int m{0};

        while (n != 0) {
            m += n % 10;
            n /= 10;
        }

        n = m;
    }

    return n;
}

} // namespace numbers
