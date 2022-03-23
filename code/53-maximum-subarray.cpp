// Title: Maximum Subarray
// Description:
//     Given an integer array nums,
//     find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// Link: https://leetcode.com/problems/maximum-subarray/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int partialSum = 0;
        int largestSum = INT_MIN;
        
        // greedy strategy
        for (int num: nums) {
            // add the value to the subarray
            partialSum += num;
            
            // update the max value
            largestSum = std::max(partialSum, largestSum);
            
            // discard the subarray if the sum is already negative
            if (partialSum < 0) partialSum = 0;
        }
        
        return largestSum;
    }
};
