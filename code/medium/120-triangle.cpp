// Title: Triangle
// Description:
//     Given a triangle array, return the minimum path sum from top to bottom.
//     For each step, you may move to an adjacent number of the row below.
//     More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
//     Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
// Link: https://leetcode.com/problems/triangle/

// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>> &triangle) {
        const std::size_t N = triangle.size();

        /*
            dp[i][j] = the minimum path sum from (i, j) to bottom
                     = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j]
        */
        std::vector<std::vector<int>> dp(N+1); {
            // len(dp[i]) = i+1
            for (std::size_t i = 0; i != N+1; ++i) dp[i] = std::vector<int>(i+1);

            // dp[N][j] = 0
            for (std::size_t j = 0; j != N+1; ++j) dp[N][j] = 0;
        }

        for (std::size_t ri = 0; ri != N; ++ri) {
            std::size_t i = (N-1) - ri;  // i = N-1 ~ 0
            for (std::size_t j = 0; j != i+1; ++j) {
                dp[i][j] = std::min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }

        return dp[0][0];
    }
};
