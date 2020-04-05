// Problem:
//     Given a non-empty array of integers, every element appears twice except for one. Find that single one.
// Link: https://leetcode.com/problems/single-number/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        // we can XOR every number so that integers which appear twice will cancel each other out, leaving the single one.
        for (int num: nums) {
            result ^= num;
        }
        
        return result;
    }
};
