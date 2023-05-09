// Title: Maximal Square
// Description:
//     Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
// Link: https://leetcode.com/problems/maximal-square/

// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

        const std::size_t M = matrix.size();
        const std::size_t N = matrix[0].size();
        
        // keep track of the side of the largest square
        std::size_t maxSide = 0;
        
        // dp[i][j] = side of the largest square containing only 1's with (i, j) as the bottom-right corner
        std::vector<std::vector<std::size_t>> dp(M, std::vector<std::size_t>(N)); {
            for (std::size_t i = 0; i != M; ++i) {
                dp[i][0] = (matrix[i][0] == '1' ? 1 : 0);
                maxSide = std::max(dp[i][0], maxSide);
            }
            for (std::size_t j = 0; j != N; ++j) {
                dp[0][j] = (matrix[0][j] == '1' ? 1 : 0);
                maxSide = std::max(dp[0][j], maxSide);
            }
        }
        
        /*
            dp[i][j] = {
                min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1  if matrix[i][j] == '1'
                0                                              if matrix[i][j] != '1'
            } for i > 0, j > 0
        */
        for (std::size_t i = 1; i < M; ++i) {
            for (std::size_t j = 1; j < N; ++j) {
                dp[i][j] = (matrix[i][j] == '1' ? std::min({ dp[i-1][j-1], dp[i][j-1], dp[i-1][j] }) + 1 : 0);
                maxSide = std::max(dp[i][j], maxSide);
            }
        }
        
        // return the max square area
        return maxSide * maxSide;
    }
};
