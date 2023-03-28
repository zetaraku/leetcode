// Title: Flood Fill
// Description:
//     An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
//     You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
//     To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
//     Return the modified image after performing the flood fill.
// Link: https://leetcode.com/problems/flood-fill/

// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int color) {
        const std::size_t M = image.size();
        const std::size_t N = image[0].size();

        // the target color to replace
        int targetColor = image[sr][sc];

        // we *must* skip the whole process if the target pixel is already in the chosen color
        // otherwise, the process will fall into an infinity loop
        if (targetColor == color) return image;

        // perform a depth-first search (DFS)
        std::stack<std::pair<std::size_t, std::size_t>> processingStack; {
            processingStack.push({ sr, sc });
        }

        while (!processingStack.empty()) {
            auto [r, c] = processingStack.top(); processingStack.pop();

            // skip this pixel if it is not in the target color
            if (image[r][c] != targetColor) continue;

            // replace the color of this pixel
            image[r][c] = color;

            // push all connected pixels into the processingStack
            if (r > 0) processingStack.push({ r-1, c });
            if (r < M-1) processingStack.push({ r+1, c });
            if (c > 0) processingStack.push({ r, c-1 });
            if (c < N-1) processingStack.push({ r, c+1 });
        }

        return image;
    }
};
