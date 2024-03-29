// Title: Reverse String
// Description:
//     Write a function that reverses a string.
//     The input string is given as an array of characters s.
// Link: https://leetcode.com/problems/reverse-string/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    void reverseString(std::vector<char> &s) {
        // handle edge case
        if (s.size() == 0) return;

        // swap each pair from both sides
        for (std::size_t i = 0, j = s.size() - 1; i < j; ++i, --j) {
            std::swap(s[i], s[j]);
        }
    }
};
