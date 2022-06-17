// Title: Perform String Shifts
// Description:
//     You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:
//         direction can be 0 (for left shift) or 1 (for right shift). 
//         amount is the amount by which string s is to be shifted.
//         A left shift by 1 means remove the first character of s and append it to the end.
//         Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
//     Return the final string after all operations.
// Link: https://leetcode.com/problems/perform-string-shifts/

// Time complexity: O(m+n)
// Space complexity: O(n)
// Variables:
//     n = length of s
//     m = number of entries in shift
class Solution {
public:
    string stringShift(string s, vector<vector<int>> &shift) {
        int offsetToSplit = 0;
        
        // add up the total offset we need to perform
        for (vector<int> &command: shift) {
            int direction = (command.at(0) == 0 ? -1 : +1);
            int amount = command.at(1);
            
            // offset direction is opposite to shift direction
            offsetToSplit -= direction * amount;
        }
        
        // the divisor must be signed to divide correctly!
        int n = (int) s.size();
        // proform a real modulus of n
        offsetToSplit = (offsetToSplit % n + n) % n;
        
        // return the shifted string
        return s.substr(offsetToSplit, string::npos) + s.substr(0, offsetToSplit);
    }
};
