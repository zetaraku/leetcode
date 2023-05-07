// Title: Reverse Bits
// Description:
//     Reverse bits of a given 32 bits unsigned integer.
// Link: https://leetcode.com/problems/reverse-bits/

// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    std::uint32_t reverseBits(std::uint32_t n) {
        std::uint32_t r = 0;

        // move 32 bits one-by-one
        for (std::size_t i = 0; i != 32; ++i) {
            // spare the lowest bit in r
            r <<= 1;

            // copy the lowest bit from n to r
            r |= (n & 1);

            // pop the lowest bit from n
            n >>= 1;
        }

        return r;
    }
};
