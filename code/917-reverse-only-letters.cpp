// Title: Reverse Only Letters
// Description:
//     Given a string s, reverse the string according to the following rules:
//     All the characters that are not English letters remain in the same position.
//     All the English letters (lowercase or uppercase) should be reversed.
//     Return s after reversing it.
// Link: https://leetcode.com/problems/reverse-only-letters/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        // copy the original string to modify on
        std::string result = s;
        
        // read the original string backward
        std::reverse_iterator it = s.rbegin();
        
        for (char &c: result) {
            // leave the non-letter alone
            if (!std::isalpha(c)) continue;
            
            // skip any non-letters when reading backward
            while (!std::isalpha(*it)) ++it;
            // replace the letter with the reversed one
            c = *it;
            // advance the reversed iterator
            ++it;
        }
        
        return result;
    }
};
