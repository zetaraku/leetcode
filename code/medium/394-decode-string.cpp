// Title: Decode String
// Description:
//     Given an encoded string, return its decoded string.
//     The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
//     Note that k is guaranteed to be a positive integer.
//     You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.
//     Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.
//     For example, there will not be input like 3a or 2[4].
//     The test cases are generated so that the length of the output will never exceed 10^5.
// Link: https://leetcode.com/problems/decode-string/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    std::string decodeString(std::string s) {
        const std::size_t N = s.length();

        std::stack<std::pair<std::size_t, std::string>> contextStack; {
            // base context
            contextStack.push({ 0xDEADBEEF, "" });
        }

        std::size_t tmpMultiplier = 0;
        for (char c: s) {
            if (std::isdigit(c)) {
                // append a digit to the tmpMultiplier
                tmpMultiplier = tmpMultiplier * 10 + (c - '0');
            } else if (c == '[') {
                // push a new context
                contextStack.push({ tmpMultiplier, "" });

                // reset the tmpMultiplier
                tmpMultiplier = 0;
            } else if (c == ']') {
                // pop out the current context
                auto [k, str] = contextStack.top(); contextStack.pop();

                // append k copies of current string to the previous string
                auto &[prevK, prevStr] = contextStack.top();
                for (std::size_t i = 0; i != k; ++i) prevStr.append(str);
            } else {
                // append a plain char to the current string
                auto &[k, str] = contextStack.top();
                str.push_back(c);
            }
        }

        // return the base string
        auto [dummyK, str] = contextStack.top(); contextStack.pop();
        return str;
    }
};
