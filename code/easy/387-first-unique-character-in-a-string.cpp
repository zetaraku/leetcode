// Title: First Unique Character in a String
// Description:
//     Given a string s, find the first non-repeating character in it and return its index.
//     If it does not exist, return -1.
// Link: https://leetcode.com/problems/first-unique-character-in-a-string/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int firstUniqChar(std::string s) {
        std::vector<int> counts(26, 0);
        
        // count the chars
        for (char c: s) counts[c - 'a'] += 1;
        
        // find the first unique char
        auto it = std::find_if(s.begin(), s.end(), [&](char c) {
            return counts[c - 'a'] == 1;
        });
        
        return it != s.end() ? it - s.begin() : -1;
    }
};
