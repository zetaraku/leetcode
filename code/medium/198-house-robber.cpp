// Title: House Robber
// Description:
//     You are a professional robber planning to rob houses along a street.
//     Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected
//     and it will automatically contact the police if two adjacent houses were broken into on the same night.
//     Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
// Link: https://leetcode.com/problems/house-robber/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int rob(std::vector<int> &nums) {
        std::size_t N = nums.size();
        
        // dp[k] = max money we can rob from the first k houses
        std::vector<int> dp(N+1);
        
        dp[0] = 0;
        if (N >= 1) dp[1] = nums[0];
        
        for (std::size_t k = 2; k <= N; ++k) {
            // the current house index (0-based)
            std::size_t i = k - 1;
            
            dp[k] = std::max(
                // rob k-th house and take max rob from the first k-2 houses (avoid adjacent)
                dp[k-2] + nums[i],
                // spare rob k-th house and take max rob from the first k-1 houses
                dp[k-1]
            );
        }
        
        // return the max money we can rob from all (i.e. first N) houses
        return dp[N];
    }
};
