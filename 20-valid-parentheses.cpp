// Title: Valid Parentheses
// Description:
//     Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//     An input string is valid if:
//         Open brackets must be closed by the same type of brackets.
//         Open brackets must be closed in the correct order.
// Link: https://leetcode.com/problems/valid-parentheses/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool isValid(string s) {
        // use a dummy head so we don't need to check if the stack is empty :D!
        std::stack<char> parens({ '\0' });
        
        // process each paren
        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                // put the opening paren into the stack
                parens.push(c);
            } else /* if (c == ')' || c == '}' || c == ']') */ {
                // the closing paren should match the previous opening paren 
                if (c == ')') {
                    if (parens.top() != '(') return false;
                } else if (c == '}') {
                    if (parens.top() != '{') return false;
                } else if (c == ']') {
                    if (parens.top() != '[') return false;
                }
                
                // remove the matched opening paren
                parens.pop();
            }
        }
        
        // check if there is no remaining parens (only contains the dummy head)
        return parens.top() == '\0';
    }
};
