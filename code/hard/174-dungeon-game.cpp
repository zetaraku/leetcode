// Title: Dungeon Game
// Description:
//     The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon.
//     The dungeon consists of m x n rooms laid out in a 2D grid.
//     Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.
//     The knight has an initial health point represented by a positive integer.
//     If at any point his health point drops to 0 or below, he dies immediately.
//     Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms;
//     other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).
//     To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
//     Return the knight's minimum initial health so that he can rescue the princess.
//     Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
// Link: https://leetcode.com/problems/dungeon-game/

// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>> &dungeon) {
        const std::size_t M = dungeon.size();
        const std::size_t N = dungeon[0].size();

        /*
            dp[i][j] = minimum health required at room (i, j) to reach the goal (M-1, N-1) alive
                     = minimum health required of down room (i+1, j) and right room (i, j+1)
                       - health gain at (i, j)
                       + health loss at (i, j)
                       (the value must be at least 1 to survive)
                     = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j])
        */
        std::vector<std::vector<int>> dp(M, std::vector<int>(N));

        /* base case: */ {
            dp[M-1][N-1] = std::max(1, 1 - dungeon[M-1][N-1]);
        }
        for (int i = M-2; i >= 0; --i) {
            dp[i][N-1] = std::max(1, dp[i+1][N-1] - dungeon[i][N-1]);
        }
        for (int j = N-2; j >= 0; --j) {
            dp[M-1][j] = std::max(1, dp[M-1][j+1] - dungeon[M-1][j]);
        }
        for (int i = M-2; i >= 0; --i) {
            for (int j = N-2; j >= 0; --j) {
                dp[i][j] = std::max(1, std::min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
            }
        }

        // return the minimum health required at top-left room (0, 0) to reach the goal (m-1, n-1) alive
        return dp[0][0];
    }

    /* Insight: Notice the base case starts at the bottom-right corner */
};
