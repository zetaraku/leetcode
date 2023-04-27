// Title: Palindromic Substrings
// Description:
//     Given a string s, return the number of palindromic substrings in it.
//     A string is a palindrome when it reads the same backward as forward.
//     A substring is a contiguous sequence of characters within the string.
// Link: https://leetcode.com/problems/palindromic-substrings/

// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    int countSubstrings(std::string s) {
        const std::size_t N = s.size();

        std::size_t count = 0;
        
        for (std::size_t coreBegin = 0, coreEnd; coreEnd = coreBegin + 1, coreBegin != N; coreBegin = coreEnd) {
            // expend the core
            while (coreEnd != N && s[coreEnd] == s[coreBegin]) ++coreEnd;

            // set the palindrome to the core
            std::size_t pBegin = coreBegin, pEnd = coreEnd;

            // expend the palindrome
            while (pBegin != 0 && pEnd != N && s[pBegin-1] == s[pEnd]) --pBegin, ++pEnd;

            std::size_t coreLength = coreEnd - coreBegin;
            std::size_t pLength = pEnd - pBegin;

            // count the palindromic substrings
            count += coreLength * (coreLength + 1) / 2 + (pLength - coreLength) / 2;
        }

        return count;
    }
};
