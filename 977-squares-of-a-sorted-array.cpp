// Title: Squares of a Sorted Array
// Description:
//     Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
// Link: https://leetcode.com/problems/squares-of-a-sorted-array/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::vector<int> result;
        
        // handle edge case
        if (nums.size() == 0) return vector<int>();
        
        // merge numbers from both sides
        std::size_t i = 0, j = nums.size() - 1;
        while (i != j) {
            int a = nums[i], b = nums[j];
            
            // take the larger squared number
            if (a * a > b * b) {
                result.push_back(a * a); ++i;
            } else {
                result.push_back(b * b); --j;
            }
        }
        
        // take the last number
        result.push_back(nums[i] * nums[j]);
        
        // reverse the result so the result is in ascending order
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};
