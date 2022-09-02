// Title: Climbing Stairs
// Description:
//     You are climbing a staircase. It takes n steps to reach the top.
//     Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Link: https://leetcode.com/problems/climbing-stairs/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int climbStairs(int n) {
        /*
            dp[k] = number of distinct ways to climb to the k-th stair
                  = number of ways to climb to the (k-1)-th stair then climb 1 step +
                    number of ways to climb to the (k-2)-th stair then climb 2 step
        */
        std::vector<int> dp(n+1); {
            dp[0] = 1;
            if (n >= 1) dp[1] = 1;
        }
        
        for (std::size_t i = 2; i <= n; ++i) {
            dp[i] = dp[i-2] + dp[i-1];
        }
        
        return dp[n];
    }
    
    // Note: We are just calculating Fibonacci Number (see Problem 509. Fibonacci Number)
};
