// Title: Search in Rotated Sorted Array
// Description:
//     Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//     (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//     You are given a target value to search. If found in the array return its index, otherwise return -1.
//     You may assume no duplicate exists in the array.
//     Your algorithm's runtime complexity must be in the order of O(log n).
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

// Time complexity: O(log(n))
// Space complexity: O(log(n))
class Solution {
public:
    int search(vector<int> &nums, int target) {
        return rotatedSearch(nums, 0, (int)nums.size()-1, target);
    }
    
    int rotatedSearch(vector<int> &nums, int from, int to, int target) {
        // the target cannot be found if the range is empty
        if (to < from)
            return -1;
        
        int mid = (from + to) / 2;
        int fromValue = nums.at(from);
        int midValue = nums.at(mid);
        int toValue = nums.at(to);
        
        if (target == midValue)
            return mid;
        
        if (fromValue <= midValue) {
            // if the left part is sorted in non-decreasing order
            if (fromValue <= target && target <= midValue) {
                // if the target is in this range
                // we search it by binary search as usual
                return binarySearch(nums, from, mid-1, target);
            } else {
                // otherwise, the other part will be a rotated sorted array with smaller and larger values
                // we serach it by rotated search instead
                return rotatedSearch(nums, mid+1, to, target);
            }
        } else if (midValue <= toValue) {
            // otherwise, the right part will be sorted in non-decreasing order
            if (midValue <= target && target <= toValue) {
                return binarySearch(nums, mid+1, to, target);
            } else {
                return rotatedSearch(nums, from, mid-1, target);
            }
        } else {
            return -1;  // unreachable
        }
    }
    
    int binarySearch(vector<int> &nums, int from, int to, int target) {
        if (to < from)
            return -1;
        
        int mid = (from + to) / 2;
        int midValue = nums.at(mid);
        
        if (target == midValue)
            return mid;
        
        if (target < midValue) {
            return binarySearch(nums, from, mid-1, target);
        } else if (target > midValue) {
            return binarySearch(nums, mid+1, to, target);
        } else {
            return -1;  // unreachable
        }
    }
};
