// Title: Move Zeroes
// Description:
//     Given an array nums, write a function to move all 0's to the end of it
//     while maintaining the relative order of the non-zero elements.
// Link: https://leetcode.com/problems/move-zeroes/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // the next insertion point of non-0 sub array
        std::size_t i = 0;
        
        for (std::size_t j = 0; j != nums.size(); ++j) {
            // move each non-0 element to the begin so all other 0 will be at the end
            if (nums[j] != 0) {
                std::swap(nums[i], nums[j]); i++;
            }
        }
    }
};
