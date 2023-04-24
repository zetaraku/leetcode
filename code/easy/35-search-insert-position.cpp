// Title: Search Insert Position
// Description:
//     Given a sorted array of distinct integers and a target value, return the index if the target is found.
//     If not, return the index where it would be if it were inserted in order.
//     You must write an algorithm with O(log n) runtime complexity.
// Link: https://leetcode.com/problems/search-insert-position/

// Time complexity: O(log(n))
// Space complexity: O(1)
class Solution {
public:
    int searchInsert(std::vector<int> &nums, int target) {
        std::size_t begin = 0, end = nums.size();
        
        // keep searching until the interval is empty (the borders meet)
        while (begin != end) {
            // locate the middle index
            std::size_t mid = begin + (end - begin) / 2;
            
            if (nums[mid] < target) {
                // move the left border to the right of the number
                begin = mid + 1;
            } else if (nums[mid] > target) {
                // move the right border to the left of the number
                end = mid;
            } else {
                // the target is found
                return mid;
            }
        }
        
        // the target is not found, return the index to insert
        return begin;
    }
};
