// Title: Find Pivot Index
// Description:
//     Given an array of integers nums, calculate the pivot index of this array.
//     The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
//     If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
//     Return the leftmost pivot index. If no such index exists, return -1.
// Link: https://leetcode.com/problems/find-pivot-index/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int pivotIndex(std::vector<int> &nums) {
        const std::size_t N = nums.size();

        int totalSum = std::reduce(nums.begin(), nums.end(), 0, std::plus<int>());

        int currentSum = 0;
        for (int pivotIndex = 0; pivotIndex != N; ++pivotIndex) {
            int leftSum = currentSum;
            int rightSum = totalSum - nums[pivotIndex] - leftSum;

            if (leftSum == rightSum) return pivotIndex;

            currentSum += nums[pivotIndex];
        }
        
        return -1;
    }
};
