// Title: Power of Four
// Description:
//     Given an integer n, return true if it is a power of four. Otherwise, return false.
//     An integer n is a power of four, if there exists an integer x such that n == 4^x.
// Link: https://leetcode.com/problems/power-of-four/

// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    bool isPowerOfFour(int n) {
        // it must be power of 2 first (see Problem 231. Power of Two)
        if (n <= 0 || (n & (n - 1)) != 0) return false;
        // in the binary representation, the only 1 must be on any power of 4
        return (n & 0b01010101010101010101010101010101) != 0;
    }
};
