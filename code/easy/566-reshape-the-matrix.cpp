// Title: Reshape the Matrix
// Description:
//     In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.
//     You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.
//     The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
//     If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
// Link: https://leetcode.com/problems/reshape-the-matrix/

// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>> &mat, int r, int c) {
        std::size_t M = mat.size();
        std::size_t N = mat[0].size();
        
        // check illegal reshape
        if (r * c != M * N) return mat;
        
        // initialize result matrix and indexes
        std::vector<std::vector<int>> result(r, std::vector<int>(c));
        std::size_t ri = 0, rj = 0;
        
        // read from the source matrix
        for (std::size_t i = 0; i != M; ++i) {
            for (std::size_t j = 0; j != N; ++j) {
                // copy element to the result matrix
                result[ri][rj++] = mat[i][j];
                
                // process line wrapping for the result matrix
                if (rj == c) ++ri, rj = 0;
            }
        }
        
        return result;
    }
};
