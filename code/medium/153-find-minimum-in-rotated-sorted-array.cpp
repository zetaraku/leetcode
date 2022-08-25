// Title: Find Minimum in Rotated Sorted Array
// Description:
//     Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
//         - [4,5,6,7,0,1,2] if it was rotated 4 times.
//         - [0,1,2,4,5,6,7] if it was rotated 7 times.
//     Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
//     Given the sorted rotated array nums of unique elements, return the minimum element of this array.
//     You must write an algorithm that runs in O(log n) time.
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Time complexity: O(log(n))
// Space complexity: O(log(n))
class Solution {
public:
    int findMin(std::vector<int> &nums) {
        // this function only works with non-empty input
        assert(nums.size() != 0);
        
        return findMin(nums, 0, nums.size() - 1);
    }
    
    int findMin(std::vector<int> &nums, std::size_t headIndex, std::size_t tailIndex) {
        // if the range contains exactly one element
        if (headIndex == tailIndex) {
            // the minimum element is the only element
            return nums[headIndex];
        }
        
        // locate the mid index (if odd) or the left-mid index (if even)
        std::size_t midIndex = headIndex + (tailIndex - headIndex) / 2;
        
        if (nums[midIndex] < nums[tailIndex]) {
            // if [midIndex, tailIndex] is in ascending order (no decending happens within)
            
            // the minimum element cannot be in (midIndex, tailIndex],
            // we can omit (midIndex, tailIndex] and search in [headIndex, midIndex] instead
            return findMin(nums, headIndex, midIndex);
        } else {
            // otherwise, a decending must happens somewhere within [midIndex, tailIndex]
            
            // the minimum element must be in (midIndex, tailIndex],
            // we can omit [headIndex, midIndex] and search in (midIndex, tailIndex] instead
            return findMin(nums, midIndex + 1, tailIndex);
        }
    }
};
