// Title: Longest Palindrome
// Description:
//     Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
//     Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
// Link: https://leetcode.com/problems/longest-palindrome/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int longestPalindrome(std::string s) {
        std::unordered_map<char, std::size_t> charCounts;

        // count each char
        for (char c: s) ++charCounts[c];

        int result = 0;

        bool hasUnpairedChar = false;
        for (const auto &[key, val]: charCounts) {
            // take only paired chars
            result += val - (val % 2);
            // record if there is any unpaired char
            if (val % 2 != 0) hasUnpairedChar = true;
        }
        // an extra unpaired char can be put in the middle of a palindrome
        if (hasUnpairedChar) result += 1;

        return result;
    }
};
