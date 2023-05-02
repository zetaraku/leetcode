// Title: Max Area of Island
// Description:
//     You are given an m x n binary matrix grid.
//     An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)
//     You may assume all four edges of the grid are surrounded by water.
//     The area of an island is the number of cells with a value 1 in the island.
//     Return the maximum area of an island in grid. If there is no island, return 0.
// Link: https://leetcode.com/problems/max-area-of-island/

// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;

        const std::size_t M = grid.size();
        const std::size_t N = grid[0].size();
        
        std::vector<std::vector<bool>> isTraversed(M, std::vector<bool>(N, false));
        
        std::function<std::size_t (std::size_t, std::size_t)> searchIsland = [&, M, N](std::size_t i, std::size_t j) -> std::size_t {
            if (isTraversed[i][j] || grid[i][j] != 1) return 0;
            
            isTraversed[i][j] = true;

            std::size_t area = 1;
            
            if (i != 0) area += searchIsland(i-1, j);
            if (i != M-1) area += searchIsland(i+1, j);
            if (j != 0) area += searchIsland(i, j-1);
            if (j != N-1) area += searchIsland(i, j+1);
            
            return area;
        };
        
        std::size_t maxArea = 0;

        for (std::size_t i = 0; i != M; ++i) {
            for (std::size_t j = 0; j != N; ++j) {                
                maxArea = std::max(searchIsland(i, j), maxArea);
            }
        }
            
        return maxArea;
    }
};
