// Title: Find the Kth Largest Integer in the Array
// Description:
//     You are given an array of strings nums and an integer k.
//     Each string in nums represents an integer without leading zeros.
//     Return the string that represents the kth largest integer in nums.
//     Note:
//         Duplicate numbers should be counted distinctly.
//         For example, if nums is ["1","2","2"], "2" is the first largest integer,
//         "2" is the second-largest integer, and "1" is the third-largest integer.
// Link: https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    std::string kthLargestNumber(std::vector<std::string> &nums, int k) {
        auto target = nums.end() - k;

        /*
            void std::nth_element(first, nth, last, comp):
                Rearranges the elements in the range [first,last),
                in such a way that the element at the nth position is the element
                that would be in that position in a sorted sequence.
        */
        std::nth_element(
            nums.begin(), target, nums.end(),
            [](std::string a, std::string b) {
                // If the two numbers have different lengths,
                // then the number with more digits is larger.
                if (a.length() != b.length()) return a.length() < b.length();

                // Otherwise, the two numbers have the same length,
                // just compare them with lexicographical order.
                // Note: The time complexity of this comparison is actually O(len(a)+len(b))
                return a < b;
            }
        );

        return *target;
    }
};
