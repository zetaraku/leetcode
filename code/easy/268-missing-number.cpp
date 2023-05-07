// Title: Missing Number
// Description:
//     Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
// Link: https://leetcode.com/problems/missing-number/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int missingNumber(std::vector<int> &nums) {
        const std::size_t N = nums.size();

        // we can XOR numbers from 0 ~ N with numbers in nums so that each number in nums will cancel out the number from 0 ~ N, leaving the missing one.
        int result = N;
        for (std::size_t i = 0; i != N; ++i) {
            // number from 0 ~ N (including the initial N)
            result ^= i;

            // number in nums
            result ^= nums[i];
        }

        return result;
    }
};
