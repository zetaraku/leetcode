// Title: Unique Paths II
// Description:
//     You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]).
//     The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.
//     An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
//     Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
//     The testcases are generated so that the answer will be less than or equal to 2 * 10^9.
// Link: https://leetcode.com/problems/unique-paths-ii/

// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        
        /*
            dp[i][j] = the number of possible unique paths to reach the grid (i, j) without obstacle
                     = the number of paths from left + the number of paths from top, if no obstacle
                     = {
                         dp[i][j-1] + dp[i-1][j] if obstacleGrid[i][j] == 0
                                    0            if obstacleGrid[i][j] != 0
                       }
        */
        int dp[m][n];
        
        if (true) {
            dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        }
        for (std::size_t i = 1; i != m; ++i) {
            dp[i][0] = obstacleGrid[i][0] == 0 ? dp[i-1][0] : 0;
        }
        for (std::size_t j = 1; j != n; ++j) {
            dp[0][j] = obstacleGrid[0][j] == 0 ? dp[0][j-1] : 0;
        }
        for (std::size_t i = 1; i != m; ++i) {
            for (std::size_t j = 1; j != n; ++j) {
                dp[i][j] = obstacleGrid[i][j] == 0 ? dp[i][j-1] + dp[i-1][j] : 0;
            }
        }
        
        return dp[m-1][n-1];
    }
};
