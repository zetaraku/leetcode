// Title: Reverse Bits
// Description:
//     Reverse bits of a given 32 bits unsigned integer.
// Link: https://leetcode.com/problems/reverse-bits/

// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    std::uint32_t reverseBits(std::uint32_t n) {
        // divide and conquer
        n = ((n & 0b11111111111111110000000000000000) >> 16) | ((n & 0b00000000000000001111111111111111) << 16);
        n = ((n & 0b11111111000000001111111100000000) >>  8) | ((n & 0b00000000111111110000000011111111) <<  8);
        n = ((n & 0b11110000111100001111000011110000) >>  4) | ((n & 0b00001111000011110000111100001111) <<  4);
        n = ((n & 0b11001100110011001100110011001100) >>  2) | ((n & 0b00110011001100110011001100110011) <<  2);
        n = ((n & 0b10101010101010101010101010101010) >>  1) | ((n & 0b01010101010101010101010101010101) <<  1);

        return n;
    }

    // std::uint32_t reverseBits(std::uint32_t n) {
    //     std::uint32_t r = 0;

    //     // move 32 bits one-by-one
    //     for (std::size_t i = 0; i != 32; ++i) {
    //         // spare the lowest bit in r
    //         r <<= 1;

    //         // copy the lowest bit from n to r
    //         r |= (n & 1);

    //         // pop the lowest bit from n
    //         n >>= 1;
    //     }

    //     return r;
    // }
};

