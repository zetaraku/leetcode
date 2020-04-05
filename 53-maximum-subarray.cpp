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
        int accumulatedSum = 0;
        int maxAccumulatedSum = std::numeric_limits<int>::min();
        
        // accumulate the sum from left to right
        for (int num: nums) {
            // extend one number toward the right
            accumulatedSum += num;
            
            // update the max sum (should contain at least one number)
            // this may be negative and should be done first!
            if (accumulatedSum > maxAccumulatedSum)
                maxAccumulatedSum = accumulatedSum;
                
            // empty the sum if it is negative (useless)
            if (accumulatedSum < 0)
                accumulatedSum = 0;
        }
        
        return maxAccumulatedSum;
    }
};
