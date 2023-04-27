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
        int n1 = text1.length();
        int n2 = text2.length();
        
        // dp[i][j] = the length of longest common subsequence of text1[0,i) and text2[0,j)
        std::vector<std::vector<int>> dp(n1+1, std::vector<int>(n2+1));{
            // dp[i][0] = 0
            for (int i = 0; i <= n1; i++) dp.at(i).at(0) = 0;
            // dp[0][j] = 0
            for (int j = 0; j <= n2; j++) dp.at(0).at(j) = 0;
        }
        
        /*
            dp[i][j] = {
                dp[i-1][j-1] + 1             if text1[i-1] == text2[j-1]
                max(dp[i-1][j], dp[i][j-1])  if text1[i-1] != text2[j-1]
            } for i > 0, j > 0
        */
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                dp.at(i+1).at(j+1) = (text1.at(i) == text2.at(j) ?
                    dp.at(i).at(j) + 1 :
                    std::max(
                        dp.at(i).at(j+1),
                        dp.at(i+1).at(j)
                    )
                );
            }
        }
        
        return dp.at(n1).at(n2);
    }
};
