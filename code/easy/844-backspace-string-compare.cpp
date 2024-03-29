// Title: Backspace String Compare
// Description:
//     Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
//     Follow up: Can you solve it in O(N) time and O(1) space?

// Link: https://leetcode.com/problems/backspace-string-compare/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {
        // we compare backward so that each backspace can immediately cancel out one next character
        for (auto ritS = s.rbegin(), ritT = t.rbegin(); true; ++ritS, ++ritT) {
            // first we cancel out all characters with backspaces at the ends of both strings
            skipCharsFromBack(ritS, s.rend());
            skipCharsFromBack(ritT, t.rend());
            
            // two strings are equal if both strings are full matched
            if (ritS == s.rend() && ritT == t.rend()) return true;
            
            // two strings are not equal if only one string is full matched but the other is not
            if (ritS == s.rend() || ritT == t.rend()) return false;
            
            // two strings are not equal if they mismatch on a character
            if (*ritS != *ritT) return false;
        }
    }
    
    void skipCharsFromBack(string::reverse_iterator &rit, string::reverse_iterator rend) {
        std::size_t numOfCharsToDelete = 0;
        
        while (rit != rend) {
            if (*rit == '#') {
                ++numOfCharsToDelete, ++rit;
            } else if (numOfCharsToDelete != 0) {
                --numOfCharsToDelete, ++rit;
            } else {
                break;
            }
        }
    }
};
