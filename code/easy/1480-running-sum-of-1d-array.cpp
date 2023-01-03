// Title: Running Sum of 1d Array
// Description:
//     Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
//     Return the running sum of nums.
// Link: https://leetcode.com/problems/running-sum-of-1d-array/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    std::vector<int> runningSum(std::vector<int> &nums) {
        std::vector<int> result;

        std::partial_sum(nums.begin(), nums.end(), std::back_inserter(result), std::plus<int>());
        
        return result;
    }
};
