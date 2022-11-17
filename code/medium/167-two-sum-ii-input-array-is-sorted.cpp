// Title: Two Sum II - Input Array Is Sorted
// Description:
//     Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
//     Let these two numbers be numbers[index1] and numbers[index2] where 1 <= first < second <= numbers.length.
//     Return the indices of the two numbers, index1 and index2, as an integer array [index1, index2] of length 2.
//     The tests are generated such that there is exactly one solution. You may not use the same element twice.
// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // pick the numbers at the start and at the end
        int i = 0, j = numbers.size() - 1;
        
        while (true) {
            // try to sum them up
            int sum = numbers[i] + numbers[j];
            
            if (sum < target) {
                // drop the one that is too small
                i++;
            } else if (sum > target) {
                // drop the one that is too big
                j--;
            } else {
                // found the solution (guaranteed)
                std::vector<int> result = { 1 + i, 1 + j };
                return result;
            }
        }
    }
};
