// Title: Power of Two
// Description:
//     Given an integer n, return true if it is a power of two. Otherwise, return false.
//     An integer n is a power of two, if there exists an integer x such that n == 2^x.
// Link: https://leetcode.com/problems/power-of-two/

// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // it must be a positive number first
        if (n <= 0) return false;
        
        // in the binary representation, it must have exactly one 1
        //    [n]       00010000      01010000
        //   [n-1]    & 00001111    & 01001111
        //            ----------    ----------
        //              00000000      01000000
        return (n & (n - 1)) == 0;
    }
};
