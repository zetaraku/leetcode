// Title: Unique Paths
// Description:
//     There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
//     The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
//     Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
//     The test cases are generated so that the answer will be less than or equal to 2 * 10^9.
// Link: https://leetcode.com/problems/unique-paths/

// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        assert(m > 0 && n > 0);

        /*
            dp[i][j] = the number of possible unique paths to reach the grid (i, j)
                     = the number of paths from left + the number of paths from top
                     = dp[i][j-1] + dp[i-1][j]
        */
        std::vector<std::vector<int>> dp(m, std::vector<int>(n)); {
            dp[0][0] = 1;
            for (std::size_t i = 1; i != m; ++i) dp[i][0] = 1;
            for (std::size_t j = 1; j != n; ++j) dp[0][j] = 1;
        }
        
        for (std::size_t i = 1; i != m; ++i) {
            for (std::size_t j = 1; j != n; ++j) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        
        return dp[m-1][n-1];
    }
    /*
        The answer is actually C((m-1)+(n-1),(n-1)), which is ((m-1)+(n-1))!/((m-1)!*(n-1)!),
        but the intermediate results are too big to calculate by this way.
    */
};
