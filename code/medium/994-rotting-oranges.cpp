// Title: Rotting Oranges
// Description:
//     You are given an m x n grid where each cell can have one of three values:
//         0 representing an empty cell,
//         1 representing a fresh orange, or
//         2 representing a rotten orange.
//     Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
//     Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
// Link: https://leetcode.com/problems/rotting-oranges/

// Time complexity: O(m*n)
// Space complexity: O(m*n)
#define EMPTY_CELL 0
#define FRESH_ORANGE 1
#define ROTTEN_ORANGE 2

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>> &grid) {
        assert(grid.size() != 0 && grid[0].size() != 0);

        const std::size_t M = grid.size();
        const std::size_t N = grid[0].size();

        std::size_t freshOrangeCount = 0;

        std::queue<std::pair<std::size_t, std::size_t>> processingQueue; {
            for (std::size_t i = 0; i != M; ++i) {
                for (std::size_t j = 0; j != N; ++j) {
                    if (grid[i][j] == FRESH_ORANGE) {
                        // count each fresh orange
                        ++freshOrangeCount;
                    } else if (grid[i][j] == ROTTEN_ORANGE) {
                        // enqueue each rotten orange
                        processingQueue.push({ i, j });
                    }
                }
            }

            // put an "end-of-minute" marker at the end
            processingQueue.push({ SIZE_MAX, SIZE_MAX });
        }

        // time start at minute 0
        int minutesElapsed = 0;

        // Breadth-First Search (with multiple sources)
        while (true) {
            // take a new rotten orange out
            auto [i, j] = processingQueue.front(); processingQueue.pop();

            // at the end of minute, check if there is any new rotten orange:
            if (i == SIZE_MAX && j == SIZE_MAX) {
                if (!processingQueue.empty()) {
                    // some oranges have become rotten within this minute and a minute has passed
                    ++minutesElapsed;
                    // put another "end-of-minute" marker at the end
                    processingQueue.push({ SIZE_MAX, SIZE_MAX });
                } else {
                    // no orange has become rotten within this minute, the process has already ended
                    break;
                }
                continue;
            }

            // make each fresh neighbor orange rotten
            if (i != 0 && grid[i-1][j] == FRESH_ORANGE) {
                grid[i-1][j] = ROTTEN_ORANGE;
                --freshOrangeCount;
                processingQueue.push({ i-1, j });
            }
            if (i != M-1 && grid[i+1][j] == FRESH_ORANGE) {
                grid[i+1][j] = ROTTEN_ORANGE;
                --freshOrangeCount;
                processingQueue.push({ i+1, j });
            }
            if (j != 0 && grid[i][j-1] == FRESH_ORANGE) {
                grid[i][j-1] = ROTTEN_ORANGE;
                --freshOrangeCount;
                processingQueue.push({ i, j-1 });
            }
            if (j != N-1 && grid[i][j+1] == FRESH_ORANGE) {
                grid[i][j+1] = ROTTEN_ORANGE;
                --freshOrangeCount;
                processingQueue.push({ i, j+1 });
            }
        }

        // return minutesElapsed if there is no more fresh orange, -1 otherwise
        return freshOrangeCount == 0 ? minutesElapsed : -1;
    }
};
