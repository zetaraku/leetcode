// Title: Minimum Window Substring
// Description:
//     Given two strings s and t of lengths m and n respectively,
//     return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
//     If there is no such substring, return the empty string "".
//     The testcases will be generated such that the answer is unique.
// Link: https://leetcode.com/problems/minimum-window-substring/

// Time complexity: O(m+n)
// Space complexity: O(m)
class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        assert(t.length() != 0);

        std::unordered_map<char, int> charCounts;
        std::size_t diffCount = 0;

        // require every char in t to be matched
        for (char c: t) {
            int &charCount = charCounts[c];

            if (charCount == 0) ++diffCount;
            charCount -= 1;
        }
        
        std::size_t minIndex = 0, minLength = SIZE_MAX;

        for (std::size_t i = 0, j = 0; true;) {
            // extend the window to include every char in t
            while (j != s.length() && diffCount != 0) {
                char c = s[j++];
                int &charCount = charCounts[c];

                charCount += 1;
                if (charCount == 0) --diffCount;
            }

            // no more window substring can include every char in t
            if (diffCount != 0) break;
            
            // shrink the window to exclude a single char in t
            while (i != j && diffCount == 0) {
                char c = s[i++];
                int &charCount = charCounts[c];

                if (charCount == 0) ++diffCount;
                charCount -= 1;
            }

            // an shorter window substring is found just before excluding the last char
            if (j-(i-1) < minLength) minIndex = (i-1), minLength = j-(i-1);
        }

        return minLength != SIZE_MAX ? s.substr(minIndex, minLength) : "";
    }
};
