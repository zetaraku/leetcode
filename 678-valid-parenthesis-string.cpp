// Title: Valid Parenthesis String
// Description:
//      Given a string containing only three types of characters: '(', ')' and '*',
//      write a function to check whether this string is valid.
//      We define the validity of a string by these rules:
//          1. Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//          2. Any right parenthesis ')' must have a corresponding left parenthesis '('.
//          3. Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//          4. '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
//          5. An empty string is also valid.
// Link: https://leetcode.com/problems/valid-parenthesis-string/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool checkValidString(string s) {
        // we maintain a range of possible depths of parenthesis
        int high = 0, low = 0;
        
        for (char c: s) {
            if (c == '*') {
                // '*' as a wildcard, extends the possibility of both high and low by 1
                high++, low--;
            } else if (c == '(') {
                // '(' increases the depth, raising the range of possibility up by 1
                high++, low++;
            } else if (c == ')') {
                // ')' decreases the depth, lowering the range of possibility down by 1
                high--, low--;
            }
            
            if (low < 0) {
                // the depth of parenthesis should be at least 0
                low = 0;
            }
            if (high < 0) {
                // the range of possibility became empty, the string is impossible to be valid
                return false;
            }
        }
        
        // finally, check if the depth can be reduced to 0 (full matched)
        return low == 0;
    }
};
