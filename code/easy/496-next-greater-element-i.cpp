// Title: Next Greater Element I
// Description:
//     The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
//     You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
//     For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
//     If there is no next greater element, then the answer for this query is -1.
//     Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
// Link: https://leetcode.com/problems/next-greater-element-i/

#include <ranges>

// Time complexity: O(n1+n2)
// Space complexity: O(n1+n2)
class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2) {
        // nextGreaterNum[n] = the next greater number of number n
        std::unordered_map<int, int> nextGreaterNum;

        // the monotonic stack built from right side of nums2
        std::stack<int> stack;

        // for each number in nums2, from right to left
        for (int num: nums2 | std::views::reverse) {
            // pop out equal or smaller numbers so the right stack maintains an (strictly) increasing order
            while (!stack.empty() && stack.top() <= num) stack.pop();

            // the current leftmost number in the stack will be the next greater number of the current number (if any)
            nextGreaterNum.emplace(num, !stack.empty() ? stack.top() : -1);

            // push itself onto the stack
            stack.push(num);
        }

        std::vector<int> result;

        // map nums1 to the result
        for (int num: nums1) {
            result.push_back(nextGreaterNum.at(num));
        }

        return result;
    }
};
