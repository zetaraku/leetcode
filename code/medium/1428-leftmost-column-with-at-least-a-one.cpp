// Title: Leftmost Column with at Least a One
// Description:
//     (This problem is an interactive problem.)
//     A binary matrix means that all elements are 0 or 1.
//     For each individual row of the matrix, this row is sorted in non-decreasing order.
//     Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it.
//     If such index doesn't exist, return -1.
//     You can't access the Binary Matrix directly.
//     You may only access the matrix using a BinaryMatrix interface:
//         BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
//         BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
//     Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.
//     Also, any solutions that attempt to circumvent the judge will result in disqualification.
//     Hint #1: (Binary Search)
//         For each row do a binary search to find the leftmost one on that row and update the answer.
//     Hint #2: (Optimal Approach)
//         Imagine there is a pointer p(x, y) starting from top right corner.
//         p can only move left or down. If the value at p is 0, move down. If the value at p is 1, move left.
//         Try to figure out the correctness and time complexity of this algorithm.
// Link: https://leetcode.com/problems/leftmost-column-with-at-least-a-one/

// Time complexity: O(r+c)
// Space complexity: O(1)
// Variables:
//     r = number of rows
//     c = number of columns
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        int r = dimensions.at(0), c = dimensions.at(1);
        
        // we go from the top-right corner
        int i = 0, lowJ = c;
        // and keep moving left or down if we haven't reached the buttom or the left-border
        while (i != r && lowJ != 0) {
            // get the next value we want to try
            int value = binaryMatrix.get(i, lowJ-1);
            
            if (value == 1) {
                // move to the left column if it's 1 on column j
                lowJ--;
            } else {
                // move on to the next row if it's 0 on column j
                i++;
            }
        }
        
        // return -1 if we didn't find any 1
        return (lowJ != c ? lowJ : -1);
    }
};
