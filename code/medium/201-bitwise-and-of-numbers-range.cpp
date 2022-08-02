// Title: Bitwise AND of Numbers Range
// Description:
//     Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
// Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/

// Time complexity: O(log(n))
// Space complexity: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = n;
        
        // keep turning the rightmost 1-bit into 0-bit from result until it is less than m
        while (result > m)
            result &= (result - 1);
        
        return result;
    }
};
