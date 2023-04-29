// Title: Longest Substring Without Repeating Characters
// Description:
//     Given a string s, find the length of the longest substring without repeating characters.
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> currentChars;
        std::size_t beginIndex = 0;
        std::size_t maxLength = 0;
        
        for (char c: s) {
            if (currentChars.count(c) == 0) {
                // insert the char
                currentChars.insert(c);

                // update the max length
                maxLength = std::max(maxLength, currentChars.size());
            } else {
                // keep removing chars from the start until the repeating char is removed
                while (true) {
                    char charToRemove = s[beginIndex++];
                    currentChars.erase(charToRemove);
                    if (charToRemove == c) break;
                }

                // insert the char
                currentChars.insert(c);
            }
        }
        
        return maxLength;
    }
};
