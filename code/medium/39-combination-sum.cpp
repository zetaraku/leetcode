// Title: Combination Sum
// Description:
//     Given an array of distinct integers candidates and a target integer target,
//     return a list of all unique combinations of candidates where the chosen numbers sum to target.
//     You may return the combinations in any order.
//     The same number may be chosen from candidates an unlimited number of times.
//     Two combinations are unique if the frequency of at least one of the chosen numbers is different.
//     It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
// Link: https://leetcode.com/problems/combination-sum/

// Time complexity: O(2^(n+t)*t)
// Space complexity: O(2^(n+t)*t)
class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::size_t N = candidates.size();
        std::size_t T = target;
        
        /*
            dp[n][t] = all combinations using first n candidates that sum to t
                     = { c ∪ { num } | c ∈ dp[n][t-num], num = candidates[n-1] } ∪ dp[n-1][t]
        */
        std::vector<std::vector<int>> dp[N+1][T+1];
        
        dp[0][0] = {{}};        // one combination with no candidate
        for (std::size_t n = 1; n <= N; ++n) {
            dp[n][0] = {{}};    // one combination with no candidate
        }
        for (std::size_t t = 1; t <= T; ++t) {
            dp[0][t] = {};      // no combination (impossible)
        }
        for (std::size_t n = 1; n <= N; ++n) {
            for (std::size_t t = 1; t <= T; ++t) {
                int num = candidates[n-1];
                
                // dp[n][t] += { c ∪ { num } | c ∈ dp[n][t-num], num = candidates[n-1] }
                if (t >= num) {
                    std::transform(
                        dp[n][t-num].begin(), dp[n][t-num].end(),
                        std::back_inserter(dp[n][t]),
                        [num](std::vector<int> combination) {
                            std::vector<int> newCombination(combination);
                            newCombination.push_back(num);
                            return newCombination;
                        }
                    );
                }
                
                // dp[n][t] += dp[n-1][t]
                dp[n][t].insert(dp[n][t].end(), dp[n-1][t].begin(), dp[n-1][t].end());
            }
        }
        
        return dp[N][T];
    }
};
