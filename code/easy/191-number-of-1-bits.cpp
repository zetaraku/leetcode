// Title: Number of 1 Bits
// Description:
//     Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
// Link: https://leetcode.com/problems/number-of-1-bits/

// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    int hammingWeight(std::uint32_t n) {
        int result = 0;

        while (n != 0) {
            result += n & 1;
            n >>= 1;
        }

        return result;

        // use STL
        // return std::bitset<32>(n).count();

        // C++20:
        // return std::popcount(n);

        // GCC compiler built-in function:
        // return __builtin_popcount(n);
    }
};
