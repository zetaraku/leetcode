// Title: Generate Parentheses
// Description:
//     Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Link: https://leetcode.com/problems/generate-parentheses/

// Time complexity: O(C(n)), where C(n) = the n-th Catalan number
// Space complexity: O(C(n)), where C(n) = the n-th Catalan number
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        /*
            dp[k]
                = all well-formed combinations of k pairs of parentheses
                = {
                    well-formed combinations of k pairs of parentheses
                    with the first group consisting of i pairs of parentheses
                  } for { i = 1 ... k }
                = {
                    "(" + str1 + ")" + str2
                  } for { str1 ∈ dp[i-1], str2 ∈ dp[j], i + j = k }
        */
        std::vector<std::string> dp[n+1];
        
        dp[0] = { "" };
        for (std::size_t k = 1; k <= n; ++k) {
            for (std::size_t i = 1; i <= k; ++i) {
                for (const std::string &str1: dp[i-1]) {
                    for (const std::string &str2: dp[k-i]) {
                        dp[k].push_back("(" + str1 + ")" + str2);
                    }
                }
            }
        }

        return dp[n];
    }
    /* Note: Using backtracking may be more efficient. */
};
