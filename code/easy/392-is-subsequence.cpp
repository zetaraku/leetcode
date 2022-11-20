// Title: Is Subsequence
// Description:
//     Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
//     A subsequence of a string is a new string that is formed from the original string
//     by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
//     (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
//     Follow up:
//     Suppose there are lots of incoming s, say s[1], s[2], ..., s[k] where k >= 10^9,
//     and you want to check one by one to see if t has its subsequence.
//     In this scenario, how would you change your code?
// Link: https://leetcode.com/problems/is-subsequence/

// Time complexity: O(m+n)
// Space complexity: O(1)
class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        for (std::size_t i = 0, j = 0; true; ++i, ++j) {
            // s is a subsequence of t if s is full matched
            if (i == s.length()) return true;
            
            // skip any unmatched chars in string t
            while (j != t.length() && t[j] != s[i]) ++j;
            
            // s is not a subsequence of t if t is exhausted while s is not full matched
            if (j == t.length()) return false;
        }
    }
};
