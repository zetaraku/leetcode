// Title: Reverse Words in a String III
// Description:
//     Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
// Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    string reverseWords(string s) {
        // indexes to mark the begin and the end of a substring
        int i = 0, j = 0;
        
        while (true) {
            // find the begin of a substring
            while (i != s.length() && s[i] == ' ') ++i;
            
            // stop if there's no more words
            if (i == s.length()) break;

            // find the end of the substring
            j = i; while (j != s.length() && s[j] != ' ') ++j;
            
            // reverse the substring
            reverseSubString(s, i, j);
            
            // continue to search for the next word
            i = j;
        }
        
        return s;
    }
    
    void reverseSubString(string& s, int begin, int end) {
        // swap each pair from both sides
        for (int i = begin, j = end - 1; i < j; ++i, --j) {
            std::swap(s[i], s[j]);
        }
    }
};
