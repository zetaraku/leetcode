// Title: Contains Duplicate
// Description:
//     Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
// Link: https://leetcode.com/problems/contains-duplicate/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> numberSet;
        
        // for each number
        for (int num: nums) {
            // insert the number into the set
            auto [_, inserted] = numberSet.insert(num);
            
            // return true if a number is already in the set
            if (!inserted) return true;
        }
        
        // every element is distinct
        return false;
    }
};
