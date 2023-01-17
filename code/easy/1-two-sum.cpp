// Title: Two Sum
// Description:
//     Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//     You may assume that each input would have exactly one solution, and you may not use the same element twice.
//     You can return the answer in any order.
// Link: https://leetcode.com/problems/two-sum/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        const std::size_t N = nums.size();

        std::unordered_map<int, std::size_t> indexOfNumber;
        
        for (std::size_t i = 0; i != N; ++i) {
            int num = nums[i];
            int anotherNum = target - num;
            
            if (indexOfNumber.count(anotherNum) != 0) {
                // return both indexes if the remaining half of the target exists
                return { (int) indexOfNumber[anotherNum], (int) i };
            } else {
                // save the index of the number
                indexOfNumber[num] = i;
            }
        }
        
        // not found (should not be reached)
        return {};
    }
};
