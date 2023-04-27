// Title: Single Number
// Description:
//     Given a non-empty array of integers, every element appears twice except for one. Find that single one.
// Link: https://leetcode.com/problems/single-number/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int singleNumber(std::vector<int> &nums) {
        // we can XOR every number so that integers which appear twice will cancel each other out, leaving the single one.
        return std::reduce(nums.begin(), nums.end(), 0, std::bit_xor<int>());
    }
};
