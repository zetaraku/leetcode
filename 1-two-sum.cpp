// Title: <Insert Problem Name>
// Description:
//     Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//     You may assume that each input would have exactly one solution, and you may not use the same element twice.
//     You can return the answer in any order.
// Link: https://leetcode.com/problems/two-sum/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> indexOfNumber;
        
        for (int i = 0; i != nums.size(); ++i) {
            int num = nums[i];
            
            if (indexOfNumber.count(target - num) != 0) {
                // return both indexes if the remaining half of the target exists
                std::vector<int> result = { indexOfNumber[target - num], i };
                return result;
            } else {
                // save the index of the number
                indexOfNumber[num] = i;
            }
        }
        
        return std::vector<int>();
    }
};
