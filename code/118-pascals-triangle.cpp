// Title: Pascal's Triangle
// Description:
//     Given an integer numRows, return the first numRows of Pascal's triangle.
//     In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// Link: https://leetcode.com/problems/pascals-triangle/

// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result;
        
        std::vector<int> row;
        for (std::size_t i = 0; i != numRows; ++i) {
            // add a new space to the tail (fill 1 if it's the first)
            row.push_back(i == 0 ? 1 : 0);
            
            // add each number to its next number
            for (std::size_t j = i; j != 0; --j) {
                row[j] += row[j-1];
            }
            
            // add the row to the result
            result.push_back(row);
        }
        
        return result;
    }
};
