// Title: Binary Search
// Description:
//     Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.
//     If target exists, then return its index. Otherwise, return -1.
//     You must write an algorithm with O(log n) runtime complexity.
// Link: https://leetcode.com/problems/binary-search/

// Time complexity: O(log(n))
// Space complexity: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        std::size_t begin = 0, end = nums.size();
        
        // keep searching if the interval is not empty
        while (begin != end) {
            // locate the middle index
            std::size_t mid = begin + (end - begin) / 2;
            
            if (nums[mid] < target) {
                // eliminate the smaller half
                begin = mid + 1;
            } else if (nums[mid] > target) {
                // eliminate the bigger half
                end = mid;
            } else {
                // the target is found
                return mid;
            }
        }
        
        // the target is not found
        return -1;
    }
};
