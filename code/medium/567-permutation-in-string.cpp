// Title: Permutation in String
// Description:
//     Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//     In other words, return true if one of s1's permutations is the substring of s2.
// Link: https://leetcode.com/problems/permutation-in-string/

// Time complexity: O(n1+n2)
// Space complexity: O(1)
class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        assert(s2.length() != 0);

        std::vector<int> charCounts(26, 0);
        std::size_t diffCount = 0;

        // require every char in s1 to be matched
        for (char c: s1) {
            int &charCount = charCounts[c - 'a'];

            if (charCount == 0) ++diffCount;
            charCount -= 1;
            // if (charCount == 0) --diffCount;
        }

        for (std::size_t i = 0, j = 0; j != s2.length();) {
            // shrink the window if the substring is full
            if (j-i == s1.length()) {
                char c = s2[i++];
                int &charCount = charCounts[c - 'a'];

                if (charCount == 0) ++diffCount;
                charCount -= 1;
                if (charCount == 0) --diffCount;
            }

            // extend the window
            if (true) {
                char c = s2[j++];
                int &charCount = charCounts[c - 'a'];

                if (charCount == 0) ++diffCount;
                charCount += 1;
                if (charCount == 0) --diffCount;
            }

            // a permutation of s1 is found
            if (diffCount == 0) return true;
        }

        // not found
        return false;
    }
};
