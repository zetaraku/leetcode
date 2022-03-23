// Title: Rotate Image
// Description:
//     You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
//     You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
//     DO NOT allocate another 2D matrix and do the rotation.
// Link: https://leetcode.com/problems/rotate-image/

// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        std::size_t N = matrix.size(), Z = N - 1;
        
        // rotate by the four quarter triangles
        for (int i = 0; i < N/2; i++) {
            for (int j = i; j < Z-i; j++) {
                int &U = matrix[0+i][0+j];
                int &R = matrix[0+j][Z-i];
                int &D = matrix[Z-i][Z-j];
                int &L = matrix[Z-j][0+i];
                std::tie(R, D, L, U) = std::make_tuple(U, R, D, L);
            }
        }
    }
};
