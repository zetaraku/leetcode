// Title: Next Greater Element II
// Description:
//     Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
//     The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number.
//     If it doesn't exist, return -1 for this number.
// Link: https://leetcode.com/problems/next-greater-element-ii/

#include <ranges>

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int> &nums) {
        // nextGreaterNum[i] = the next greater number for nums[i]
        std::vector<int> nextGreaterNum(nums.size());

        // the monotonic stack built from right to left of nums
        std::stack<int> stack;

        // do it twice so we can search through the border
        for (std::size_t count = 0; count != 2; ++count) {
            /*
                Insight:
                If the number would find its next greater number at the first pass,
                it will also find the same number again at the second pass.
                If not, it can search the remaining numbers behind it at the second pass.
            */

            // for each number in nums, from right to left
            for (std::size_t i: std::views::iota((std::size_t) 0, nums.size()) | std::views::reverse) {
                int num = nums[i];
                
                // pop out equal or smaller numbers so the right stack maintains an (strictly) increasing order
                while (!stack.empty() && stack.top() <= num) stack.pop();

                // the current leftmost number in the stack will be the next greater number of the current number (if any)
                nextGreaterNum[i] = !stack.empty() ? stack.top() : -1;

                // push itself onto the stack
                stack.push(num);
            }
        }

        return nextGreaterNum;
    }
};
