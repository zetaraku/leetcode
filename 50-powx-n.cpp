// Title: Pow(x, n)
// Description:
//     Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
// Link: https://leetcode.com/problems/powx-n/

// Time complexity: O(log(n))
// Space complexity: O(log(n))
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        
        // handle negative n and integer overflow
        if (n < 0) return myPow(1 / x, -(n + 1)) / x;

        // Exponentiation by squaring:
        //     https://en.wikipedia.org/wiki/Exponentiation_by_squaring
        return myPow(x * x, n / 2) * (n % 2 == 0 ? 1 : x);
    }
};
