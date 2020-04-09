// Title: Backspace String Compare
// Description:
//     Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
// Link: https://leetcode.com/problems/backspace-string-compare/

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        // TODO: add aoms explaination on your solution
        
        for (auto itS = S.rbegin(), itT = T.rbegin(); true; itS++, itT++) {
            executeDeletion(itS, S.rend()), executeDeletion(itT, T.rend());
            if (itS == S.rend() && itT == T.rend())
                return true;
            if (itS == S.rend() || itT == T.rend())
                return false;
            if (*itS != *itT)
                return false;
        }
    }
    
    void executeDeletion(string::reverse_iterator &iter, string::reverse_iterator const &end) {
        int del = 0;
        for (auto &it = iter; it != end; it++) {
            if (*it == '#')
                del++;
            else if (del != 0)
                del--;
            else
                return;
        }
    }
};
