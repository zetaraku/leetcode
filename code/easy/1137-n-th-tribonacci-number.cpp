// Title: N-th Tribonacci Number
// Description:
//     The Tribonacci sequence T[n] is defined as follows: 
//     T[0] = 0, T[1] = 1, T[2] = 1, and T[n+3] = T[n] + T[n+1] + T[n+2] for n >= 0.
//     Given n, return the value of T[n].
// Link: https://leetcode.com/problems/n-th-tribonacci-number/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int tribonacci(int n) {
        std::vector<int> dp(n+1); {
            dp[0] = 0;
            if (n >= 1) dp[1] = 1;
            if (n >= 2) dp[2] = 1;
        }
        
        for (std::size_t i = 3; i <= n; ++i) {
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
        
        return dp[n];
    }
    
    // Note: For an O(log(n)) solution, please refer to Problem 509. Fibonacci Number
};
