// Title: Array Nesting
// Description:
//     You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].
//     You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:
//         The first element in s[k] starts with the selection of the element nums[k] of index = k.
//         The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
//         We stop adding right before a duplicate element occurs in s[k].
//     Return the longest length of a set s[k].
// Link: https://leetcode.com/problems/array-nesting/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        std::vector<bool> visited(nums.size(), false);
        int maxLen = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // skip visited indexes to avoid O(n^2) time complexity
            if (visited[i] == true) continue;
            
            int len = 0;
            int j = i;
            do {
                // mark the index
                visited[j] = true;
                // count the length
                len++;
                // jump to the next index
                j = nums[j];
            } while (j != i);   // stop when the next index is the head
            
            // record the max length
            maxLen = std::max(len, maxLen);
        }
        
        return maxLen;
    }
};
