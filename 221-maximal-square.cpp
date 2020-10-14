// Title: Maximal Square
// Description:
//     Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
// Link: https://leetcode.com/problems/maximal-square/

// Time complexity: O(r*c)
// Space complexity: O(r*c)
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int r = matrix.size();
        if (r == 0) return 0;
        int c = matrix.at(0).size();
        if (c == 0) return 0;
        
        // keep track of the side of the largest square
        int maxSide = 0;
        
        // dp[i][j] = side of the largest square containing only 1's with (i, j) as the bottom-right corner
        vector<vector<int>> dp(r, vector<int>(c)); {
            // dp[i][0] = matrix[i][0] == '1' ? 1 : 0
            for (int i = 0; i < r; i++) {
                int side = dp.at(i).at(0) = matrix.at(i).at(0) == '1' ? 1 : 0;
                maxSide = std::max(maxSide, side);
            }
            // dp[0][j] = matrix[0][j] == '1' ? 1 : 0
            for (int j = 0; j < c; j++) {
                int side = dp.at(0).at(j) = matrix.at(0).at(j) == '1' ? 1 : 0;
                maxSide = std::max(maxSide, side);
            }
        }
        
        /*
            dp[i][j] = {
                min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1  if matrix[i][j] == '1'
                0                                              if matrix[i][j] != '1'
            } for i > 0, j > 0
        */
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                int side = dp.at(i).at(j) = (matrix.at(i).at(j) == '1' ?
                    std::min(
                        dp.at(i-1).at(j-1),
                        std::min(
                            dp.at(i).at(j-1),
                            dp.at(i-1).at(j)
                        )
                    ) + 1 : 0
                );
                maxSide = std::max(maxSide, side);
            }
        }
        
        // return the max area
        return maxSide * maxSide;
    }
};
