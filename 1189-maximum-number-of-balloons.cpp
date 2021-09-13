// Title: Maximum Number of Balloons
// Description:
//     Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
//     You can use each character in text at most once. Return the maximum number of instances that can be formed.
// Link: https://leetcode.com/problems/maximum-number-of-balloons/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        std::string pattern = "balloon";
        
        // store all letters in text into source
        std::unordered_map<char,int> source; {
            for (char c: text) ++source[c];
        }
        // store all letters in pattern into target
        std::unordered_map<char,int> target; {
            for (char c: pattern) ++target[c];
        }
        
        // apply max constraint for each letter in target
        int result = INT_MAX;
        for (auto [c, count]: target) {
            int maxVal = source[c] / count;
            result = std::min(maxVal, result);
        }
        
        return result;
    }
};
