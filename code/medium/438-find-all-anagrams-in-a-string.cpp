// Title: Find All Anagrams in a String
// Description:
//     Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
//     An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

// Time complexity: O(m+n)
// Space complexity: O(m)
class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        assert(p.length() != 0);

        std::vector<int> charCounts(26, 0);
        std::size_t diffCount = 0;

        // require every char in p to be matched
        for (char c: p) {
            int &charCount = charCounts[c - 'a'];

            if (charCount == 0) ++diffCount;
            charCount -= 1;
            // if (charCount == 0) --diffCount;
        }

        std::vector<int> result;

        for (std::size_t i = 0, j = 0; j != s.length();) {
            // shrink the window if the substring is full
            if (j-i == p.length()) {
                char c = s[i++];
                int &charCount = charCounts[c - 'a'];

                if (charCount == 0) ++diffCount;
                charCount -= 1;
                if (charCount == 0) --diffCount;
            }

            // extend the window
            if (true) {
                char c = s[j++];
                int &charCount = charCounts[c - 'a'];

                if (charCount == 0) ++diffCount;
                charCount += 1;
                if (charCount == 0) --diffCount;
            }

            // an anagram is found
            if (diffCount == 0) result.push_back(i);
        }

        return result;
    }
};
