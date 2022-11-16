// Title: House Robber II
// Description:
//     You are a professional robber planning to rob houses along a street.
//     Each house has a certain amount of money stashed.
//     All houses at this place are arranged in a circle.
//     That means the first house is the neighbor of the last one.
//     Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
//     Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
// Link: https://leetcode.com/problems/house-robber-ii/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    /* This helper function is from the solution of Problem 198. House Robber */
    int robSub(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
        std::size_t N = end - begin;
        
        // dp[k] = max money we can rob from the first k houses
        std::vector<int> dp(N+1);
        
        dp[0] = 0;
        if (N >= 1) dp[1] = *(begin + 0);
        
        for (std::size_t k = 2; k <= N; ++k) {
            // the current house index (0-based)
            std::size_t i = k - 1;
            
            dp[k] = std::max(
                // rob k-th house and take max rob from the first k-2 houses (avoid adjacent)
                dp[k-2] + *(begin + i),
                // spare rob k-th house and take max rob from the first k-1 houses
                dp[k-1]
            );
        }
        
        // return the max money we can rob from all (i.e. first N) houses
        return dp[N];
    }
    
    int rob(std::vector<int> &nums) {
        std::size_t N = nums.size();
        
        // handle edge cases
        if (N == 0) return 0;
        if (N == 1) return nums[0];
        
        // we can break the circle at some point to avoid houses at two ends being robbed at the same time:
        return std::max(
            // cases when the first house is never robbed
            robSub(nums.begin() + 1, nums.end()),
            // cases when the last house is never robbed
            robSub(nums.begin(), nums.end() - 1)
            // These cover all cases because the first house and the last house cannot be robbed at the same time
        );
    }
};
