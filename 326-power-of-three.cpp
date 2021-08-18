// Title: Power of Three
// Description:
//     Given an integer n, return true if it is a power of three. Otherwise, return false.
//     An integer n is a power of three, if there exists an integer x such that n == 3^x.
// Link: https://leetcode.com/problems/power-of-three/

// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        // n must be a positive number first
        if (n <= 0) return false;
        
        // the maximum value of int that is also a power of 3 is 3^19 = 1162261467
        // since 3 is a prime number, the only divisors of 3^19 are all in the form of 3^N
        // so if n is a divisor of 3^19, then n is in the form of 3^N
        return 1162261467 % n == 0;
    }
};
