// Title: 01 Matrix
// Description:
//     Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
//     The distance between two adjacent cells is 1.
// Link: https://leetcode.com/problems/01-matrix/

// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat) {
        assert(mat.size() != 0 && mat[0].size() != 0);

        const std::size_t M = mat.size();
        const std::size_t N = mat[0].size();

        std::vector<std::vector<int>> nearestDistance(M, std::vector<int>(N, INT_MAX));

        std::queue<std::pair<std::size_t, std::size_t>> processingQueue; {
            // for each 0 cell, set its nearestDistance as 0 and put it into the processingQueue
            for (std::size_t i = 0; i != M; ++i) {
                for (std::size_t j = 0; j != N; ++j) {
                    if (mat[i][j] == 0) {
                        nearestDistance[i][j] = 0;
                        processingQueue.push({ i, j });
                    }
                }
            }
        }

        // Breadth-First Search (with multiple sources)
        while (!processingQueue.empty()) {
            auto [i, j] = processingQueue.front(); processingQueue.pop();

            // for each neighbor cell of which the nearestDistance is not yet determined,
            // set its nearestDistance and put it into the processingQueue
            if (i != 0 && nearestDistance[i-1][j] == INT_MAX) {
                nearestDistance[i-1][j] = nearestDistance[i][j] + 1;
                processingQueue.push({ i-1, j });
            }
            if (i != M-1 && nearestDistance[i+1][j] == INT_MAX) {
                nearestDistance[i+1][j] = nearestDistance[i][j] + 1;
                processingQueue.push({ i+1, j });
            }
            if (j != 0 && nearestDistance[i][j-1] == INT_MAX) {
                nearestDistance[i][j-1] = nearestDistance[i][j] + 1;
                processingQueue.push({ i, j-1 });
            }
            if (j != N-1 && nearestDistance[i][j+1] == INT_MAX) {
                nearestDistance[i][j+1] = nearestDistance[i][j] + 1;
                processingQueue.push({ i, j+1 });
            }
        }

        return nearestDistance;
    }
};
