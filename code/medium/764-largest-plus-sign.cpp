// Title: Largest Plus Sign
// Description:
//     You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines.
//     The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.
//     Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.
//     An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's.
//     Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.
// Link: https://leetcode.com/problems/largest-plus-sign/

// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        // binary grid (true = 1, false = 0)
        std::vector<std::vector<bool>> grid(n, std::vector<bool>(n, true));
        for (vector<int> mine: mines) {
            grid[mine[0]][mine[1]] = false;
        }
        
        // the order of largest plus sign centered at (i, j) is constrained by four arms
        std::vector<std::vector<int>> minOrder(n, std::vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            // apply left arm constraint
            for (int j = 0, acc = 0; j < n; j++) {
                acc = grid[i][j] ? acc + 1 : 0;
                minOrder[i][j] = std::min(acc, minOrder[i][j]);
            }
            // apply right arm constraint
            for (int j = n-1, acc = 0; j >= 0; j--) {
                acc = grid[i][j] ? acc + 1 : 0;
                minOrder[i][j] = std::min(acc, minOrder[i][j]);
            }
        }
        for (int j = 0; j < n; j++) {
            // apply upper arm constraint
            for (int i = 0, acc = 0; i < n; i++) {
                acc = grid[i][j] ? acc + 1 : 0;
                minOrder[i][j] = std::min(acc, minOrder[i][j]);
            }
            // apply lower arm constraint
            for (int i = n-1, acc = 0; i >= 0; i--) {
                acc = grid[i][j] ? acc + 1 : 0;
                minOrder[i][j] = std::min(acc, minOrder[i][j]);
            }
        }
        
        // find the largest plus sign
        int maxOrder = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxOrder = std::max(minOrder[i][j], maxOrder);
            }
        }
        
        return maxOrder;
    }
};
