// Title: Number of Islands
// Description:
//     Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
//     An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
//     You may assume all four edges of the grid are all surrounded by water.
// Link: https://leetcode.com/problems/number-of-islands/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;

        const std::size_t m = grid.size();
        const std::size_t n = grid[0].size();
        
        std::size_t islandCount = 0;
        std::vector<std::vector<bool>> isTraversed(m, std::vector<bool>(n, false));
        
        std::function<bool (std::size_t, std::size_t)> searchIsland = [&, m, n](std::size_t i, std::size_t j) -> bool {
            if (isTraversed[i][j] || grid[i][j] == '0') return false;
            
            isTraversed[i][j] = true;
            
            if (i != 0) searchIsland(i-1, j);
            if (i != m-1) searchIsland(i+1, j);
            if (j != 0) searchIsland(i, j-1);
            if (j != n-1) searchIsland(i, j+1);
            
            return true;
        };
        
        for (std::size_t i = 0; i != m; ++i) {
            for (std::size_t j = 0; j != n; ++j) {                
                searchIsland(i, j) && ++islandCount;
            }
        }
            
        return islandCount;
    }
};
