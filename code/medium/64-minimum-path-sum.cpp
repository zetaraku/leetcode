// Title: Minimum Path Sum
// Description:
//     Given a m x n grid filled with non-negative numbers,
//     find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//     Note: You can only move either down or right at any point in time.
// Link: https://leetcode.com/problems/minimum-path-sum/

// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    int minPathSum(std::vector<std::vector<int>> &grid) {
        assert(grid.size() != 0 && grid[0].size() != 0);

        const std::size_t M = grid.size();
        const std::size_t N = grid[0].size();
        
        /*
            dp[i][j] = minimum path sum starting from top-left (0, 0) to (i, j)
        */
        std::vector<std::vector<int>> dp(M, std::vector<int>(N)); {
            dp[0][0] = grid[0][0];
            for (std::size_t i = 1; i < M; ++i) dp[i][0] = dp[i-1][0] + grid[i][0];
            for (std::size_t j = 1; j < N; ++j) dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        for (std::size_t i = 1; i < M; ++i) {
            for (std::size_t j = 1; j < N; ++j) {
                dp[i][j] = std::min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
            }
        }
        
        // the minimum path sum starting from top-left (0, 0) to bottom-right (M-1, N-1)
        return dp[M-1][N-1];
    }
};
