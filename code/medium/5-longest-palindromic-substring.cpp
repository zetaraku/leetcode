// Title: Longest Palindromic Substring
// Description:
//     Given a string s, return the longest palindromic substring in s.
// Link: https://leetcode.com/problems/longest-palindromic-substring/

// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        const std::size_t N = s.size();

        std::size_t maxBegin = 0, maxLength = 0;
        
        for (std::size_t coreBegin = 0, coreEnd; coreEnd = coreBegin + 1, coreBegin != N; coreBegin = coreEnd) {
            // expend the core
            while (coreEnd != N && s[coreEnd] == s[coreBegin]) ++coreEnd;

            // set the palindrome to the core
            std::size_t pBegin = coreBegin, pEnd = coreEnd;

            // expend the palindrome
            while (pBegin != 0 && pEnd != N && s[pBegin-1] == s[pEnd]) --pBegin, ++pEnd;

            // record the new longest palindromic substring
            if (pEnd - pBegin > maxLength) maxBegin = pBegin, maxLength = pEnd - pBegin;
        }

        return s.substr(maxBegin, maxLength);
    }
};
