// Title: String to Integer (atoi)
// Description:
//     Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
// Link: https://leetcode.com/problems/string-to-integer-atoi/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int myAtoi(std::string s) {
        int sign = +1;
        std::int64_t value = 0;
        
        auto it = s.begin();
        
        // skip any leading spaces
        while (it != s.end() && *it == ' ') ++it;
        
        // read the optional sign
        if (it != s.end()) {
            if (*it == '+') {
                sign = +1, ++it;
            } else if (*it == '-') {
                sign = -1, ++it;
            }
        }
        
        // read the digits
        while (it != s.end() && isdigit(*it)) {
            // append the parsed digit
            value = value * 10 + (*it - '0'), ++it;
            
            // stop reading digits when the value is already too large
            if (value > INT32_MAX) break;
        }
        
        // return the clamped result
        return (int) std::clamp<std::int64_t>(sign * value, INT32_MIN, INT32_MAX);
    }
};
