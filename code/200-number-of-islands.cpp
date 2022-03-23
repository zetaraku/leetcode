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
    int numIslands(vector<vector<char>> &grid) {
        int r = grid.size();
        if (r == 0)
            return 0;
        
        int c = grid.at(0).size();
        if (c == 0)
            return 0;
        
        int islandCount = 0;
        vector<vector<bool>> isTraversed(r, vector<bool>(c, false));
        
        std::function<bool(int,int)> searchIsland = [&] (int i, int j) -> bool {
            // this grid is water, no new island found
            if (grid.at(i).at(j) == '0')
                return false;
            
            // this grid is counted before, no new island found
            if (isTraversed.at(i).at(j))
                return false;
            
            // a new grid is found, now mark this grid as traversed
            isTraversed.at(i).at(j) = true;
            
            // search for all connected grids and mark them
            if (i-1 >= 0)
                searchIsland(i-1, j);
            if (i+1 < r)
                searchIsland(i+1, j);
            if (j-1 >= 0)
                searchIsland(i, j-1);
            if (j+1 < c)
                searchIsland(i, j+1);
            
            // we found a new island!
            return true;
        };
        
        // increase the island count for each new island we found
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                searchIsland(i, j) && islandCount++;
            
        return islandCount;
    }
};
