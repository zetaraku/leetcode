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
        // the end index of consecutive non-zero elements starting from the beginning
        vector<int>::size_type tail = 0;
        
        // starting from left to right
        for (auto i = 0; i < nums.size(); i++) {
            // if we encounter a non-zero element
            if (nums.at(i) != 0) {
                // move it back to the tail of the consecutive non-zero partition
                std::swap(nums.at(tail), nums.at(i));
                // extend the right bound of the consecutive non-zero partition
                tail++;
            }
        }
    }
};
