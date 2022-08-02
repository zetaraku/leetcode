// Title: Minimum Path Sum
// Description:
//     Given a m x n grid filled with non-negative numbers,
//     find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//     Note: You can only move either down or right at any point in time.
// Link: https://leetcode.com/problems/minimum-path-sum/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int r = grid.size();
        int c = grid.at(0).size();
        
        // Dynamic Programming:
        // dp[i][j] = minimum path sum which starts from (0, 0) to (i, j)
        vector<vector<int>> minSum(r, vector<int>(c)); {
            // dp[0][0] = grid[0][0]
            minSum.at(0).at(0) = grid.at(0).at(0);
            
            // dp[i][0] = dp[i-1][0] + grid[i][0]
            for (int i = 1; i < r; i++)
                minSum.at(i).at(0) = minSum.at(i-1).at(0) + grid.at(i).at(0);
            
            // dp[0][j] = dp[0][j-1] + grid[0][j]
            for (int j = 1; j < c; j++)
                minSum.at(0).at(j) = minSum.at(0).at(j-1) + grid.at(0).at(j);
        }
        
        // dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j]
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                minSum.at(i).at(j) = std::min(
                    minSum.at(i).at(j-1),
                    minSum.at(i-1).at(j)
                ) + grid.at(i).at(j);
            }
        }
        
        // the answer is in dp[r-1][c-1], the minimum path sum which starts from (0, 0) to (r-1, c-1)
        return minSum.at(r-1).at(c-1);
    }
};
