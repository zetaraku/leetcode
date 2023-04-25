// Title: Squares of a Sorted Array
// Description:
//     Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
// Link: https://leetcode.com/problems/squares-of-a-sorted-array/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int> &nums) {
        const std::size_t N = nums.size();

        std::vector<int> result(N); std::size_t prevIndex = N;
        
        // remaining range [i, j) to process
        std::size_t i = 0, j = N;

        // merge squared numbers from both sides
        while (i != j) {
            int a = nums[i], b = nums[j-1];
            
            // take the larger squared number
            if (a * a > b * b) {
                result[--prevIndex] = a * a; ++i;
            } else {
                result[--prevIndex] = b * b; --j;
            }
        }
        
        return result;
    }
};
