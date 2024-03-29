// Title: Number of Islands
// Description:
//     Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
//     An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
//     You may assume all four edges of the grid are all surrounded by water.
// Link: https://leetcode.com/problems/number-of-islands/

// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;

        const std::size_t M = grid.size();
        const std::size_t N = grid[0].size();
        
        std::vector<std::vector<bool>> isTraversed(M, std::vector<bool>(N, false));
        
        std::function<bool (std::size_t, std::size_t)> searchIsland = [&, M, N](std::size_t i, std::size_t j) -> bool {
            if (isTraversed[i][j] || grid[i][j] != '1') return false;
            
            isTraversed[i][j] = true;
            
            if (i != 0) searchIsland(i-1, j);
            if (i != M-1) searchIsland(i+1, j);
            if (j != 0) searchIsland(i, j-1);
            if (j != N-1) searchIsland(i, j+1);
            
            return true;
        };
        
        std::size_t islandCount = 0;

        for (std::size_t i = 0; i != M; ++i) {
            for (std::size_t j = 0; j != N; ++j) {                
                if (searchIsland(i, j)) ++islandCount;
            }
        }
            
        return islandCount;
    }
};
