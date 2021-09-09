// Title: Shifting Letters
// Description:
//     You are given a string s of lowercase English letters and an integer array shifts of the same length.
//     Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').
//     For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
//     Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.
//     Return the final string after all such shifts to s are applied.
// Link: https://leetcode.com/problems/shifting-letters/

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        /* naive solution will be rejected by TLE! */
        
        // we need to accumulate the shifts on the same letter and then perform the shift at once
        int accumulatedShift = 0;
        for (int i = shifts.size() - 1; i >= 0; i--) {
            accumulatedShift = (accumulatedShift + shifts[i]) % 26;
            s[i] = (s[i] - 'a' + accumulatedShift) % 26 + 'a';
        }
        
        return s;
    }
};
