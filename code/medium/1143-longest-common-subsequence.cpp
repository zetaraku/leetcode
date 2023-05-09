// Title: Longest Common Subsequence
// Description:
//     Given two strings text1 and text2, return the length of their longest common subsequence.
//     A subsequence of a string is a new string generated from the original string
//     with some characters(can be none) deleted without changing the relative order of the remaining characters.
//     (eg, "ace" is a subsequence of "abcde" while "aec" is not).
//     A common subsequence of two strings is a subsequence that is common to both strings.
//     If there is no common subsequence, return 0.
// Link: https://leetcode.com/problems/longest-common-subsequence/

// Time complexity: O(n1*n2)
// Space complexity: O(n1*n2)
class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        const std::size_t n1 = text1.length();
        const std::size_t n2 = text2.length();
        
        // dp[i][j] = the length of longest common subsequence of text1[0,i) and text2[0,j)
        std::vector<std::vector<int>> dp(1+n1, std::vector<int>(1+n2)); {
            dp[0][0] = 0;
            for (std::size_t i = 1; i <= n1; ++i) dp[i][0] = 0;
            for (std::size_t j = 1; j <= n2; ++j) dp[0][j] = 0;
        }
        
        /*
            dp[i][j] = {
                dp[i-1][j-1] + 1             if text1[i-1] == text2[j-1]
                max(dp[i][j-1], dp[i-1][j])  if text1[i-1] != text2[j-1]
            } for i > 0, j > 0
        */
        for (std::size_t i = 1; i <= n1; ++i) {
            for (std::size_t j = 1; j <= n2; ++j) {
                dp[i][j] = (text1[i-1] == text2[j-1] ?
                    dp[i-1][j-1] + 1 :
                    std::max(dp[i][j-1], dp[i-1][j])
                );
            }
        }
        
        return dp[n1][n2];
    }
};
